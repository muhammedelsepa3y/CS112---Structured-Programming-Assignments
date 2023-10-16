/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double x_coordinate_of_the_center_of_the_circle,
        y_coordinate_of_the_center_of_the_circle,
        the_radius_of_the_circle, x_coordinate_of_the_point,                                                 // Declaration the variables
        y_coordinate_of_the_point,distance,difference;

    cout << "Enter coordinates of the center of the circle: ";                                               // Display a message to get coordinates of the center of the circle from the user

    cin >> x_coordinate_of_the_center_of_the_circle >> y_coordinate_of_the_center_of_the_circle;             // Get coordinates of the center of the circle from the user

    cout << "Enter the radius of the circle: ";                                                              // Display a message to get the radius of the circle from the user

    cin >> the_radius_of_the_circle;                                                                         // Get the radius of the circle from the user

    cout << "Enter coordinates of the point: ";                                                              // Display a message to get coordinates of the point from the user

    cin >> x_coordinate_of_the_point >> y_coordinate_of_the_point;                                           // Get coordinates of the point from the user

    distance = sqrt((pow((x_coordinate_of_the_point-x_coordinate_of_the_center_of_the_circle),2))
        +(pow((y_coordinate_of_the_point-y_coordinate_of_the_center_of_the_circle),2)));                     // Calculate the distance between the point and the center of the circle

    if (distance>the_radius_of_the_circle)
    {
        difference = distance - the_radius_of_the_circle;                        // Calculate the difference between (distance between the point and the center of the circle) and( the radius of the circle )
    } else {
        difference =  the_radius_of_the_circle- distance ;
    }

    if (difference < 0.01) {
        distance = the_radius_of_the_circle;                                                                 // Check if the difference less than 0.01, distance will be equal to the radius of the circle
    }

    if (the_radius_of_the_circle > distance) {
        cout << "\nInside the circle\n";             // Display a message "Inside the circle" if the radius of the circle is bigger than the distance between the point and the center of the circle (the point is located inside the circle)
    } else if (distance>the_radius_of_the_circle){
        cout << "\nOutside the circle\n";         // Display a message "Outside the circle" if the radius of the circle is less than the distance between the point and the center of the circle (the point is located outside the circle)
    } else {
        cout << "\nOn the circle\n";           // Display a message "On the circle" if the radius of the circle is equal to the distance between the point and the center of the circle (the point is located on the circle)
    }
    return 0;
}
