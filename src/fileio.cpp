#include "globals.h"

// Load teams data from teams.txt file
void loadTeams(Team teamsArr[], int &teamsCount)
{
    ifstream teams_file("../data/teams.txt");

    if (!teams_file.is_open())
    {
        cout << "Failed to open teams file ... " << endl;
        return;
    }

    while (teams_file >> teamsArr[teamsCount].TeamID >> teamsArr[teamsCount].TeamName >> teamsArr[teamsCount].UniversityName >> teamsArr[teamsCount].NumberOfMembers >> teamsArr[teamsCount].ProjectTitle >> teamsArr[teamsCount].FinalScore >> teamsArr[teamsCount].Rank)
    {
        teamsCount++;
    }
}

// Save all teams data to file
void saveTeams(Team teamsArr[], int teamsCount)
{

    ofstream teams_file;
    teams_file.open("../data/teams.txt", ios::out); // open file for writing

    if (!teams_file.is_open())
    {
        cout << "File not opened\n";
        return; // stop if file failed to open
    }

    // write each team's data to the file
    for (int i = 0; i < teamsCount; i++)
    {
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

void loadJudges(Judge judges[], int &judgesCount)
{
    ifstream judges_file("../data/judges.txt");

    if (!judges_file.is_open())
    {
        cout << "Could not open judges.txt\n";
        return;
    }

    while (
        judges_file >> judges[judgesCount].JudgeID >> judges[judgesCount].JudgeName >> judges[judgesCount].Speciality >> judges[judgesCount].UserName >> judges[judgesCount].Password)
    {
        judgesCount++;
    }

    judges_file.close();
}



void loadEvaluations(Evaluation evaluations[], int &evaluationsCount)
{
    ifstream evaluations_file("../data/evaluations.txt");

    if (!evaluations_file.is_open())
    {
        cout << "Could not open evaluations.txt\n";
        return;
    }

    while (
        evaluations_file >> evaluations[evaluationsCount].EvaluationID >> evaluations[evaluationsCount].TeamID >> evaluations[evaluationsCount].JudgeID >> evaluations[evaluationsCount].InnovationScore >> evaluations[evaluationsCount].TechnicalScore >> evaluations[evaluationsCount].PresentationScore >> evaluations[evaluationsCount].TotalScore)
    {
        evaluationsCount++;
    }

    evaluations_file.close();
}

void saveEvaluations(Evaluation evaluations[], int evaluationsCount)
{
    ofstream evaluations_file("../data/evaluations.txt");

    if (!evaluations_file.is_open())
    {
        cout << "Could not save evaluations.txt\n";
        return;
    }

    for (int i = 0; i < evaluationsCount; i++)
    {
        evaluations_file
            << evaluations[i].EvaluationID << " "
            << evaluations[i].TeamID << " "
            << evaluations[i].JudgeID << " "
            << evaluations[i].InnovationScore << " "
            << evaluations[i].TechnicalScore << " "
            << evaluations[i].PresentationScore << " "
            << evaluations[i].TotalScore << endl;
    }

    evaluations_file.close();
}

// Load admins data from file
void loadAdmins(Admin admins[], int &adminsCount)
{

    ifstream admins_file;
    admins_file.open("../data/admins.txt");

    if (!admins_file)
    {
        cout << "Error opening file\n";
        return;
    }

    while (adminsCount < ADMINS_SIZE && admins_file >> admins[adminsCount].AdminID >> admins[adminsCount].UserName >> admins[adminsCount].Password)
    {
        adminsCount++;
    }

    admins_file.close();
}

