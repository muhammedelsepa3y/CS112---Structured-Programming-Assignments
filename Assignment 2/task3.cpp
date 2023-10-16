/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 3 of Ass 2
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int counts=0;                   //Declare a global variable  (the number of the credit card number) to use it in more than one function
unsigned long long int credit_number_int;   //Declare a global variable  (the credit card number) to use it in more than one function
string credit_number_string ;
// Function to get the credit card number from the user and compute the number of digits of the credit card number
unsigned long long int credit_number(){
    cout<<"Please enter your credit card number here: ";
    cin>>credit_number_int;
    counts=log10(credit_number_int)+1;
    while (counts>16 || counts<14){
        cout<<"Your credit card number is false (credit card number must be in range 14 to 16 number)\n";
        cout<<"Please correct your credit card number here: ";
        cin>>credit_number_int;
        counts=log10(credit_number_int)+1;
    }
    stringstream credit___number___int__string;
    credit___number___int__string<<credit_number_int;
    credit_number_string = credit___number___int__string.str();
}
// Function to check if the number have two digit it will sum them until it will be one digit
int check_single_digit(long int digit){
    int left,right;
    int count_=log10(digit)+1;
    left=digit;
    while(count_!=1){
        right=left%10;
        left=left/10;
        digit=right+left;
        count_=log10(digit)+1;
    }
    return digit ;
}
// Function to multiply each second digit by 2 from the right
unsigned long long int point_2_3(unsigned long long int credit_num){
    int multiply,result_=0;
    unsigned long long int left=credit_num,right;
    for(int i =0;i<counts;i++){
        left=left/10;
        right=left%10;
        if (counts==15){
            if (i>=0 && i%2!=0){
                multiply=2*right;
                result_+=check_single_digit(multiply);
            }
        } else if (counts==14 || counts==16){
            if(i>=0 && i%2==0){
                multiply=2*right;
                result_+=check_single_digit(multiply);
            }
        }
    }
    return result_;
}
//Function to Sum the digits that had not been multiplied by 2 in previous function
unsigned long long int point_4(){
    int sum=0;
    if (counts==14){
        int h=1;
        for(int k=0;k<7;k++){
            sum+=(credit_number_string[h]-48);
            h+=2;
        }
    } else if (counts==15){
        int h=0;
        for(int k=0;k<8;k++){
            sum+=(credit_number_string[h]-48);
            h+=2;
        }
    }else if (counts==16){
        int h=1;
        for(int k=0;k<8;k++){
            sum+=(credit_number_string[h]-48);
            h+=2;
        }
    }
    return sum;
}
//function to check Credit card number validation
string validity(){
    unsigned long long int result;
    credit_number();
    result=point_2_3(credit_number_int)+point_4();
    if (result%10==0){
        return "true";
    } else {
        return "false";
    }
}
// the main function
int main(){
    cout<<validity()<<"\n";
    return 0;
}
