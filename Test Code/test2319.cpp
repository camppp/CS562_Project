#include <iostream>
#include <string>
using namespace std;

const string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int dayOfWeek(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y--;
    }
    int c = y / 100;
    y %= 100;
    int f = d + ((13 * (m + 1)) / 5) + y + (y / 4) + (c / 4) - (2 * c);
    while (f < 0) {
        f += 7;
    }
    return f % 7;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string date1, date2;
        cin >> date1 >> date2;
        int yy1, yy2, m1, m2, d1, d2;
        sscanf(date1.c_str(), "%d-%d-%d", &yy1, &m1, &d1);
        sscanf(date2.c_str(), "%d-%d-%d", &yy2, &m2, &d2);

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((yy1 % 4 == 0 && yy1 % 100 != 0) || yy1 % 400 == 0) {
            daysInMonth[2] = 29;
        }

        int days = 0;
        while (yy1 != yy2 || m1 != m2 || d1 != d2) {
            d1++;
            if (d1 > daysInMonth[m1]) {
                m1++;
                d1 = 1;
                if (m1 > 12) {
                    yy1++;
                    m1 = 1;
                    if ((yy1 % 4 == 0 && yy1 % 100 != 0) || yy1 % 400 == 0) {
                        daysInMonth[2] = 29;
                    } else {
                        daysInMonth[2] = 28;
                    }
                }
            }
            days++;
        }

        int dayIndex = (dayOfWeek(yy1, m1, d1) + days) % 7;
        cout << days[(dayIndex + 1) % 7] << endl;
    }
    return 0;
}
