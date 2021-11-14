#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double lagrange(double c, double x[], double f[], int size)
{
    double int_value = 0;

    for (int i = 0; i < size; i++)
    {
        double Lagrangian = 1;
        for (int j = 0; j < size; j++)
        {
            if (j != i)
                Lagrangian = Lagrangian * (c - x[j]) / (x[i] - x[j]);
        }

        int_value = int_value + Lagrangian * f[i];
    }
    return int_value;
}

/*******************
*Global declartions*
*******************/

//Without Lagrange
double x[] = {1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8};
double fx[] = {1.543, 1.669, 1.811, 1.971, 2.151, 2.352, 2.577, 2.828, 3.107};
int size = 9;

//With Lagrange
double x2[] = {1, 1.1, 1.3, 1.4, 1.5, 1.7, 1.8};
double fx2[] = {1.543, 1.669, 1.971, 2.151, 2.352, 2.828, 3.107};
double v1 = lagrange(1.2,x2,fx2,7);
double v2 = lagrange(1.6, x2, fx2, 7);
double x3[] = { 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8 };
double fx3[] = {1.543, 1.669, v1, 1.971, 2.151, 2.352,v2, 2.828, 3.107};


/**********************
 *Function Definitions*
 *********************/


double trapezoidalMethod(double hsmall, double x[], double fx[], int n){ 
    double sum=fx[0]+fx[n-1];
    double two=0;

    for(int i = 1; i < n-1;i++){
        two = two + fx[i];
    }
    two=2*two;
    sum = sum+two;
    return (hsmall*sum/2);
}

double simpsonsMethod(double hsmall, double x[], double fx[], int size){ // Simpsons 1/3 Method
    int n = size-1;
    if(n % 2 == 0){
        double sum = fx[0]+fx[n];
        double four = 0;
        double two = 0;

        // Gets even indexes and sums (Even index 2,4,6 are 4*sum)
        for(int i = 1; i <= ((n/2)-1); i++){
           two = two + fx[2*i];
        }
        two = 2 * two;

        //Gets odd indexes and sums (Odd index 1,3,5 are 2*sum)
        for(int i = 1; i <= (n/2); i++){
            four = four + fx[2*i-1];
        }
        four = 4 * four;

        double totalsum = sum + four + two;

        return (hsmall/3)*totalsum;
    }
    else return -1;

}


int main(){
    cout << "\nWithout Lagrange Interpolation!\n--------------------------------------------";
    cout << "\nTrapezoid Method, h=.1 and n=9 : " << trapezoidalMethod(.1,x,fx,size) << endl;
    cout << "Simpsons Method, h=.1 and n=8 : " << simpsonsMethod(.1,x,fx,size) << endl << endl;

    cout << "\nWith Lagrange Interpolation!\n-----------------------------------------------";
    cout << "\nTrapezoid Method, h=.1 and n=9 : " << trapezoidalMethod(.1, x3, fx3, size) << endl;
    cout << "Simpsons Method, h=.1 and n=8 : " << simpsonsMethod(.1, x3, fx3, size) << endl << endl;
}