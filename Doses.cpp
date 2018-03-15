#include "Patient.h"

using namespace std;

int main() {

	bool again = false;

	do {
		Patient p;
		p.getSex();
		p.getAge();
		p.getWeight();
		p.getHeight();
		p.getCreatinine();
		p.getAUC();

		cout << endl;

		cout << "The patient has a body surface area of " << p.BSA() << " meters squared" << endl;
		cout << "I recommend a dose of " << p.dose() << " mg of carboplatin" << endl << endl;

		string input;
		cout << "Would you like to run another calculation? Type \"1\" to run the program again, or any other key to exit: ";
		getline(cin, input);
		if (input == "1") {
			cout << endl;
			again = true;			
		}
		else{
			again = false;
		}
	} while (again);
	
	cout << endl;
	system("pause");
	return 0;
}

