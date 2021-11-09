#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Function
double f(double x) {return 2 * sin(x) - exp(x) / 4 - 1;}
//Derivative Function
double fprime(double x) {return 2 * cos(x) - exp(x) / 4;}

double newtonMethod(double x0, int choice, double tolerance, int& iter) {
    double error = 99999, x1;
    //If f'(x) = 0, the tangent is 0. Need a new value.
    while (fprime(x0) == 0) {
        cout << "Please enter a different value for x0:";
        cin >> x0;
    }

    while (error > tolerance) {
        iter++;
        //Found root
        if (f(x0) == 0)
            return x0;
        else {
            x1 = x0 - (f(x0) / fprime(x0));
        }
        //absol approx err
        if (choice == 1) {
            error = abs(x0 - x1);
            x0 = x1;
        }
        //relat absol approx error
        else if (choice == 2) {
            error = abs(x0 - x1) / abs(x1);
            x0 = x1;
        }
        //true abs error
        else if (choice == 3) {
            error = abs(f(x1));
            x0 = x1;
        }
        else {
            cout << "Please enter a valid choice:";
            cin >> choice;
        }

    }

    return x0;
}


int main() {
    int cont = 1;

    while (cont == 1) {
        cout << "Please enter an x value:";
        double x;
        cin >> x;

        cout << "\nPlease enter your choice for your error approximation method:\n 1) Absolute Approximate Error\n 2) Relative Approximate Error\n 3) True Absolute Error\n";
        int choice;
        cin >> choice;

        int iterations = 0;
        double tolerance = pow(10, -6);
        double res = newtonMethod(x, choice, tolerance, iterations);

        cout << "Root: " << setprecision(15) << res << endl << "Iterations: " << iterations << endl;
        cout << "\nType 1 to enter another x value:";
        cin >> cont;

    }
    return 0;
}
