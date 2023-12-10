#include <iostream>
#include <string>

class HF_TitleTable {
public:
    HF_TitleTable(Xml::Element& element) : element_(element) {}
    ~HF_TitleTable() {}

    void Produce_Title(const char* i_title) {
        std::string title = i_title;
        std::string html = "<th>" + title + "</th>";
        element_.AddChild(html);
    }

    void Produce_Title(const char* i_annotations, const char* i_label) {
        // TODO: Implement this function
    }

private:
    Xml::Element& element_;
};
