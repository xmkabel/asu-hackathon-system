#include "globals.h"

void calculateFinalScores(int teamsCount, Team teamsArr[], int evalCount, Evaluation evalArr[]) {
    for (int i = 0; i < teamsCount; i++) {
        float sum = 0;
        int counter = 0;

        for (int j = 0; j < evalCount; j++) {
            if (evalArr[j].TeamID == teamsArr[i].TeamID) {
                sum += evalArr[j].TotalScore;
                counter++;
            }
        }

        if (counter > 0)
            teamsArr[i].FinalScore = sum / counter;
        else
            teamsArr[i].FinalScore = 0;
    }
}
