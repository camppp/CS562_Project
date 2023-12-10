#include <iostream>
#include <string>
#include <vector>

using namespace std;

string formatContactInfo(const vector<map<string, string>>& contacts) {
    vector<string> formattedContacts;
    for (const auto& contact : contacts) {
        string name = contact.at("name");
        string telephone = contact.at("telephone");
        int index = stoi(contact.at("index"));
        formattedContacts.push_back(
            "Contact information for " + name + ":\n"
            "- Telephone: " + telephone + "\n"
            "- Index: " + to_string(index)
        );
    }
    return formattedContacts;
}

int main() {
    vector<map<string, string>> contacts = {
        {{"name", "Alice"}, {"telephone", "123-456-7890"}, {"index", "1"}},
        {{"name", "Bob"}, {"telephone", "987-654-3210"}, {"index", "2"}}
    };
    vector<string> formattedContacts = formatContactInfo(contacts);
    for (const auto& contact : formattedContacts) {
        cout << contact << endl;
    }
    return 0;
}
