#include <iostream>
#include <string>
#include <vector>

class HtmlTree {
public:
    std::string tag;
    std::string content;
    std::vector<HtmlTree> children;

    HtmlTree(const std::string& tag, const std::string& content) : tag(tag), content(content) {}

    std::string generateHtml() {
        std::string html;
        html += "<" + tag + ">";
        html += content;
        for (const auto& child : children) {
            html += child.generateHtml();
        }
        html += "</" + tag + ">";
        return html;
    }
};

int main() {
    HtmlTree huge("div", "top level content",
        {
            HtmlTree("p", "paragraph 1"),
            HtmlTree("p", "paragraph 2"),
            HtmlTree("div", "nested div content",
                {
                    HtmlTree("span", "nested span")
                }
            )
        }
    );

    std::cout << huge.generateHtml() << std::endl;

    return 0;
}
