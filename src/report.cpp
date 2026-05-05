#include "globals.h"

void displayReport(int teamsCount, Team teamsArr[]) {

	if (teamsCount == 0) return;
	Team winner = teamsArr[0];
	cout << left
		<< "  " << setw(4) << "Rank"
		<< "  " << setw(25) << "Project"
		<< "  " << setw(25) << "Team Name"
		<< "  " << setw(4) << "ID"
		<< "  " << setw(25) << "University"
		<< "  " << setw(4) << "Final Score" << endl;

	cout << "==========================================================================================================\n\n";

	for (int i = 0; i < teamsCount; i++) {
		cout << left
			<< "  " << setw(4) << teamsArr[i].Rank
			<< "  " << setw(25) << teamsArr[i].ProjectTitle
			<< "  " << setw(25) << teamsArr[i].TeamName
			<< "  " << setw(4) << teamsArr[i].TeamID
			<< "  " << setw(25) << teamsArr[i].UniversityName
			<< "  " << setw(4) << teamsArr[i].FinalScore << endl;

	}


	cout << endl << "========================\n";
	cout << "!!! HACKATHON WINNER !!!\n";
	cout << "========================\n\n";

	cout << "Team Name     |\t" << winner.TeamName << endl;
	cout << "Project Title |\t" << winner.ProjectTitle << endl;
	cout << "Final Score   |\t" << winner.FinalScore << "\n\n";
}
