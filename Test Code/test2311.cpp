#include <iostream>
#include <sstream>

class out_buff : public std::stringbuf {
public:
    out_buff(FILE* file) {
        setp(0, 0);
        setg(0, 0, 0);
        file_ = file;
    }

    ~out_buff() {
        sync();
    }

    int sync() {
        if (pbase() != pptr()) {
            fwrite(pbase(), 1, pptr() - pbase(), file_);
            setp(pbase(), epptr());
        }
        return 0;
    }

private:
    FILE* file_;
};

namespace Catch {
    std::ostream& cout() {
        static std::ostream ret(new out_buff(stdout));
        return ret;
    }

    std::ostream& clog() {
        static std::ostream ret(new out_buff(stderr));
        return ret;
    }
}
