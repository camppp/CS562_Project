void populateOutputTensors(const std::vector<Tensor*>& model_output_tensors, std::vector<Tensor>& output_tensors) {
    for (int i = 0; i < model_output_tensors.size(); i++) {
        output_tensors[i].setDataType(model_output_tensors[i]->getDataType());
    }
}
