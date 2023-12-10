static void apply(dom_t &dom, arith_operation_t op, varname_t x, varname_t y,
                  varname_t z) {
  switch (op) {
    case ArithOperation::ADD:
      dom += lincst_t(var_t(x) + var_t(y) + var_t(z), lincst_t::EQUALITY);
      break;
    case ArithOperation::SUB:
      dom += lincst_t(var_t(x) - var_t(y) - var_t(z), lincst_t::EQUALITY);
      break;
    case ArithOperation::MUL:
      dom += lincst_t(var_t(x) * var_t(y) * var_t(z), lincst_t::EQUALITY);
      break;
    case ArithOperation::DIV:
      dom += lincst_t(var_t(x) / var_t(y) / var_t(z), lincst_t::EQUALITY);
      break;
    default:
      break;
  }
}
