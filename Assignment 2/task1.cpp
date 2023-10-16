/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 1 of Ass 2
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
double degree;              // Declare global value (the degrees which the user will enter)to use it in more than one function

double get_degree() {
    cout << "please Enter the angle in degrees: ";     // Get the angle in degrees from the user
    cin >> degree;
    cout << "You Entered: " << degree << " degrees\n";
    return degree;
}

long double deg_rad() {
    long double rad;                                       // Function to Convert the angle which the user entered in degrees to radian
    rad = get_degree() * 3.141592654 / 180;
    cout << "The angle you entered in radian: " << fixed << setprecision(8) << rad << "\n";
    return rad;
}

long double power(long double base, int exponent) {
    long double result = 1;
    while (exponent > 0) {                                        //  Function to compute the power
        result *= base;
        exponent--;
    }
    return result;
}

long double factorial(long double num) {
    int temp = num;
    for (int i = 1; i < temp; i++) {                            //  Function to compute the Factorial
        num *= (temp - i);
    }
    return num;
}

void sine(long double rad) {
    long double sine = 0, exponent, numerator, denominator;
    for (int i = 0; i < 15; i++) {
        denominator = factorial((2 * i) + 1);
        numerator = power(-1, i);                                        //  Function to compute the sine of the angle which the user entered
        exponent = power(rad, (2 * i + 1));                                  //  and Display it to the user
        sine += (numerator / denominator * exponent);
    }
    cout << "sin of the angle: " << fixed << setprecision(10) << sine << "\n";
}

void cosine(long double rad) {
    long double cos = 1, exponent, numerator, denominator;
    for (int i = 1; i < 15; i++) {
        denominator = factorial(2 * i);                                  //  Function to compute the cosine of the angle which the user entered
        numerator = power(-1, i);                                       //  and Display it to the user
        exponent = power(rad, (i * 2));
        cos += (numerator * exponent / denominator);
    }
    cout << "cos of the angle: " << fixed << setprecision(10) << cos << "\n";
}

long double bernoulli(int bernoulli2_n) {                             // Function to get the Bernoulli Series
    long double numerator, denominator, result;
    if (bernoulli2_n == 0) {
        numerator = 1, denominator = 6;
    }
    else if (bernoulli2_n == 1) {
        numerator = -1, denominator = 30;
    }
    else if (bernoulli2_n == 2) {
        numerator = 1, denominator = 42;
    }
    else if (bernoulli2_n == 3) {
        numerator = -1, denominator = 30;
    }
    else if (bernoulli2_n == 4) {
        numerator = 5, denominator = 66;
    }
    else if (bernoulli2_n == 5) {
        numerator = -691, denominator = 2730;
    }
    else if (bernoulli2_n == 6) {
        numerator = 7, denominator = 6;
    }
    else if (bernoulli2_n == 7) {
        numerator = -3617, denominator = 510;
    }
    else if (bernoulli2_n == 8) {
        numerator = 43867, denominator = 798;
    }
    else if (bernoulli2_n == 9) {
        numerator = -174611, denominator = 330;
    }
    else if (bernoulli2_n == 10) {
        numerator = 854513,denominator = 138;
    }
    else if (bernoulli2_n == 11) {
        numerator = -236364091, denominator = 2730;
    }
    else if (bernoulli2_n == 12) {
        numerator = 8553103, denominator = 6;
    }
    else if (bernoulli2_n == 13) {
        numerator = -23749461029, denominator = 870;
    }
    else if (bernoulli2_n == 14) {
        numerator = 8615841276005, denominator = 14322;
    }
    result = numerator / denominator;
    return result;
}

long double tan_degree_rad(){
    long double rad;                                   // Function to make the angle degrees in range the tan and convert it to radian
    while (degree>360){                                // to compute the tangent of the angle
        degree=degree-360;
    }
    while (degree<-360){
        degree=degree+360;
    }
    if (degree<90 && degree>=0){
        degree=degree;
    } else if (degree>90 && degree <=180){
        degree=degree-180;
    } else if (degree>180 && degree<270){
        degree=degree-180;
    } else if (degree>270 && degree<=360){
        degree=degree-360;
    }
    rad = degree * 3.141592654 / 180;
    return rad;
}

int check_tan_undefined() {           // Function to check the angle is in range of tan
    int n = 0,result;                      // to check tan is undefined or not
    if (degree < 0) {
        while ((90 - (180 * n)) >= degree) {
            if ((90 - (180 * n)) == degree) {
                result = 0;
            }
            else {
                result = 1;
            }
            n++;
        }
    }
    else if (degree > 0) {
        while ((90 + (180 * n)) <= degree) {
            if ((90 + (180 * n)) == degree) {
                result = 0;
            }
            else {
                result = 1;
            }
            n++;
        }
    }
    return result;
}

void tangent(long double rad) {
    long double tangentt = 0, exponent, numerator, denominator;
    for (int i = 0; i < 15; i++) {
        denominator = factorial((2 * i) + 2);
        numerator = (power(-1, i)) * (power(2, (2 * i) + 2)) * ((power(2, (2 * i) + 2)) - 1) * bernoulli(i);
        exponent = power(rad, (i * 2 + 1));
        tangentt += (numerator / denominator * exponent);                   //  Function to compute the tangent of the angle which the user entered
    }                                                                       //  and Display it to the user
    if (check_tan_undefined()) {
        cout << "tan of the angle: " << fixed << setprecision(10) << tangentt << "\n";
    }
    else {
        cout << "tan of the angle is undefined \n";
    }
}

int main() {                                // the main function
    long double radian;
    radian = deg_rad();                     // calling function to get the angle from the user in degrees and convert it to radian
    sine(radian);                           // calling function to get sine of the angle which the user entered
    cosine(radian);                         // calling function to get cosine of the angle which the user entered
    tangent(tan_degree_rad());                  // calling function to get tangent of the angle which the user entered
    return 0;
}
