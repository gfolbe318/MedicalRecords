#include "Patient.h"

bool isInt(char input) {
	if (input < 48 || input > 57) {
		return false;
	}
	return true;
}

bool allIntegers(string input) {
	for (unsigned int i = 0; i < input.length(); i++) {
		if (!isInt(input[i])) {
			return false;
		}
	}
	return true;
}

bool validHeightInput(string input) {
	if (input.length() == 3) {
		if (isInt(input[0]) && isInt(input[2]) && input[1] == ' ') {
			return true;
		}
		else {
			return false;
		}
	}
	else if (input.length() == 4) {
		if (isInt(input[0]) && isInt(input[2]) && isInt(input[3]) && input[1] == ' ') {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool isDecimal(string input) {
	int decimalCount = 0;
	for (int i = 0; i < input.length(); i++) {
		if (!isInt(input[i]) && input[i] != '.') {
			return false;
		}
		else if (input[i] == '.') {
			decimalCount++;
			if (decimalCount > 1) {
				return false;
			}
		}
	}
	return true;
}




Patient::Patient()
	:age(0), weight(0), height(0), sex(""), AUC(0.0), creatinine(0.0)  {};

void Patient::getSex() {
	string sex_in;
	bool check = false;
	do {
		cout << "Is the patient male or female? Enter \"M\" or \"m\" for male, or \"F\" for \"f\" for female: ";
		getline(cin, sex_in);
		if (sex_in == "M" || sex_in == "m") {
			sex = "male";
			check = true;
		}
		else if (sex_in == "F" || sex_in == "f") {
			sex = "female";
			check = true;
		}
		else {
			cout << "Invalid input" << endl;
			cin.clear();
		}
	} while (!check);

}

void Patient::getAge() {
	string age_in;
	bool check = false;
	int localAge = 0;

	do {
		bool run = false;
		cout << "Type the age of the patient in years, then press enter: ";
		getline(cin, age_in);
		if (allIntegers(age_in)) {
			age = stoi(age_in);
			check = true;
		}

		else {
			cout << "Invalid input" << endl;
		}
			
	} while (!check);
}

void Patient::getWeight() {
	string weight_in;
	bool check = false;

	do {
		cout << "Type the weight of the patient in pounds, then press enter: ";
		getline(cin, weight_in);
		if (allIntegers(weight_in) || isDecimal(weight_in)) {
			weight = stod(weight_in);
			check = true;
		}

		else {
			cout << "Invalid input" << endl;
		}

	} while (!check);
}

void Patient::getHeight() {
	string height_input;
	bool check = false;

	do {
		cout << "How tall is the patient? Enter in the following format and press enter: feet (space) inches: ";
		getline(cin, height_input);
		if(validHeightInput(height_input)){
			if (height_input.length() == 3) {
				height = 12 * (height_input[0] - 48) + (height_input[2] - 48);
				check = true;
			}
			else if (height_input.length() == 4) {
				if (height_input[2] != '1') {
					cout << "That seems like an unusually high number. Please try again" << endl;
					check = false;
				}
				else {
					height = 12 * (height_input[0] - 48) + 10 + (height_input[3] - 48);
					check = true;
				}
			}
		}
		else {
			cout << "Invalid input" << endl;
		}

	} while (!check);
}

void Patient::getCreatinine() {
	string Cr_input;
	bool check = false;

	do {
		cout << "What is the patient's creatinine levels? Enter in units of mg/dL and press enter: ";
		getline(cin, Cr_input);
		if (allIntegers(Cr_input) || isDecimal(Cr_input)) {
			creatinine = stod(Cr_input);
			check = true;
		}
		else {
			cout << "Invalid input" << endl;
		}
	} while (!check);
}

void Patient::getAUC() {
	string AUC_input;
	bool check = false;

	do {
		cout << "What is the target AUC? Enter in units of mg and press enter: ";
		getline(cin, AUC_input);
		if (allIntegers(AUC_input) || isDecimal(AUC_input)) {
			AUC = stod(AUC_input);
			check = true;
		}
		else {
			cout << "Invalid input" << endl;
		}
	} while (!check);
}

double Patient::BSA() {

	double metricHeight = height * 2.54;
	double metricWeight = weight * 0.453593;

	return sqrt(metricHeight * metricWeight / 3600);
}

double Patient::dose() {
	double localWeight = weight * .453593;

	double GFR = ((140 - age) / (creatinine)) * (localWeight / 72);
		
	double dose = AUC * (GFR + 25);

	if (sex == "female") {
		dose *= 0.85;
	}

	return dose;
}
