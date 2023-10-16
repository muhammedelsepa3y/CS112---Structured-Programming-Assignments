/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 1 of Ass 3
#include <iostream>
using namespace std;
int the_length_of_the_surface;
char**make_a_surface();
int the_number_of_close_micro_organisms(char**,int ,int );
bool check_next_iteration_will_have_a_micro_organism(char**,int ,int );
char** the_new_surface(char**);
void print_current_surface(char**);
void update_current_surface(char**,char**);


// the main function to take the length of the surface and the number of the iterations from the user
// and make a loop to print each surface state
int main(){
    cout<<"Please enter the length/width of the square surface: ";
    cin>>the_length_of_the_surface;
    while(the_length_of_the_surface<=1){
        cout<<"Invalid Value it should be greater than 1\nPlease enter again the length of the square surface: ";
        cin>>the_length_of_the_surface;
    }
    cout<<"Please enter the number of the iterations: ";
    int the_number_of_the_iterations;
    cin>>the_number_of_the_iterations;
    while(the_number_of_the_iterations<=1){
        cout<<"Invalid Value it should be greater than 1\nPlease enter again the number of the iterations: ";
        cin>>the_number_of_the_iterations;
    }
    char**the_surface=make_a_surface();
    while(the_number_of_the_iterations>=0){
        the_number_of_the_iterations--;
        print_current_surface(the_surface);
        char**new_surface=the_new_surface(the_surface);
        update_current_surface(the_surface,new_surface);
    }
    return 0;
}
// function to build the square surface
char**make_a_surface(){
    char**the_surface=new char*[the_length_of_the_surface];
    for(int row_=0;row_<the_length_of_the_surface;row_++){
        the_surface[row_]=new char[the_length_of_the_surface];
    }
    char user_input;
    for(int row_=0;row_<the_length_of_the_surface;row_++){
        for(int column_=0;column_<the_length_of_the_surface;column_++){
            cout<<"Please enter the value of plot array["<<row_<<"]["<<column_<<"] = M or - : ";
            cin>>user_input;
            while(user_input!='M' && user_input!='-'){
                cout<<"\nInvalid value ... you should enter M or -\nPlease try again: ";
                cin>>user_input;
            }
            the_surface[row_][column_]=user_input;
        }
    }
    return the_surface;
}
// Function to print each surface state
int m=0;
void print_current_surface(char**the_surface){
    cout<<"\n";
    if(m==0){
        cout<<"the initial state of the surface\n";
    } else{
        cout<<"iteration \""<<m<<"\"\n";
    }
    m++;
    for(int row_=0;row_<the_length_of_the_surface;row_++){
        cout<<"[";
        for(int column_=0;column_<the_length_of_the_surface;column_++)
        cout<<the_surface[row_][column_];
        cout<<"]\n";
    }
    cout<<"\n";
}
// Function to get the number of close micro organisms
int the_number_of_close_micro_organisms(char**the_surface,int row_,int column_){
    int close_micro_organisms_number=0;
    for(int row=row_-1;row<=row_+1;row++){
        for(int column=column_-1;column<=column_+1;column++){
            if(row<0 ||column<0|| row>=the_length_of_the_surface|| column>=the_length_of_the_surface || (row==row_ && column==column_)){
                continue;
            }
            if(the_surface[row][column]=='M'  ){
                close_micro_organisms_number++;
            }
        }
    }
    return close_micro_organisms_number;
}
// A function which should return whether in the next iteration, this block will be empty or have a micro-organism
bool check_next_iteration_will_have_a_micro_organism(char**the_surface,int row_,int column_){
    bool check;
    int number_of_close_micro_organisms=the_number_of_close_micro_organisms(the_surface,row_,column_);
    if(the_surface[row_][column_]=='M'){
        if(number_of_close_micro_organisms==2 || number_of_close_micro_organisms==3){
            check=1;
        } else {
            check=0;
        }
    } else {
        if (number_of_close_micro_organisms==3){
            check=1;
        } else{
            check=0;
        }
    }
    return check;
}
// Function to get the new surface (next iteration)
char** the_new_surface(char**the_surface){
    char**new_surface=new char*[the_length_of_the_surface];
    for(int row_=0;row_<the_length_of_the_surface;row_++){
        new_surface[row_]=new char[the_length_of_the_surface];
    }
    for(int row_=0;row_<the_length_of_the_surface;row_++){
        for(int column_=0;column_<the_length_of_the_surface;column_++){
            if(check_next_iteration_will_have_a_micro_organism(the_surface,row_,column_)){
                new_surface[row_][column_]='M';
            } else {
                new_surface[row_][column_]='-';
            }
        }
    }
    return new_surface;
}
// function which will apply the new states from the next state surface to the current state surface.
void update_current_surface(char**the_surface , char**new_surface){
    for (int row=0;row<the_length_of_the_surface;row++){
        for(int column=0;column<the_length_of_the_surface;column++){
            the_surface[row][column]=new_surface[row][column];
        }
    }
}
