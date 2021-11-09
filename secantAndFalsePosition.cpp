#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double tolerance = pow(10, -6);
int iteration = 0;

//thought it would be funny to inform you that my code was not working for about an hour and I couldn't
//figure out why. Little did I know it's because the data type in func was an int and not a double...
double func(double x) { return 2 * sin(x) - exp(x) / 4 - 1; }

double secantMethod(double x0, double x1, int choice, double tolerance, int& iteration) {
	double error = 99999;
	double x2 = 0; //This will be the root that is returned.

	//If |func(x0)| < |func(x1)|, then swap.
	if (abs(func(x0)) < abs(func(x1))) {
		x0 = x0 + x1;
		x1 = x0 - x1;
		x0 = x0 - x1;
	}


	//While the error is larger than the tolerance, run the program.
	while (error > tolerance) {
		iteration++;


		//Set variables as needed using mathematical formula0
		double f0 = func(x0), f1 = func(x1);
		x2 = x1 - (f1 * (x0 - x1)) / (f0 - f1);
		x0 = x1;
		x1 = x2;

		//In the rare occassion the root is found before the error < tolerance, return root.
		if (func(x2) == 0)
			return x2;
		else {
			//Absolute Approximate Error
			if (choice == 1)
				error = abs(x0 - x1);
			//Relative Absolute Approximate Error
			else if (choice == 2)
				error = abs(x0 - x1) / abs(x1);
			//True absolute error
			else
				error = abs(func(x2));
		}
	}


	return x2;
}

double falsePositionMethod(double x0, double x1, int choice, double tolerance, int& iteration) {
	double error = 99999, x2 = 0, x;


	if (func(x0) * func(x1) < 0) {
		x = x1;

		while (error > tolerance) {
			iteration++;

			//Same mathematical formula as above function
			double f0 = func(x0), f1 = func(x1);
			x2 = x1 - (f1 * (x0 - x1)) / (f0 - f1);

			//off chance it equals 0
			if (func(x2) == 0)
				return x2;
			//if less
			else if (func(x0) * func(x2) < 0)
				x1 = x2;
			//if not
			else x0 = x2;

			//Absolute Approx Error
			if (choice == 1) {
				error = abs(x - x2);
				x = x2;
			}
			//Relative Absolute Approx Error
			else if (choice == 2) {
				error = abs(x - x2) / abs(x2);
				x = x2;
			}
			//True Absolute Error
			else error = abs(func(x2));

		}

	}
	else return -1;

	return x2;
}

int menu() {
	cout << "What method would you like to use?\n 1) Secant Method\n 2) False Position Method\n 3) Exit\n";
	int methodChoice;
	cin >> methodChoice;

	while (methodChoice > 3 || methodChoice < 1) {
		cout << "Please enter a valid choice.\n";
		cin >> methodChoice;
	}

	if (methodChoice == 1) {
		cout << "\nPlease enter your choice for your error approximation method:\n 1) Absolute Approximate Error\n 2) Relative Approximate Error\n 3) True Absolute Error\n";
		int errorChoice;
		cin >> errorChoice;
		while (errorChoice > 3 || errorChoice < 1) {
			cout << "Please enter a valid choice.\n";
			cin >> errorChoice;
		}
		cout << "Please enter x0:";
		double x0; 
		cin >> x0;
		cout << "Please enter x1:";
		double x1;
		cin >> x1;
		double result = secantMethod(x0, x1, errorChoice, tolerance, iteration);
		cout << "Root: " << setprecision(15) << result << endl << "Iterations: " << iteration << endl << endl;
		iteration = 0;


	}
	else if (methodChoice == 2) {
		cout << "\nPlease enter your choice for your error approximation method:\n 1) Absolute Approximate Error\n 2) Relative Approximate Error\n 3) True Absolute Error\n";
		int errorChoice;
		cin >> errorChoice;
		while (errorChoice > 3 || errorChoice < 1) {
			cout << "Please enter a valid choice.\n";
			cin >> errorChoice;
		}
		cout << "Please enter x0:";
		double x0;
		cin >> x0;
		cout << "Please enter x1:";
		double x1;
		cin >> x1;
		while (func(x0) * func(x1) >= 0) {
			cout << "Please enter valid brackets.\n";
			cout << "Please enter x0:";
			cin >> x0;
			cout << "Please enter x1:";
			cin >> x1;
		}
		double result = falsePositionMethod(x0, x1, errorChoice, tolerance, iteration);
		cout << "Root: " << setprecision(15) << result << endl << "Iterations: " << iteration << endl << endl;
		iteration = 0;
	}
	else if (methodChoice == 3) {
		cout << "\nQuitting...\n\n";
		return -1;
	}
}


int main() {
	while (menu() != -1) {}
}
