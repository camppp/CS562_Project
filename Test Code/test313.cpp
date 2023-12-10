#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

string generateHTMLTable(vector<vector<int>> v, set<pair<int, int>> failed_coords) {
    string html = "<table>";
    for (int i = 0; i < v.size(); i++) {
        html += "<tr>";
        for (int j = 0; j < v[i].size(); j++) {
            int value = v[i][j];
            string cell_class = "";
            if (failed_coords.find(make_pair(i, j)) != failed_coords.end()) {
                cell_class = "failed";
            }
            if (value == UNKNOWN) {
                html += "<td class=\"" + cell_class + "\">unknown</td>";
            } else if (value == WHITE) {
                html += "<td class=\"" + cell_class + "\">.</td>";
            } else if (value == BLACK) {
                html += "<td class=\"" + cell_class + "\">#</td>";
            } else {
                html += "<td class=\"" + cell_class + "\">" + to_string(value) + "</td>";
            }
        }
        html += "</tr>";
    }
    html += "</table>";
    return html;
}
