struct SeatInfo {
    int row;
    int column;
    int seatId;
};

SeatInfo getSeatInfo(string boardingPass) {
    SeatInfo info;
    info.row = 0;
    info.column = 0;
    info.seatId = 0;

    for (int i = 0; i < boardingPass.length(); i++) {
        char c = boardingPass[i];
        if (c == 'F') {
            info.row /= 2;
        } else if (c == 'B') {
            info.row = (info.row + 1) / 2;
        } else if (c == 'L') {
            info.column /= 2;
        } else if (c == 'R') {
            info.column = (info.column + 1) / 2;
        }
    }

    info.seatId = (info.row * 8) + info.column;
    return info;
}
