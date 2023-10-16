/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 1
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double the_temperature_in_degrees_celsius,
        the_wind_speed_in_kilometers_per_hour,                                                                              //Declaration the variables
        the_wind_chill_temperature;

    cout << "Please enter the temperature in degrees Celsius: ";                                                            //Display a message to get the temperature in degrees Celsius from the user

    cin >> the_temperature_in_degrees_celsius;                                                                              //get the temperature in degrees Celsius from the user

    cout << "Please enter the wind speed in kilometers per hour: ";                                                         //Display a message to get the wind speed in kilometers per hour from the user

    cin >> the_wind_speed_in_kilometers_per_hour;                                                                           //get the wind speed in kilometers per hour from the user

    the_wind_chill_temperature = 13.12 + (0.6215 * the_temperature_in_degrees_celsius) -
        (11.37 * (pow(the_wind_speed_in_kilometers_per_hour, 0.16))) +                                                      //Calculate the wind chill temperature
        (0.3965 * the_temperature_in_degrees_celsius * (pow(the_wind_speed_in_kilometers_per_hour, 0.16)));

    cout << "\nThe wind chill temperature is: " << fixed << setprecision(2) << the_wind_chill_temperature << endl;          //Display a message to illustrate the output of the wind chill temperature
    return 0;
}
