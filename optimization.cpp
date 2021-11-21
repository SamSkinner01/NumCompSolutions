#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double goldenRatio = 1.618;

double func(double x){return pow(x,3)-4*x;}
double fprime(double x){return 3*pow(x,2)-4;}
double f2prime(double x){return 6*x;}

double goldenSectionMin(double a, double b, double accuracy, int& iter){
    //Initial Initialization
    double 
        x1 = b - ((b-a)/goldenRatio),
        x2 = a + ((b-a)/goldenRatio),
        y1 = func(x1), 
        y2=func(x2);
        
        while(abs(b-a) >= accuracy){
            iter++;
            //Finds Min
            if(y1 >= y2){
                a=x1;
                x1=x2;
                x2=a+(b-a)/goldenRatio;
                y1=func(x1);
                y2=func(x2);
            }
            else{
                b=x2;
                x2=x1;
                x1=b-(b-a)/goldenRatio;
                y1=func(x1);
                y2=func(x2);
            }
        }

        return (a+b)/2;
    
}

double goldenSectionMax(double a, double b, double accuracy, int &iter)
{
    // Initial Initialization
    double
        x1 = b - ((b - a) / goldenRatio),
        x2 = a + ((b - a) / goldenRatio),
        y1 = func(x1),
        y2 = func(x2);

    while (abs(b - a) >= accuracy)
    {
        iter++;
        // Finds max
        if (y1 <= y2)
        {
            a = x1;
            x1 = x2;
            x2 = a + (b - a) / goldenRatio;
            y1 = func(x1);
            y2 = func(x2);
        }
        else
        {
            b = x2;
            x2 = x1;
            x1 = b - (b - a) / goldenRatio;
            y1 = func(x1);
            y2 = func(x2);
        }
    }

    return (a + b) / 2;
}

double newtonMethod(double xk, double accuracy, double scaling, int &iter){
    double xkp1 = xk - scaling * (fprime(xk) / f2prime(xk));

    while (abs(xkp1 - xk) >= accuracy)
    {
        iter++;
        xk = xkp1;
        xkp1 = xk - scaling * (fprime(xk) / f2prime(xk));
    }

    return xkp1;
}

int main(){

    cout << "\nGolden Section Method\n-----------------------------------------\n";
    int iter=0;
    double xmin = goldenSectionMin(3, -3, .001, iter);
    cout << "Min: " << setprecision(10) << xmin << "\tf(x):" << setprecision(10) << func(xmin) << "\tIterations:" << iter << endl;

    int iter2 = 0;
    double xmax= goldenSectionMax(3, -3, .001, iter2);
    cout << "Max: " << setprecision(10) << xmax << "\tf(x):" << setprecision(10) << func(xmax) << "\tIterations:" << iter2 << endl<< endl;

    cout << "Newton's Method\n-----------------------------------------\n";
    int iter3 = 0;
    double xmin1 = newtonMethod(1,.001, 1,iter3);
    cout << "Min: " << setprecision(10) << xmin1 << "\t\tf(x):" << setprecision(10) << func(xmin1) << "\tIterations:" << iter3 << endl;

    int iter4 = 0;
    double xmax1 = newtonMethod(-1, .001, 1, iter4);
    cout << "Max: " << setprecision(10) << xmax1 << "\tf(x):" << setprecision(10) << func(xmax1) << "\tIterations:" << iter4 << endl << endl;
}
