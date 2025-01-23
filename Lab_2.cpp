//we need to solve the polynomial using the horner's rule 


#include<iostream>
#include<vector>
using namespace std;

//function to evaluate a polynomial using horner's rule
double poly(const vector<double>&coefficients,double x){
    double result=0;
    for(int i=coefficients.size()-1;i>=0;--i){
        result=result*x+coefficients[i];
    }
    return result;
}


//function to calculate exponentitation usign iterative method 
double exponentiation(double base, int exponent) {
    double result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If the exponent is odd
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int main(){
    vector<double> coefficients={2,-6,2,-1};
    double x=3;
    double polynomial=poly(coefficients,x);
    cout<<"value of polynomial"<<polynomial<<endl;
    return 0;
}
