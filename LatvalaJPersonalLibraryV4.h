#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>

using namespace std;

ifstream fin;

ofstream fout;

char toLower(char letter) {
	if (letter > 96)
		letter -= 32;
	return letter;
}

int randomFrom(int min, int max) {
	srand(time(NULL));
	return rand() % (max - min) + min;
}

int validateInteger(string errorMessage = "\nError. Please enter a valid input.\n") {
	int input = 0;
	cin >> input;

	while (!input || cin.fail()) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

char validateChar(string errorMessage = "\nError. Please enter a valid input.\n") {
	char input = 0;
	cin >> input;

	while (!input || cin.fail()) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

int validateInteger(int min, string errorMessage = "\nError. Please enter a valid input.\n") {
	int input = 0;
	cin >> input;

	while (!input || cin.fail() || input < min) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

int validateInteger(int min, int max, string errorMessage = "\nError. Please enter a valid input.\n") {
	int input = 0;
	cin >> input;

	while (!input || cin.fail() || input < min || input > max) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

char validateChar(char min, char max, string errorMessage = "\nError. Please enter a valid input.\n") {
	char input = 0;
	cin >> input;

	while (!input || cin.fail() || input < min || input > max) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

char validateChar(char min1, char max1, char min2, char max2, string errorMessage = "\nError. Please enter a valid input.\n") {
	char input = 0;
	cin >> input;

	while (!input || cin.fail() || !((input > min1 && input < max1) || (input > min2 && input < max2))) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

float validateFloat(string errorMessage = "\nError. Please enter a valid input.\n") {
	float input = 0;
	cin >> input;

	while (!input || cin.fail()) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

double validateDouble(string errorMessage = "\nError. Please enter a valid input.\n") {
	double input = 0;
	cin >> input;

	while (!input || cin.fail()) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return input;
}

bool validateYorN(string errorMessage = "\nError. Please enter a valid input.\n") {
	char input = 0;
	cin >> input;

	while (!input || cin.fail() || !(tolower(input) == 'y' || tolower(input) == 'n')) {
		cout << errorMessage;
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cin >> input;
	}

	return (toLower(input == 'y'));
}

int endProgram(bool newlines = true) {
	if (newlines) cout << "\n\n";
	cout << "Press enter to exit";
	cin.ignore(100, '\n');
	cin.get();
	return 0;
}

string retline(istream& is) {
	string line;
	getline(is, line);
	return line;
}

string padString(string str, unsigned short int inputSize, char padding, bool beginning = false) {

	string output = str;

	unsigned short int stringSize = output.length();

	if (stringSize < inputSize)
		for (unsigned short int i = 0; i < (inputSize - stringSize); i++)
			if (beginning)
				output.insert(0, 1, padding);
			else
				output.push_back(padding);

	return output;
}