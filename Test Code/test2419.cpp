// Completing the lcs_length function
int lcs_length(char *a, char *b){
    int m = strlen(a);
    int n = strlen(b);
    int l[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) l[i][j] = 0;
            else if(a[i-1] == b[j-1]) l[i][j] = 1 + l[i-1][j-1];
            else l[i][j] = (l[i-1][j] > l[i][j-1]) ? l[i-1][j] : l[i][j-1];
        }
    }
    return l[m][n];
}

// Implementing the function to find the length of the LCS for two given strings
int find_lcs_length(char *str1, char *str2){
    return lcs_length(str1, str2);
}
