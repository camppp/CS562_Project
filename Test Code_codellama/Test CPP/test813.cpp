c
string finalPosition(string commands) {
    int x = 0, y = 0, i = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int j = 0; j < commands.length(); j++) {
        char c = commands[j];
        if (c == 'R') {
            i = (i + 1) % 4;
        } else if (c == 'L') {
            i = (i + 3) % 4;
        } else {
            x += dx[i];
            y += dy[i];
        }
    }

    return to_string(x) + " " + to_string(y);
}
