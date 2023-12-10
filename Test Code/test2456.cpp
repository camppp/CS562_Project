#include <iostream>
#include <vector>

struct TeamPoints {
    int ID;
    int points;
};

std::vector<TeamPoints> teamPoints; // Assuming this vector is initialized with team IDs and initial points

void updateTeamPoints(int fTeam, int sTeam, int winner) {
    for (int i = 0; i < teamPoints.size(); i++) {
        if (teamPoints[i].ID == fTeam || teamPoints[i].ID == sTeam) {
            if (winner == 0) {
                teamPoints[i].points++; // Increment points for both teams in case of a tie
            } else if (teamPoints[i].ID == winner) {
                teamPoints[i].points += 3; // Increment points for the winning team
            }
        }
    }
}
