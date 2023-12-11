#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> countWords(const string& commentBlock) {
    map<string, int> wordCounts;

    // Split the comment block into individual words
    vector<string> words = split(commentBlock, " ");

    // Iterate over the words and count the occurrences
    for (const string& word : words) {
        // Ignore non-alphabetic characters and case
        string alphaWord = word.substr(0, word.find_first_not_of("abcdefghijklmnopqrstuvwxyz"));
        if (alphaWord.empty()) {
            continue;
        }

        // Increment the count for the word
        wordCounts[alphaWord]++;
    }

    return wordCounts;
}

int main() {
    string commentBlock = "// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n"
                          "// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
                          "// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
                          "// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.";

    map<string, int> wordCounts = countWords(commentBlock);

    for (const auto& wordCount : wordCounts) {
        cout << wordCount.first << ": " << wordCount.second << endl;
    }

    return 0;
}
