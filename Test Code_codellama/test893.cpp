#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rearrangeVerses(string input) {
    vector<string> verses;
    string currentVerse;
    bool isPortal = false;

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == '>') {
            verses.push_back(currentVerse);
            currentVerse = "";
        } else if (c == '<') {
            currentVerse = "";
        } else if (c == 'P') {
            isPortal = true;
        } else {
            currentVerse += c;
        }
    }

    if (isPortal) {
        return verses[0];
    } else {
        return "";
    }
}

int main() {
    string input = "> Verse 5\n\
W: Anyway, this cake is great.\n\
E: When I look up there it makes me glad I'm not you.\n\
SW: there is research to be done on the people who are still alive.\n\
< Verse 5\n\
< Verse 4\n\
< Verse 3\n\
<Portal: Still Alive Verse 1\n\
>Last One Verse 6\n\
";

    string output = rearrangeVerses(input);
    cout << output << endl;

    return 0;
}
