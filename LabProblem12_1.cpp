/*
* File: LabProblem12_1
* Author: Ethan Burch
* 
* Date: 11/16/2023
* Description: counts the number of words and characters
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void countWords(string filename);
void countCharacters(string filename);
void pressEnterToContinue();
int main(void) {
	string datafile;
	cout << "Enter filename: ";
	getline(cin, datafile);
	

	countWords(datafile);
	countCharacters(datafile);
	pressEnterToContinue();
}


void countWords(string filename) {
	ifstream inFile;
	string input;
	string finalInput;
	int words = 0;

	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error\n";
		return;
	}
	while (true) {
		inFile >> input;
		if (inFile.fail()) break;
		finalInput += input + ' ';
	}

	for (int i = 0; i < finalInput.length(); i++) {
		if (finalInput[i] == ' ') {
			words++;
		}
	}
	cout << "\nNumber of Words: " << words;
}

void countCharacters(string filename) {
	ifstream inFile;
	string input;
	string finalInput;
	int characters = 0;

	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error\n";
		return;
	}
	while (true) {
		inFile >> input;
		if (inFile.fail()) break;
		finalInput += input + ' ';
	}

	for (int i = 0; i < finalInput.length(); i++) {
		if (finalInput[i] >= 33 && finalInput[i] <= 63 || finalInput[i] >= 65 && finalInput[i] <= 90 || finalInput[i] >= 97 && finalInput[i] <= 122) {
			characters++;
		}
	}
	cout << "\nNumber of Characters: " << characters;
}

void pressEnterToContinue() {
	cout << "\nPress enter to continue...\n";
	cin.clear();
	while (cin.get() != '\n') continue;
}