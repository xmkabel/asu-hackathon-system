// main.cpp
#include "globals.h"

// ── Global Variable Definitions ────────────────────────────
// (declared as extern in globals.h, defined exactly once here)
Team teams[TEAMS_SIZE];
int teamCount = 0;

Admin admins[ADMINS_SIZE];
int adminsCount = 0;
bool isAdminLoggedIn = false;

Judge judges[JUDGES_SIZE];
int judgesCount = 0;

Evaluation evaluations[EVALUATIONS_SIZE];
int evaluationsCount = 0;

// ── Menu ───────────────────────────────────────────────────
void menu()
{
    while (true)
    {

        do
        {
            cout << "Please login as an admin to access the system.\n\n";
            isAdminLoggedIn = AdminLogin(admins, adminsCount);
            if (!isAdminLoggedIn)
            {
                cout << "Invalid credentials. Please try again.\n\n";
            }
            else
            {
                cout << "Login successful! Welcome to the Hackathon Management System.\n\n";
            }
        } while (!isAdminLoggedIn);
        int choice;
        choice = getValidInt();
        do
        {
            cout << "\n===== Hackathon Management System =====\n";
            cout << "1.  Register Team\n";
            cout << "2.  View Teams\n";
            cout << "3.  Edit Team\n";
            cout << "4.  Delete Team\n";
            cout << "5.  Submit Project\n";
            cout << "6.  Add Evaluation\n";
            cout << "7.  Calculate Final Scores\n";
            cout << "8.  Generate Ranking\n";
            cout << "9.  Display Final Report\n";
            cout << "10. Logout\n";
            cout << "0.  Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {

            case 1:
                registerTeam();
                break;
            case 2:
                viewTeams();
                break;
            case 3:
                editTeam();
                break;
            case 4:
                deleteTeam();
                break;
            case 5:
                submitProject();
                break;
            case 6:
                addEvaluation();
                break;
            case 7:
                calculateFinalScores(teamCount, teams, evaluationsCount, evaluations);
                cout << "Final scores calculated.\n";
                break;

            case 8:
                generateRanking(teamCount, teams);
                cout << "Ranking generated.\n";
                break;

            case 9:
                displayReport(teamCount, teams);
                break;
            case 10:
                cout << "Admin logged out.\n";
                isAdminLoggedIn = false;
                break;

            case 0:
                saveTeams(teams, teamCount);
                saveEvaluations(evaluations, evaluationsCount);
                cout << "Exiting...\n";
                return; // exit program completely

            default:
                cout << "Invalid choice!\n";
            }
        } while (isAdminLoggedIn);
    }
}

int main()
{
    
    loadTeams(teams, teamCount);
    loadJudges(judges, judgesCount);
    loadEvaluations(evaluations, evaluationsCount);
    loadAdmins(admins, adminsCount);
    menu();

    return 0;
}
