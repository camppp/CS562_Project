#include <boost/compute.hpp>

int main() {
    // Set up the initial data and context
    boost::compute::device device = boost::compute::system::default_device();
    boost::compute::context context(device);
    boost::compute::command_queue queue(context, device);

    // Create the input and output arrays
    boost::compute::vector<float> a(10, context);
    boost::compute::vector<float> b(10, context);

    // Initialize the input array
    a[0] = 1.0f;
    a[1] = 2.0f;
    a[2] = 3.0f;
    a[3] = 4.0f;
    a[4] = 5.0f;
    a[5] = 6.0f;
    a[6] = 7.0f;
    a[7] = 8.0f;
    a[8] = 9.0f;
    a[9] = 10.0f;

    // Calculate the partial sum of the input array
    boost::compute::transform(a.begin(), a.end(), b.begin(),
        [](float x) { return x * x; }, queue);

    // Print the result
    std::cout << "Partial sum: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
