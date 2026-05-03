#include "globals.h"

// Check if an ID is available
bool CheckID(int id) {
    for (int i = 0; i < teamCount; i++) {
        if (teams[i].TeamID == id)
            return false;
    }
    return true;
}

// Find team index by ID
int findTeamIndexById(int id) {
    for (int i = 0; i < teamCount; i++) {
        if (teams[i].TeamID == id)
            return i;
    }
    return -1;
}

// Register Team
void registerTeam() {
    if (teamCount >= TEAMS_SIZE) {
        cout << "No space for more teams!\n";
        return;
    }

    int id;
    do {
        cout << "Enter Team ID: ";
        cin >> id;

        if (!CheckID(id))
            cout << "ID already exists!\n";

    } while (!CheckID(id));

    teams[teamCount].TeamID = id;

    cout << "Enter Team Name: ";
    getline(cin >> ws, teams[teamCount].TeamName);

    cout << "Enter University Name: ";
    getline(cin >> ws, teams[teamCount].UniversityName);

    cout << "Enter Number of Members: ";
    cin >> teams[teamCount].NumberOfMembers;

    cout << "Enter Project Title: ";
    getline(cin >> ws, teams[teamCount].ProjectTitle);

    teams[teamCount].FinalScore = 0;
    teams[teamCount].Rank = 0;

    teamCount++;

    cout << "Team Registered Successfully!\n";
}

// View Teams
void viewTeams() {
    if (teamCount == 0) {
        cout << "No teams available!\n";
        return;
    }

    for (int i = 0; i < teamCount; i++) {
        cout << "\n--- Team " << i + 1 << " ---\n";
        cout << "ID: " << teams[i].TeamID << endl;
        cout << "Name: " << teams[i].TeamName << endl;
        cout << "University: " << teams[i].UniversityName << endl;
        cout << "Members: " << teams[i].NumberOfMembers << endl;
        cout << "Project: " << teams[i].ProjectTitle << endl;
    }
}

// Edit Team
void editTeam() {
    int id;
    cout << "Enter Team ID to edit: ";
    cin >> id;

    int index = findTeamIndexById(id);

    if (index == -1) {
        cout << "Team not found!\n";
        return;
    }

    int choice;

    do {
        cout << "\n--- Edit Menu ---\n";
        cout << "1. Edit Team Name\n";
        cout << "2. Edit University Name\n";
        cout << "3. Edit Number of Members\n";
        cout << "4. Edit Project Title\n";
        cout << "5. Exit Editing\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter New Team Name: ";
            getline(cin >> ws, teams[index].TeamName);
            break;

        case 2:
            cout << "Enter New University Name: ";
            getline(cin >> ws, teams[index].UniversityName);
            break;

        case 3:
            cout << "Enter New Number of Members: ";
            cin >> teams[index].NumberOfMembers;
            break;

        case 4:
            cout << "Enter New Project Title: ";
            getline(cin >> ws, teams[index].ProjectTitle);
            break;

        case 5:
            cout << "Finished Editing.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);
}

// Delete Team
void deleteTeam() {
    int id;
    cout << "Enter Team ID to delete: ";
    cin >> id;

    int index = findTeamIndexById(id);

    if (index == -1) {
        cout << "Team not found!\n";
        return;
    }

    char confirm;
    cout << "Are you sure you want to delete? (y/n): ";
    cin >> confirm;

    if (confirm != 'y' && confirm != 'Y') {
        cout << "Deletion cancelled.\n";
        return;
    }

    for (int i = index; i < teamCount - 1; i++) {
        teams[i] = teams[i + 1];
    }

    teamCount--;

    cout << "Team Deleted Successfully!\n";
}
