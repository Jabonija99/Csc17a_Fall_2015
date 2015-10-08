/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 22, 2015, 5:15 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Days in a month
 */
int main(int argc, char** argv) {
    int month, year, days; //Variables for day, month, and year
    bool inValid; //Input validation
    
    cout <<"Days of the month" <<endl;
    
    do{
        cout <<"Enter the month (1-12): ";
        cin >> month;
        cout <<"Enter the year: ";
        cin >> year;

        switch(month){
            case 1: //Jan.
                days = 31;
                inValid = true;
                break;

            case 2: //Feb.
                if(year%100 == 0 && year%400 == 0){
                    days = 29;
                }
                else if(year%4 == 0){
                    days = 29;
                }
                else{
                    days = 28;
                }

                inValid = true;
                break;

            case 3://Mar
                days = 31;
                inValid = true;
                break;

            case 4://Apr
                days = 30;
                inValid = true;
                break;

            case 5://May
                days = 31;
                inValid = true;
                break;

            case 6://Jun
                days = 30;
                inValid = true;
                break;

            case 7://Jul
                days = 31;
                inValid = true;
                break;

            case 8://Aug
                days =  31;
                inValid = true;
                break;

            case 9://Sep
                days = 30;
                inValid = true;
                break;

            case 10://Oct
                days = 31;
                inValid = true;
                break;

            case 11://Nov
                days = 30;
                inValid = true;
                break;

            case 12://Dec
                days = 31;
                inValid = true;
                break;

            default:
                //Prompt and flag for invalid input
                cout <<"Invalid input!" <<endl;
                inValid = false;
                break;
        }
    }while(!inValid); //Repeats as long as the input is not valid.   
    
    //Output days
    cout <<"Days: " <<days;
    
    return 0;
}

