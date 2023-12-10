#include <functional>
#include <iostream>
#include <vector>

struct TensorEngine {
  std::vector<double> data;
  TensorEngine(std::vector<double> data) : data(data) {}
};

struct TensorSpec {
  std::vector<int> shape;
  TensorSpec(std::vector<int> shape) : shape(shape) {}
};

struct ImmediateMap {
  std::function<double(double)> function;
  ImmediateMap(std::function<double(double)> function) : function(function) {}

  TensorEngine eval(TensorEngine tensor, TensorSpec spec) {
    std::vector<double> result;
    for (int i = 0; i < tensor.data.size(); i++) {
      result.push_back(function(tensor.data[i]));
    }
    return TensorEngine(result);
  }
};

int main() {
  // Define a tensor with shape (2, 3)
  std::vector<int> shape = {2, 3};
  std::vector<double> data = {1, 2, 3, 4, 5, 6};
  TensorEngine tensor(data);
  TensorSpec spec(shape);

  // Define a function to apply to each element of the tensor
  std::function<double(double)> function = [](double x) { return x * 2; };

  // Create an ImmediateMap object with the function
  ImmediateMap map(function);

  // Evaluate the mapping operation on the tensor
  TensorEngine result = map.eval(tensor, spec);

  // Print the result
  for (int i = 0; i < result.data.size(); i++) {
    std::cout << result.data[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
