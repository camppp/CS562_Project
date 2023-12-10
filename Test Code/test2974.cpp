#include <boost/thread.hpp>

class Singleton {
private:
    static Singleton* instance;
    static boost::once_flag onceFlag;
    size_t uniqueId;

    Singleton() {
        // Private constructor to prevent instantiation
        uniqueId = generateUniqueId();
    }

    static void createInstance() {
        instance = new Singleton();
    }

    static size_t generateUniqueId() {
        // Generate a unique identifier
        return /* your unique identifier generation logic */;
    }

public:
    static Singleton* getInstance() {
        boost::call_once(&Singleton::createInstance, onceFlag);
        return instance;
    }

    size_t getData() {
        boost::call_once(&Singleton::generateUniqueId, onceFlag);
        return uniqueId;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
boost::once_flag Singleton::onceFlag = BOOST_ONCE_INIT;
