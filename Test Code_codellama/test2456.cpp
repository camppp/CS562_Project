void updateTeamPoints(int fTeam, int sTeam, int winner) {
    if (winner == 0) {
        teams[fTeam].points += 1;
        teams[sTeam].points += 1;
    } else {
        teams[winner].points += 3;
        teams[winner ^ 1].points = 0;
    }
}
