// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

// Constants for array sizes
#define TEAMS_SIZE 10
#define ADMINS_SIZE 2
#define JUDGES_SIZE 5
#define EVALUATIONS_SIZE 50

// Structs
struct Admin
{
    int AdminID;
    string UserName;
    string Password;
};

struct Team
{
    int TeamID;
    string TeamName;
    string UniversityName;
    int NumberOfMembers;
    string ProjectTitle;
    float FinalScore;
    int Rank;
};

struct Judge
{
    int JudgeID;
    string JudgeName;
    string Speciality;
    string UserName;
    string Password;
};

struct Evaluation
{
    int EvaluationID;
    int TeamID;
    int JudgeID;
    float InnovationScore;
    float TechnicalScore;
    float PresentationScore;
    float TotalScore;
};

// Global Variables (defined once in main.cpp)

extern Admin admins[ADMINS_SIZE];
extern int adminsCount;
extern bool isAdminLoggedIn;

extern Team teams[TEAMS_SIZE];
extern int teamCount;

extern Admin admins[ADMINS_SIZE];
extern int adminsCount;

extern Judge judges[JUDGES_SIZE];
extern int judgesCount;

extern Evaluation evaluations[EVALUATIONS_SIZE];
extern int evaluationsCount;

// auth.cpp
bool AdminLogin(Admin admins[], int adminscount);

// teams.cpp
int findTeamIndexById(int id);
void registerTeam();
void viewTeams();
void editTeam();
void deleteTeam();

//  project.cpp
void submitProject();

//  fileIO.cpp
void loadTeams(Team teamsArr[], int &teamsCount);
void saveTeams(Team teamsArr[], int teamsCount);
void loadJudges(Judge judges[], int &judgesCount);
void loadEvaluations(Evaluation evaluations[], int &evaluationsCount);
void saveEvaluations(Evaluation evaluations[], int evaluationsCount);
void loadAdmins(Admin admins[], int &adminsCount);

// evaluation.cpp
void addEvaluation();

//  score.cpp
void calculateFinalScores(int teamsCount, Team teamsArr[], int evalCount, Evaluation evalArr[]);

//  ranking.cpp
void generateRanking(int teamsCount, Team teamsArr[]);

//  report.cpp
void displayReport(int teamsCount, Team teamsArr[]);

#endif
