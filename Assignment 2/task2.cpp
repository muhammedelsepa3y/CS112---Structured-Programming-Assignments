/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 2 of Ass 2
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
// Declare global variable (the names of the three candidates) to use it in more than function
string first_candidate,second_candidate,third_candidate;
// Function to get the names of the three candidates from the user
void names_of_3_candidates() {
    cout << "Please enter the names of the three candidates: ";
    cin >> first_candidate>>second_candidate>>third_candidate;
    while (first_candidate==second_candidate || first_candidate==second_candidate || second_candidate==third_candidate){
        cout<<"You are not allowed to duplicate name of candidate\n";
        cout << "Please enter the names of the three candidates: ";
        cin>>first_candidate>>second_candidate>>third_candidate;
    }
}
// Function to get the number of voters from the user
int number_of_voters() {
    int num;
    cout << "Please enter number of voters: ";
    cin >> num;
    return num;
}
// Declare global variable to use it in more than function
string first_vote,second_vote,third_vote;
// Function to get the number of voters from the user
void voter_choice(string v1,string v2,string v3) {
    cout << "Please enter your choice of three candidates in order of preference: ";
    cin >> first_vote >> second_vote >> third_vote;
    while ((first_vote != v1 && first_vote != v2 && first_vote != v3) || (second_vote != v1 && second_vote != v2 && second_vote != v3)
           || (third_vote != v1 && third_vote != v2 && third_vote != v3) || first_vote == second_vote || first_vote == third_vote || second_vote == third_vote) {

        cout << "Please enter names correctly in order of preference and you are not allowed to duplicate one candidate [ " << v1 << " , " << v2 << " , " << v3 << " ] : \n";
        cin >> first_vote >> second_vote >> third_vote;
    }
}
// Function to compute points for each candidate with the normal majority election system
void old_system(string first__vote ,string first__candidate,string second__candidate ,string third__candidate, int &first_old_point ,int &second_old_point , int &third_old_point) {
    if (first__vote == first__candidate) {
        first_old_point++;
    }
    else if (first__vote == second__candidate) {
        second_old_point++;
    }
    else if (first__vote == third__candidate) {
        third_old_point++;
    }
}
// Function to compute points for each candidate with the new point system
void new_system(string first__vote,string second__vote,string third__vote,string first__candidate,string second__candidate,
                string third__candidate,int &first_new_point,int &second_new_point,int &third_new_point) {
    if (first__vote == first__candidate) {
        first_new_point += 3;
    }
    else if (first__vote == second__candidate) {
        second_new_point += 3;
    }
    else if (first__vote == third__candidate) {
        third_new_point += 3;
    }
    if (second__vote == first__candidate) {
        first_new_point += 2;
    }
    else if (second__vote == second__candidate) {
        second_new_point += 2;
    }
    else if (second__vote == third__candidate) {
        third_new_point += 2;
    }
    if (third__vote == first__candidate) {
        first_new_point += 1;
    }
    else if (third__vote == second__candidate) {
        second_new_point += 1;
    }
    else if (third__vote == third__candidate) {
        third_new_point += 1;
    }

}
// Function to compute who is winner with old system and new system and display his name
void winner(int first_old_point,int second_old_point,int third_old_point,int first_new_point,int second_new_point,int third_new_point
            ,string first__candidate,string second__candidate,string third__candidate) {
    int winner_old_point, winner_new_point;
    winner_old_point = max(first_old_point, max(second_old_point, third_old_point));
    winner_new_point = max(first_new_point, max(second_new_point, third_new_point));
    if (winner_old_point == first_old_point) {
        cout << "the winner in old system is: " <<first__candidate << " with " << first_old_point << " Point\n";
    }
    else if (winner_old_point == second_old_point) {
        cout << "the winner in old system is: " << second__candidate << " with " << second_old_point << " Point\n";
    }
    else if (winner_old_point == third_old_point) {
        cout << "the winner in old system is: " << third__candidate << " with " << third_old_point << " Point\n";
    }
    if (winner_new_point == first_new_point) {
        cout << "the winner in new system is: " << first__candidate << " with " << first_new_point << " Point\n";
    }
    else if (winner_new_point == second_new_point) {
        cout << "the winner in new system is: " << second__candidate << " with " << second_new_point << " Point\n";
    }
    else if (winner_new_point == third_new_point) {
        cout << "the winner in new system is: " << third__candidate << " with " << third_new_point << " Point\n";
    }

}
// Function to calling each function in order to know the winner in The Egyptian Sewing Syndicate
void vote() {
    names_of_3_candidates();
    int first_old_point = 0, second_old_point = 0, third_old_point = 0, first_new_point = 0, second_new_point = 0, third_new_point = 0;
    int num = number_of_voters();
    for (int i = 0; i < num; i++) {
        voter_choice(first_candidate,second_candidate,third_candidate);
        old_system(first_vote,first_candidate,second_candidate,third_candidate,first_old_point,second_old_point,third_old_point);
        new_system(first_vote,second_vote,third_vote,first_candidate,second_candidate,third_candidate,first_new_point,second_new_point,third_new_point);
    }
    winner(first_old_point,second_old_point,third_old_point,first_new_point,second_new_point,third_new_point,first_candidate,second_candidate,third_candidate);
}
// the main function
int main() {
    vote();
    return 0;
}
