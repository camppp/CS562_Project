std::vector<at::Tensor> attn_score_backward(
    const at::Tensor &grad_output,
    const at::Tensor &attn_query,
    const at::Tensor &attn_keys,
    const at::Tensor &bias,
    const at::Tensor &linear_attn) {
  // Compute the gradients of the attention scores with respect to the input tensors
  at::Tensor grad_attn_scores = grad_output * linear_attn;
  at::Tensor grad_attn_query = grad_attn_scores.sum(attn_keys, /*keepdim=*/true);
  at::Tensor grad_attn_keys = grad_attn_scores.sum(attn_query, /*keepdim=*/true);
  at::Tensor grad_bias = grad_attn_scores.sum(/*keepdim=*/true);
  at::Tensor grad_linear_attn = grad_attn_scores * attn_query;

  // Compute the gradients of the input tensors with respect to the output tensor
  at::Tensor grad_attn_query_input = grad_attn_query * attn_keys;
  at::Tensor grad_attn_keys_input = grad_attn_keys * attn_query;
  at::Tensor grad_bias_input = grad_bias * bias;
  at::Tensor grad_linear_attn_input = grad_linear_attn * attn_keys;

  // Return the gradients of the input tensors
  return {grad_attn_query_input, grad_attn_keys_input, grad_bias_input, grad_linear_attn_input};
}
