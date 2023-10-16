/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 3
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int main() {
    cout<<"\n\n"<<setw(87)<<"Welcome To The Calculation Program for telephone charges\n";
    cout<<setw(87)<<"--------------------------------------------------------\n";                       //Display a message to welcome the user
    cout<<setw(78)<<"-  Please select Plan A or Plan B  -\n\n\n";

    cout<<setw(69)<<"| Plan A : Premium |\n\n";
    cout<<setw(19)<<"Day"<<setw(25)<<"Time"<<setw(30)<<"Call Duration"<<setw(30)<<"Rate per minute\n";
    cout<<setw(15)<<"From"<<setw(8)<<"To"<<setw(15)<<"From"<<setw(12)<<"To\n\n";
    cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<"< 15 min"<<setw(29)<<"L.E. 0.60\n";
    cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<">= 15 min"<<setw(29)<<"L.E. 0.80\n";
    cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"05:00 pm"<<setw(11)<<"07:00 am"<<setw(23)<<"any duration"<<setw(27)<<"L.E. 0.45\n";         //Display all information about Plan A
    cout<<setw(16)<<"Friday"<<setw(10)<<"Saturday"<<setw(14)<<"any time"<<setw(11)<<"any time"<<setw(23)<<"any duration"<<setw(28)<<"L.E. 0.25\n\n";
    cout<<setw(108)<<"________________________________________________________________________________________________\n\n\n";

    cout<<setw(69)<<"| Plan B : Platinum |\n\n";
    cout<<setw(19)<<"Day"<<setw(27)<<"Time"<<setw(30)<<"Call Duration"<<setw(30)<<"Rate per minute\n";
    cout<<setw(15)<<"From"<<setw(9)<<"To"<<setw(16)<<"From"<<setw(12)<<"To\n\n";
    cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<"< 30 min"<<setw(29)<<"L.E. 0.60\n";
    cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<">= 30 min"<<setw(29)<<"L.E. 0.80\n";
    cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"05:00 pm"<<setw(11)<<"07:00 am"<<setw(23)<<"any duration"<<setw(27)<<"L.E. 0.45\n";         //Display all information about Plan B
    cout<<setw(17)<<"Thursday"<<setw(11)<<"Saturday"<<setw(14)<<"any time"<<setw(11)<<"any time"<<setw(23)<<"any duration"<<setw(28)<<"L.E. 0.25\n\n";
    cout<<setw(108)<<"________________________________________________________________________________________________\n\n\n";

    cout<<setw(23)<<"Call Data :-\n\n";
	cout<<setw(33)<<"Please enter A or B : ";                       //Display a message to know that user choose plan a or b
	char user_plan;                                               //Declaration a variable ( user_plan )
	cin>>user_plan;                                              //get the choosed plan from the user
	if (user_plan!='A' && user_plan!='B'){                       //check if the choosed plan is not a nor b so it will be got again
        cout<<setw(27)<<"Invalid Value \n\n";
        cout<<setw(30)<<"Please try again : ";
        cin>>user_plan;
	}
	cout<<setw(36)<<"-----------------------\n\n";

	cout<<setw(77)<<"Please Enter The Call Start time in 24-hour format as \"15:12:20\": ";  //Display a message to get the call start time from the user
	string start_time;                                                   //Declaration a variable ( start_time )
	cin>>start_time;                                                  //get the call start time from the user
	int start_hour,start_minute,start_second;                          //Declaration a variable ( start_hour , start_minute , start_second )
	char a,b,c,d,e,f;
	a=start_time[0];
	b=start_time[1];
	c=start_time[3];
	d=start_time[4];
	e=start_time[6];
	f=start_time[7];
	start_hour=((a-48)*10)+(b-48);                                        //calculate ( start_hour , start_minute , start_second )
    start_minute=((c-48)*10)+(d-48);
    start_second=((e-48)*10)+(f-48);

    if (start_hour < 0 || start_minute<0 ||start_second<0 || start_hour>23 ||start_minute>59 || start_second>59){
        /*check if start_hour<0 or start_minute<0 or start_second<0 or start_hour>23 or start_minute>59 or start_second>59
        it will get the call start time again from the user and calculate start_hour and start_minute and start_second  */
        cout<<"\n\n";
        cout<<setw(27)<<"Invalid Value \n\n";
        cout<< setw(30)<<"Please try again : ";
        cin>>start_time;
        a=start_time[0];
        b=start_time[1];
        c=start_time[3];
        d=start_time[4];
        e=start_time[6];
        f=start_time[7];
        start_hour=((a-48)*10)+(b-48);
        start_minute=((c-48)*10)+(d-48);
        start_second=((e-48)*10)+(f-48);
	}
	cout<<setw(87)<<"--------------------------------------------------------------------------\n\n";

	cout<<setw(75)<<"Please Enter The Call End time in 24-hour format as \"15:22:20:\" ";   //Display a message to get the call end time from the user
	string end_time;                                                    //Declaration a variable ( end_time )
	cin>>end_time;                                                      //get the call end time from the user
	int end_hour,end_minute,end_second;                                 //Declaration a variable ( end_hour , end_minute , end_second )
	char g,h,i,j,k,l;
	g=end_time[0];
	h=end_time[1];
	i=end_time[3];
	j=end_time[4];
	k=end_time[6];
	l=end_time[7];
	end_hour=((g-48)*10)+(h-48);                                        //calculate ( end_hour , end_minute , end_second )
	end_minute=((i-48)*10)+(j-48);
	end_second=((k-48)*10)+(l-48);

	if ((start_hour==end_hour && start_minute>=end_minute && start_second>=end_second) || end_hour<start_hour || end_hour < 0 || end_hour>23 || end_minute<0 || end_minute>59 || end_second<0 || end_second>59){
         /*check if end_hour<0 or end_minute<0 or end_second<0 or end_hour>23 or end_minute>59 or end_second>59
        it will get the call end time again from the user and calculate end_hour and end_minute and end_second  */
        cout<<"\n\n";
        cout<<setw(27)<<"Invalid Value \n\n";
        cout<<setw(30)<<"Please try again : ";
        cin>>end_time;
        int end_hour,end_minute,end_second;
        char g,h,i,j,k,l;
        g=end_time[0];
        h=end_time[1];
        i=end_time[3];
        j=end_time[4];
        k=end_time[6];
        l=end_time[7];
        end_hour=((g-48)*10)+(h-48);
        end_minute=((i-48)*10)+(j-48);
        end_second=((k-48)*10)+(l-48);
        cout<<setw(85)<<"------------------------------------------------------------------------\n\n";
	} else{
        cout<<setw(85)<<"------------------------------------------------------------------------\n\n";
	}

	string day_name;                                                    //Declaration a variable ( day_name )
	int day_number,month_number;                                        //Declaration a variable ( day_number , month_number )
	cout<<setw(16)<<"Note\n";
	cout<<setw(51)<<"Days: {Sat-Sun-Mon-Tues-Wed-Thurs-Fri}\n\n";
	cout<<setw(48)<<"Please Enter The Date as \"Sat 22 4\": ";          // Display a message to get day name and day number and month number from the user
	cin>>day_name>>day_number>>month_number;                            //get day name and day number and month number from the user
	if (day_number>31 || month_number>12 || (day_name!="Sat" && day_name!="Sun" && day_name!="Mon" && day_name!="Tues" && day_name!="Wed" && day_name!="Thurs" && day_name!="Fri" )){
        /*check if day_number>31 or month_number>12 or day_name does not exist it will get the date again*/
        cout<<setw(27)<<"Invalid Value \n\n";
        cout<<setw(30)<<"Please try again : ";
        cin>>day_name>>day_number>>month_number;
	}
	cout<<setw(58)<<"---------------------------------------------\n\n";
	cout<<setw(95)<<"__________________________________________________________________________"<<"\n\n";

    cout<<setw(77)<<"You will be charged for the call at the plan "<<user_plan<<setw(8)<<" rates \n\n";
    cout<<setw(31)<<"Call information :- \n\n";              //Display a message that including call information (start time and end time and date
    cout<<setw(21)<<"Start time: "<<start_time<<"\n";
    cout<<setw(19)<<"End time: "<<end_time<<"\n";
    cout<<setw(15)<<"Date: "<<day_name<<" "<<day_number<<" "<<month_number<<"\n";

    int duration;                                            // Declaration a variable (duration)
    //Calculate the duration
    if(end_minute>start_minute){
        duration=(((end_hour-start_hour)*60)+(end_minute-start_minute));
        if (end_second>start_second){
                duration++;
        }
    }else if(end_minute==start_minute){
        duration=(((end_hour-start_hour)*60)+(end_minute-start_minute));
        if (end_second>start_second){
                duration++;
        }
    }else{
        duration=((end_hour-start_hour-1)*60)+(end_minute+60-start_minute);
        if (end_second>start_second){
                duration++;
        }
    }
    cout<<setw(19)<<"Duration: "<<duration<<" minutes\n";  //Display a message that including call information (duration and choosed plan by the user
    cout<<setw(15)<<"Plan: "<<user_plan<<"\n";

    double rate;  //Declaration a variable ( rate )
    if(user_plan=='A'){
        /* calculate the rate by check if user choose plan a or b
           becuase the rate depend on  choosed plan by the user
           and display all information about choosed plan */
            cout<<setw(69)<<"| Plan A : Premium |\n\n";
            cout<<setw(20)<<"Day"<<setw(24)<<"Time"<<setw(30)<<"Call Duration"<<setw(30)<<"Rate per minute\n";
            cout<<setw(15)<<"From"<<setw(8)<<"To"<<setw(15)<<"From"<<setw(12)<<"To\n\n";
            cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<"< 15 min"<<setw(29)<<"L.E. 0.60\n";
            cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<">= 15 min"<<setw(29)<<"L.E. 0.80\n";
            cout<<setw(16)<<"Sunday"<<setw(10)<<"Thursday"<<setw(14)<<"05:00 pm"<<setw(11)<<"07:00 am"<<setw(23)<<"any duration"<<setw(27)<<"L.E. 0.45\n";
            cout<<setw(16)<<"Friday"<<setw(10)<<"Saturday"<<setw(14)<<"any time"<<setw(11)<<"any time"<<setw(23)<<"any duration"<<setw(30)<<"L.E. 0.25\n\n\n\n";
            if(day_name=="Sat" || day_name=="Fri"){
                rate=duration*0.25;
            } else {
                if (start_hour>=7 && start_hour<=17){
                        if (duration<15){
                            rate=0.60*duration;
                        } else {
                            rate=0.80*duration;
                        }
                } else{
                        rate=0.45*duration;
                }
            }
    } else
     {
            cout<<setw(69)<<"| Plan B : Platinum |\n\n";
            cout<<setw(19)<<"Day"<<setw(27)<<"Time"<<setw(30)<<"Call Duration"<<setw(30)<<"Rate per minute\n";
            cout<<setw(15)<<"From"<<setw(9)<<"To"<<setw(16)<<"From"<<setw(12)<<"To\n\n";
            cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<"< 30 min"<<setw(29)<<"L.E. 0.60\n";
            cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"07:00 am"<<setw(11)<<"05:00 pm"<<setw(21)<<">= 30 min"<<setw(29)<<"L.E. 0.80\n";
            cout<<setw(16)<<"Sunday"<<setw(12)<<"wednesday"<<setw(14)<<"05:00 pm"<<setw(11)<<"07:00 am"<<setw(23)<<"any duration"<<setw(27)<<"L.E. 0.45\n";
            cout<<setw(17)<<"Thursday"<<setw(11)<<"Saturday"<<setw(14)<<"any time"<<setw(11)<<"any time"<<setw(23)<<"any duration"<<setw(30)<<"L.E. 0.25\n\n\n\n";
            if(day_name=="Sat" || day_name=="Fri" || day_name=="Thurs"){
                rate=duration*0.25;
            } else {
                if (start_hour>=7 && start_hour<=17){
                        if (duration<30){
                            rate=0.60*duration;
                        } else {
                            rate=0.80*duration;
                        }
                } else{
                        rate=0.45*duration;
                }
            }
    }

    cout<<setw(70)<<"-----------------------\n";
    cout<<setw(63)<<"Call Rate: L.E. "<<fixed<<setprecision(2)<<rate<<"\n";    //Display a price clarification message
    cout<<setw(72)<<"-----------------------\n\n\n";

    return 0;
}
