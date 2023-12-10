#include <iostream>

using Size = size_t;

class Reader {
public:
    Size read(void* buffer, Size length) {
        // Read the specified number of bytes from the file stream
        stream.read(buffer, length);

        // Return the number of bytes read
        return length;
    }

private:
    FileInputStream stream;
};

GLAY_NS_END()
