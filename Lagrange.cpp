#include <iostream>
using namespace std;
 
double lagrange(double c, double x[], double f[], int size){
   double int_value=0;
  
   for(int i=0; i < size;i++){
       double Lagrangian=1;
       for(int j=0; j <size; j++){
           if(j != i)
               Lagrangian=Lagrangian*(c-x[j])/(x[i]-x[j]);
       }
      
       int_value=int_value+Lagrangian*f[i];
   }
   return int_value;
}
 
int main() {
   double c=.6;
   double x[3] = {.3,.5,.7};
   double f[3] = { .404958, .824361, 1.40963};
   int size = 3;
   cout << "First 3 points: "<< lagrange(c, x, f, size) << endl;
  
   double x1[4] = {.3,.5,.7, .9};
   double f1[4] = { .404958, .824361, 1.40963, 2.21364};
   size =4;
   cout << "First 4 points: "<< lagrange(c, x1, f1, size) << endl;
  
   double x2[4] = {.5,.7,.9,1.1};
   double f2[4] = {.824361, 1.40963, 2.21364,3.30458};
   size =4;
   cout << "Last 4 points: "<< lagrange(c, x2, f2, size) << endl;
  
   double x3[5] = {.3,.5,.7, .9,1.1};
   double f3[5] = { .404958, .824361, 1.40963, 2.21364, 3.30458};
   size =5;
   cout << "All points: "<< lagrange(c, x3, f3, size) << endl << endl;
}
