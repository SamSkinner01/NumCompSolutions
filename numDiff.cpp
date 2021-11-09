#include <iostream>
#include <cmath>
using namespace std;

//Function
double func(double x){return x*exp(x);}

//This function shall approximate the derivative of a function.
double prime(double x0, double h, int choice){
    //Firstly for Forward Difference
    if(choice == 1)
        return (func(x0+h)-func(x0))/h;
    //Secondly Three-point Forward Difference
    else if(choice == 2)
        return (-func(x0+2*h)+4*func(x0+h)-3*func(x0))/(2*h);
    //Thirdly Three-point Centered Difference
    else if(choice == 3)
        return (func(x0+h)-func(x0-h))/(2*h);
    //Finally, invalid choice if not 1,2, or 3
    else
        cout << "Invalid choice.\n";

    return -1;  
}

//To calculate the True Absolute Error
double trueAbsError(double obsVal, double trueVal){return abs(trueVal-obsVal);}

int main(){
    
}
