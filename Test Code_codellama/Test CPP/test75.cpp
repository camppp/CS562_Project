int minChangesTo24HourFormat(char* schedule) {
    int hours = schedule[0] - '0';
    int minutes = schedule[2] - '0';
    if (hours >= 24 || minutes >= 60) {
        return -1;
    }
    if (hours < 10) {
        hours = hours + 10;
    }
    if (minutes < 10) {
        minutes = minutes + 10;
    }
    return hours * 100 + minutes;
}
