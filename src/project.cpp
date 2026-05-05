#include "globals.h"

void submitProject() {
    int TeamId;
    string ProjectTitle;
    cout << "Enter Team ID: ";
    TeamId = getValidInt();
    cout << "Enter Project Title: ";
    cin.ignore();
    getline(cin, ProjectTitle);
    int index = findTeamIndexById(TeamId);
    if (index == -1) {
        cout << "Team not found!\n";
        return;
    }
    teams[index].ProjectTitle = ProjectTitle;
    cout << "Project Submitted Successfully!\n";
    
}