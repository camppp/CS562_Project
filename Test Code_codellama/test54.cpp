class FileSystem {
public:
    void create_folder(const User& user, const std::string& folderName) {
        // Create a new folder with the given folderName
        std::string folderPath = "/" + folderName;
        std::ofstream folderStream(folderPath);
        if (!folderStream) {
            throw std::runtime_error("Failed to create folder");
        }

        // Assign the newly created folder to the specified user
        user.addFolder(folderPath);
    }
};
