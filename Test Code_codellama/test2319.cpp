#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string daysOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string startDate, endDate;
        cin >> startDate >> endDate;
        int startYear = stoi(startDate.substr(0, 4));
        int startMonth = stoi(startDate.substr(5, 2));
        int startDay = stoi(startDate.substr(8, 2));
        int endYear = stoi(endDate.substr(0, 4));
        int endMonth = stoi(endDate.substr(5, 2));
        int endDay = stoi(endDate.substr(8, 2));

        int daysBetween = 0;
        for (int year = startYear; year <= endYear; year++) {
            if (year == startYear) {
                daysBetween += (endMonth - startMonth) * 30;
                daysBetween += (endDay - startDay);
            } else if (year == endYear) {
                daysBetween += (12 - startMonth) * 30;
                daysBetween += (endDay - 1);
            } else {
                daysBetween += 365;
            }
        }

        int dayOfWeek = (daysBetween + 1) % 7;
        cout << daysOfWeek[dayOfWeek] << endl;
    }
    return 0;
}
