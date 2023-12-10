static void apply(dom_t &dom, arith_operation_t op, varname_t x, varname_t y,
                  varname_t z) {
  switch (op) {
    case ADDITION: {
      linexp_t x_expr = linexp_t(var_t(y)) + linexp_t(var_t(z)) - var_t(x);
      dom += lincst_t(x_expr, lincst_t::EQUALITY);
      break;
    }
    case SUBTRACTION: {
      linexp_t x_expr = linexp_t(var_t(y)) - linexp_t(var_t(z)) - var_t(x);
      dom += lincst_t(x_expr, lincst_t::EQUALITY);
      break;
    }
    case MULTIPLICATION: {
      linexp_t x_expr = linexp_t(var_t(y)) * linexp_t(var_t(z)) - var_t(x);
      dom += lincst_t(x_expr, lincst_t::EQUALITY);
      break;
    }
    case DIVISION: {
      // Division is not directly supported in linear expressions
      // and may require additional handling based on the domain implementation.
      // For simplicity, we'll assume that division is not directly supported.
      // You may need to handle division differently based on the actual domain implementation.
      break;
    }
    default: {
      // Handle unsupported arithmetic operations
      // This could include bitwise operations, modulus, etc.
      // For simplicity, we'll assume that only basic arithmetic operations are supported.
      break;
    }
  }
}
