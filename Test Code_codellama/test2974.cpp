#include <boost/call_once.hpp>
#include <boost/thread/once.hpp>

class Singleton {
public:
    static Singleton& getInstance() {
        static boost::once_flag flag;
        boost::call_once(flag, [] {
            instance = new Singleton();
        });
        return *instance;
    }

    int getData() {
        static boost::once_flag flag;
        boost::call_once(flag, [] {
            data = generateUniqueId();
        });
        return data;
    }

private:
    static Singleton* instance;
    static int data;

    Singleton() {}

    int generateUniqueId() {
        // Generate a unique identifier
        return 12345;
    }
};

Singleton* Singleton::instance = nullptr;
int Singleton::data = 0;
