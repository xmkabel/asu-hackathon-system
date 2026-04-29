#include "globals.h"

void submitProject(int TeamId, string ProjectTitle) {
    int index = findTeamIndexById(TeamId);
    if (index == -1) {
        cout << "Team not found!\\n";
        return;
    }
    teams[index].ProjectTitle = ProjectTitle;
    cout << "Project Submitted Successfully!\\n";
    
}