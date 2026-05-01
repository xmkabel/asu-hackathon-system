#include "globals.h"

// Save all teams data to file
void saveTeams(Team teamsArr[], int teamsCount) {

    ofstream teams_file;
    teams_file.open("../data/teams.txt", ios::out); // open file for writing

    if (!teams_file.is_open()) {
        cout << "File not opened\n";
        return; // stop if file failed to open
    }

    // write each team's data to the file
    for (int i = 0; i < teamsCount; i++) {
        teams_file
            << teamsArr[i].TeamID << " "
            << teamsArr[i].TeamName << " "
            << teamsArr[i].UniversityName << " "
            << teamsArr[i].NumberOfMembers << " "
            << teamsArr[i].ProjectTitle << " "
            << teamsArr[i].FinalScore << " "
            << teamsArr[i].Rank << endl;
    }

    teams_file.close(); // close file after writing
    cout << "Teams data saved successfully\n";
}


// Load admins data from file 
void LoadAdmins(Admin admins[], int &usercount)
{
    usercount = 0;
    ifstream infile;
    infile.open("../data/admins.txt");

    if (!infile)
    {
        cout << "Error opening file\n";
        return;
    }

    while (usercount < ADMINS_SIZE && infile >> admins[usercount].AdminID >> admins[usercount].UserName >> admins[usercount].Password)
    {
        usercount++;
    }

    infile.close();

}
