#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
//Going to define global variables, such as h and c, all values of x and all values of y
double c = .26, h = .01, x[6] = {.15, .21, .23, .27, .32, .35}, fx[6] = {.1761, .3222, .3617, .4314, .5051, .5441};
int s = 6;
 
double lagrange(double c, double x[], double f[], int size)
{
   double int_value = 0;
   for (int i = 0; i < size; i++){
       double Lagrangian = 1;
       for (int j = 0; j < size; j++){
           if (j != i)
               Lagrangian = Lagrangian * (c - x[j]) / (x[i] - x[j]);
       }
       int_value = int_value + Lagrangian * f[i];
   }
   return int_value;
}
 
//This function shall approximate the derivative of a function.
double prime(double x[], double fx[], int choice){
 
   double x0 = lagrange(c, x, fx, s); // func(c), will need for every form of differentiation
   double x1 = lagrange(c + h, x, fx, s); //func(c+h)
   double x2 = lagrange(c + 2*h, x, fx, s); // func(c+2h)
   double x3 = lagrange(c-h,x,fx,s);// func(c-h)
   // Forward Difference --> Requires 2 points x0 and x0+h
   if(choice == 1){
       return ((x1)-(x0))/h;
   }
   //Three-points Forward Difference --> Requires 3 points x0, x0+h, x0+2h
   else if (choice == 2){
       return ((-x2)+(4*x1)-(3*x0))/(2*h);
   }
   //Three-points Centerd Difference --> 3 points x0-h,x0,x0+h
   else if (choice == 3){
       return ((x1)-(x3))/(2*h);
   }
   else {
       return 0;
   }
   
}
 
//To calculate the True Absolute Error
double trueAbsError(double obsVal, double trueVal){
   return abs(trueVal-obsVal);
}
 
int main(){
  
   cout << endl << setprecision(10) << prime(x,fx,1) << endl;
   cout << setprecision(10) << prime(x, fx, 2) << endl;
   cout << setprecision(10) << prime(x, fx, 3) << endl << endl;
  
}
