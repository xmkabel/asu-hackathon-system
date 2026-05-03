#include "globals.h"

void addEvaluation() {
    // Check capacity
    if (evaluationsCount >= EVALUATIONS_SIZE) {
        cout << "Error: Evaluations array is full.\n";
        return;
    }

    // Display all judges
    cout << "\n===== Available Judges =====\n";
    if (judgesCount == 0) {
        cout << "No judges registered.\n";
        return;
    }
    for (int i = 0; i < judgesCount; i++) {
        cout << "ID: " << judges[i].JudgeID
             << " | Name: " << judges[i].JudgeName
             << " | Specialty: " << judges[i].Speciality << "\n";
    }

    // Select judge by ID
    int selectedJudgeID;
    cout << "\nEnter Judge ID: ";
    cin >> selectedJudgeID;

    int judgeIndex = -1;
    for (int i = 0; i < judgesCount; i++) {
        if (judges[i].JudgeID == selectedJudgeID) {
            judgeIndex = i;
            break;
        }
    }
    if (judgeIndex == -1) {
        cout << "Error: Judge ID not found.\n";
        return;
    }

    //  Display all teams 
    cout << "\n===== Registered Teams =====\n";
    if (teamCount == 0) {
        cout << "No teams registered.\n";
        return;
    }
    for (int i = 0; i < teamCount; i++) {
        cout << "ID: " << teams[i].TeamID
             << " | Name: " << teams[i].TeamName
             << " | Project: " << teams[i].ProjectTitle << "\n";
    }

    //  Select team by ID 
    int selectedTeamID;
    cout << "\nEnter Team ID: ";
    cin >> selectedTeamID;

    int teamIndex = -1;
    for (int i = 0; i < teamCount; i++) {
        if (teams[i].TeamID == selectedTeamID) {
            teamIndex = i;
            break;
        }
    }
    if (teamIndex == -1) {
        cout << "Error: Team ID not found.\n";
        return;
    }

    //  Check for duplicate evaluation (same judge + team) 
    for (int i = 0; i < evaluationsCount; i++) {
        if (evaluations[i].JudgeID == selectedJudgeID &&
            evaluations[i].TeamID  == selectedTeamID) {
            cout << "Error: This judge has already evaluated this team.\n";
            return;
        }
    }

    //  Enter 3 scores 
    float innovation, technical, presentation;

    cout << "\nEnter Innovation Score     (0-10): ";
    cin >> innovation;
    cout << "Enter Technical Score      (0-10): ";
    cin >> technical;
    cout << "Enter Presentation Score   (0-10): ";
    cin >> presentation;

    // Validate range
    if (innovation    < 0 || innovation    > 10 ||
        technical     < 0 || technical     > 10 ||
        presentation  < 0 || presentation  > 10) {
        cout << "Error: All scores must be between 0 and 10.\n";
        return;
    }

    //  Build and store the Evaluation struct 
    Evaluation e;
    e.EvaluationID      = evaluationsCount + 1;          // auto-increment
    e.JudgeID           = selectedJudgeID;
    e.TeamID            = selectedTeamID;
    e.InnovationScore   = innovation;
    e.TechnicalScore    = technical;
    e.PresentationScore = presentation;
    e.TotalScore        = innovation + technical + presentation; // spec formula

    evaluations[evaluationsCount] = e;
    evaluationsCount++;

    cout << "\n✔ Evaluation added successfully!\n";
    cout << "  Judge  : " << judges[judgeIndex].JudgeName << "\n";
    cout << "  Team   : " << teams[teamIndex].TeamName << "\n";
    cout << "  Total  : " << e.TotalScore << " / 30\n";
}
