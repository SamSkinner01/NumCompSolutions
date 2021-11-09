//Project 1: Bisection Method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Function given in assignment
double func(double x) { return 2 * sin(x) + exp(x) / 4 - 1; }

double bisection(double x1, double x2, double tolerance, int choice, int& iteration){
    //Defined variables that will be needed
    double error = 999999;
    double x3 = 0, x4;

    //this means (-)(+) = (-), so these are bracketing f(x)=0
    if (func(x1) * func(x2) < 0){
        //while error is not at an acceptable precision
        while (!(error < tolerance)){
            iteration++;
            //find mid point
            x3 = (x1 + x2) / 2;
            //in the off chance it equals 0 that is the root
            if (func(x3) == 0)
                return x3;
            else{
                if (func(x1) * func(x3) < 0){
                    x2 = x3;
                    x4 = x1;
                }
                else{
                    x1 = x3;
                    x4 = x2;
                }

                if (choice == 1)
                    error = abs(x4 - x3);
                else if (choice == 2)
                    error = abs(x4 - x3) / abs(x3);
                else
                    error = abs(func(x3));
                //extra possibly useful info
                //cout << "error: " << error << " iteration: " << iteration << " x3: " << x3 << endl;
            }
        }
    }
    else return -1;
    return x3;
}

void enterInfo(double& x, double& y, int& choice) {
    cout << "Please enter a bracket value: ";
    cin >> x;
    cout << "Please enter another bracket value: ";
    cin >> y;
    while (func(x) * func(y) >= 0) {
        cout << "Invalid Brackets.\n";
        cout << "Please enter a bracket value: ";
        cin >> x;
        cout << "Please enter another bracket value: ";
        cin >> y;
    }
    cout << endl;
    cout << "Please choose which error you would like to use.\n 1)Absolute Approximate Error\n 2)Relative Absolute Approximate Error\n 3)True Absolute Error\n";
    while (choice < 1 || choice > 3) {
        cin >> choice;
        cout << endl;
    }
}

int main()
{
    double x, y, tolerance = pow(10, -6);
    int choice = 0, iterations = 0;
    int cont = 1;

    while (cont == 1) {
        enterInfo(x, y, choice);
        double res = bisection(x, y, tolerance, choice, iterations);
        if (res == -1) {}
        else {
            cout << setprecision(10) << res << " " << iterations << endl << endl;
        }
        iterations = 0; choice = 0;

        cout << "Would you like to run again(Type '1' for yes)?\n";
        cin >> cont;
        cout << "\n";
    }
}
