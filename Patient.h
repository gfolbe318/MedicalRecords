#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Patient {
private:
	string sex;
	int age;
	double weight;
	int height;
	double AUC;
	double creatinine;

public:
	  
	Patient();

	void getAge();

	void getWeight();

	void getHeight();

	void getSex();

	void getAUC();

	void getCreatinine();

	double BSA();

	double dose();

};

#endif
