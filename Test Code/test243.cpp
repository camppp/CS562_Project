#include <iostream>
#include <fstream>
#include <string>

class TEditMetadata {
private:
    std::string title;
    std::string author;
    std::string date;
    std::string description;

public:
    TEditMetadata() {
        // Constructor implementation
    }

    void LoadMetadata(std::string filePath) {
        // Load metadata from the media file at the given filePath
        // Populate title, author, date, and description fields
    }

    void UpdateTitle(std::string newTitle) {
        title = newTitle;
    }

    void UpdateAuthor(std::string newAuthor) {
        author = newAuthor;
    }

    void UpdateDate(std::string newDate) {
        date = newDate;
    }

    void UpdateDescription(std::string newDescription) {
        description = newDescription;
    }

    void SaveMetadata() {
        // Save the modified metadata back to the media file
        // Update the metadata in the file with the new title, author, date, and description
    }
};

int main() {
    TEditMetadata metadataEditor;
    metadataEditor.LoadMetadata("path_to_media_file");
    metadataEditor.UpdateTitle("New Title");
    metadataEditor.UpdateAuthor("New Author");
    metadataEditor.UpdateDate("New Date");
    metadataEditor.UpdateDescription("New Description");
    metadataEditor.SaveMetadata();
    return 0;
}
