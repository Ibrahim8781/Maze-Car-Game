//Mohammad_Ibraheem_22I-2603, Ibrahim_Ahmed_22I-8781
#pragma once
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<string>
#include"Header.h"
#include"Header2.h"
class Game {
private:
	string pName;
	int score;
	int lvl;
	Map Map;
public:
	Game() {
		pName = "";
		lvl = 0;
		score = 0;
	}
	int Menu() {
		system("Color 1F");
		cout << "\n\n\n\n\n                            ------Welcome to IbbiSquared 2-D Car Game!------" << endl;
		cout << "\n\n                                        Press Any Key to Continue           " << endl;
		char cht;
		cht = _getch();
		system("cls");
		int choice;
		system("Color 1F");
		do{
			cout << "1) Manual\n2) Automatic\n3) Whole Scorelist\n0) Exit\nOption: ";
		cin >> choice;
		system("cls");
		if (choice < 0 || choice>3) {
			cout << "OOPS! You entered the wrong option. Try Again!\n" << endl;
		}
		} while (choice < 0 || choice>3);
		return choice;
	}
	void Manual() {
		srand(time(NULL));
		system("Color 1F");
		cout << "Enter Name: ";
		cin >> pName;
		system("cls");
		cout << "Choose Level: \n";
		cout << "\n1) Easy\n2) Normal\n3) Hard\n\nYour Choice: ";
		cin >> lvl;
		auto time = Map.manGame(lvl);
		cout << "\n\t\t\t\t\tPlayer: " << pName << endl;
		cout << "\t\t\t\t\tLevel: " << lvl << endl;
		cout << "\t\t\t\t\tNo. of Obstacles passed: " << Map.getTotalObs() << endl;
		cout << "\t\t\t\t\tTotal Score: " << Map.getScore() << endl;
		cout << "\n\t\t\t\t\tTime Taken: " << time.count() << " seconds" << endl;
		score = Map.getScore();
		history();
		return;
	}
	void Auto() {
		cout << "hello";
		return;
	}
	void history() {
		ofstream recFile("Record.txt", ios::app);
		if (recFile.is_open()) {
			recFile << pName << " ~ " << score << endl;
			recFile.close();
		}
		else {
			cout << "Error opening file for writing." << endl;
		}
	}
	void showScore() {
		ifstream recFile("Record.txt");
		string ss;
		while (getline(recFile, ss)) {
			cout << ss << endl;
		}
	}
};