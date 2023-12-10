#include <iostream>

namespace fastrtps {
    namespace rtps {
        class ParameterCount_t {
        private:
            int pid; // PID (Parameter ID) of the parameter
            int length; // Length associated with the parameter

        public:
            // Default constructor
            ParameterCount_t() : pid(0), length(0) {}

            /**
             * Constructor using a parameter PID and the parameter length
             * @param pid Pid of the parameter
             * @param in_length Its associated length
             */
            ParameterCount_t(int pid, int in_length) : pid(pid), length(in_length) {}

            // Method to get the PID of the parameter
            int getPID() const {
                return pid;
            }

            // Method to get the length associated with the parameter
            int getLength() const {
                return length;
            }
        };
    }
}

int main() {
    // Create an instance of ParameterCount_t
    fastrtps::rtps::ParameterCount_t paramCount(1, 10);

    // Access and print the PID and length of the parameter
    std::cout << "PID: " << paramCount.getPID() << ", Length: " << paramCount.getLength() << std::endl;

    return 0;
}
