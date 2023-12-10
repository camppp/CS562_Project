#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> count_license_keywords(const string& license_text) {
    unordered_map<string, int> keyword_counts;
    keyword_counts["software"] = 0;
    keyword_counts["warranties"] = 0;
    keyword_counts["conditions"] = 0;
    keyword_counts["limitations"] = 0;

    string::size_type pos = 0;
    while ((pos = license_text.find("software", pos)) != string::npos) {
        keyword_counts["software"]++;
        pos += 7; // "software" has 7 characters
    }

    pos = 0;
    while ((pos = license_text.find("warranties", pos)) != string::npos) {
        keyword_counts["warranties"]++;
        pos += 9; // "warranties" has 9 characters
    }

    pos = 0;
    while ((pos = license_text.find("conditions", pos)) != string::npos) {
        keyword_counts["conditions"]++;
        pos += 10; // "conditions" has 10 characters
    }

    pos = 0;
    while ((pos = license_text.find("limitations", pos)) != string::npos) {
        keyword_counts["limitations"]++;
        pos += 11; // "limitations" has 11 characters
    }

    return keyword_counts;
}

int main() {
    string license_text = "Unless required by applicable law or agreed to in writing, software\n"
                          "distributed under the License is distributed on an \"AS IS\" BASIS,\n"
                          "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
                          "See the License for the specific language governing permissions and\n"
                          "limitations under the License.";

    unordered_map<string, int> keyword_counts = count_license_keywords(license_text);

    cout << "Keyword counts:" << endl;
    for (const auto& pair : keyword_counts) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
