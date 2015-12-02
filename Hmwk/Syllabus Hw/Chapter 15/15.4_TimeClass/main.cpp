/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 1, 2015, 10:29 AM
 */

#include <cstdlib>
#include <iostream>
#include "Time.h"

using namespace std;

//Military time class
class MilTime: public Time{
private:
    int mHrs, mSec; //Military time and seconds
public:
    MilTime(); //Base constructor
    
    bool setTime(int); //Sets time to standard
    bool setTime(int,int); //Sets time to standard
    
    int getMHrs(); //Returns military hours
    string getStHrs(); //Returns standard hours
    
};


/*
 * 
 */
int main(int argc, char** argv) {
    MilTime timer;
    int hrs;
    
    cout <<"Enter military time: ";
    cin >> hrs;
    
    if(timer.setTime(hrs)){
        cout <<"Military time: " <<timer.getMHrs() <<endl
                <<"Standard time: " <<timer.getStHrs() <<endl;
    }
    else{
        cout <<"Invalid input!";
    }
    
    return 0;
}

MilTime::MilTime(){
    mHrs = 0;
    mSec = 0;
}
bool MilTime::setTime(int hrs, int sec){
    bool inVal = true;
    
    if(hrs > -1 && hrs <2400 && sec < 60 && sec > -1 ){
        mHrs = hrs;
        mSec = sec;

        tHour = hrs/100;
        tMin =(tHour*100) - hrs;
        if(tHour > 12){
            tHour -= 12;
        }
        tSec = sec;
    }
    else{
        inVal = false;
    }
    
    return inVal;
}
bool MilTime::setTime(int hrs){
    bool inVal = true;
    
    if(hrs > -1 && hrs <2400){
        mHrs = hrs;

        tHour = hrs/100;
        tMin = (tHour*100) - hrs;
        if(tHour > 12){
            tHour -= 12;
        }
    }
    else{
        inVal = false;
    }
    
    return inVal;
}
int MilTime::getMHrs(){
    return mHrs;
}
string MilTime::getStHrs(){
    return tHour+":"+tMin;
}