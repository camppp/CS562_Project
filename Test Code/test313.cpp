#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

enum CellValue { UNKNOWN, WHITE, BLACK };

string generateHTMLTable(vector<vector<int>> v, set<pair<int, int>> failed_coords) {
    stringstream ss;
    ss << "<table>\n";
    for (int i = 0; i < v.size(); i++) {
        ss << "<tr>";
        for (int j = 0; j < v[i].size(); j++) {
            ss << "<td";
            if (failed_coords.find(make_pair(i, j)) != failed_coords.end()) {
                ss << " class=\"failed\"";
            }
            switch (v[i][j]) {
                case UNKNOWN: ss << ">unknown</td>"; break;
                case WHITE:   ss << " class=\"white\">.</td>"; break;
                case BLACK:   ss << " class=\"black\">#</td>"; break;
                default:      ss << " class=\"number\">" << v[i][j] << "</td>"; break;
            }
        }
        ss << "</tr>\n";
    }
    ss << "</table>";
    return ss.str();
}
