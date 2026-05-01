#include "globals.h"

// Comparator: higher score first, then alphabetical order
bool teamSorter(const Team& a, const Team& b) {
    if (a.FinalScore != b.FinalScore)
        return a.FinalScore > b.FinalScore;

    return a.TeamName < b.TeamName;
}

// Sort teams and assign ranks
void generateRanking(int teamsCount, Team teamsArr[]) {
    sort(teamsArr, teamsArr + teamsCount, teamSorter);

    for (int i = 0; i < teamsCount; i++) {
        teamsArr[i].Rank = i + 1;
    }
}