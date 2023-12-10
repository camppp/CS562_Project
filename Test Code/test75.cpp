#include <stdio.h>
#include <string.h>

int minChangesTo24HourFormat(char* schedule) {
    int n = strlen(schedule);
    int dp[1024][24], inf;
    int i, j;

    memset(dp, 63, sizeof(dp));
    inf = dp[0][0];
    dp[0][6] = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < 24; j++) {
            if(dp[i][j] == inf) {
                // Implement the logic to find the minimum number of changes required to convert the schedule into a valid 24-hour format
                // Your code here
            }
        }
    }

    // Return the minimum number of changes required
    // Your code here
}

int main() {
    int testcase;
    char s[1024];
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%s", s);
        int changes = minChangesTo24HourFormat(s);
        printf("%d\n", changes);
    }
    return 0;
}
