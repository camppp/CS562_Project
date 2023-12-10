class pstring {
public:
    static bool checkExtension(const std::string& filename, const std::string& extension) {
        return filename.substr(filename.find_last_of('.') + 1) == extension;
    }
};

class pfile {
public:
    static bool copy(const std::string& source, const std::string& destination) {
        std::ifstream src(source, std::ios::binary);
        std::ofstream dst(destination, std::ios::binary);
        dst << src.rdbuf();
        return dst.good();
    }
};
