class FileManager {
private:
    // Database connection
    DatabaseConnection db;

    // Workspace ID
    int workspaceId;

    // Working directory
    std::string workingDir;

public:
    // Initialize the source
    void initializeSource(int workspaceId) {
        this->workspaceId = workspaceId;
        db.connect();
    }

    // Set the working directory
    void setWorkingDir(const std::string& workingDir) {
        this->workingDir = workingDir;
    }

    // Load files from the database
    std::vector<File> loadFiles(const std::string& whereClause) {
        // Query the database for files that match the where clause
        std::vector<File> files;
        db.query("SELECT * FROM files WHERE " + whereClause, [&files](const std::vector<std::string>& row) {
            files.push_back(File(row[0], row[1], row[2]));
        });
        return files;
    }

    // Insert or update a local file
    void insertOrUpdateLocalFile(const std::string& fileId, const std::string& fileName) {
        // Check if the file exists in the working directory
        if (std::filesystem::exists(workingDir + "/" + fileName)) {
            // Update the file in the database
            db.query("UPDATE files SET name = ?, size = ?, modified = ? WHERE id = ?",
                     fileName, std::filesystem::file_size(workingDir + "/" + fileName),
                     std::filesystem::last_write_time(workingDir + "/" + fileName), fileId);
        } else {
            // Insert the file into the database
            db.query("INSERT INTO files (name, size, modified) VALUES (?, ?, ?)",
                     fileName, std::filesystem::file_size(workingDir + "/" + fileName),
                     std::filesystem::last_write_time(workingDir + "/" + fileName));
        }
    }

    // Remove a local file
    void removeLocalFile(const std::string& fileId) {
        // Query the database for the file
        db.query("SELECT * FROM files WHERE id = ?", [&fileId](const std::vector<std::string>& row) {
            // Remove the file from the working directory
            std::filesystem::remove(workingDir + "/" + row[1]);
        });
    }

    // Insert a file into the database
    std::string insertDBFile(const std::string& fileName) {
        // Insert the file into the database
        db.query("INSERT INTO files (name, size, modified) VALUES (?, ?, ?)",
                 fileName, std::filesystem::file_size(workingDir + "/" + fileName),
                 std::filesystem::last_write_time(workingDir + "/" + fileName));

        // Return the file ID
        return db.lastInsertId();
    }

    // Update a file in the database
    void updateDBFile(const File& file) {
        // Update the file in the database
        db.query("UPDATE files SET name = ?, size = ?, modified = ? WHERE id = ?",
                 file.name, file.size, file.modified, file.id);
    }
};
