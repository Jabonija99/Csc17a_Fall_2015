/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 13, 2015, 10:03 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>

//User Libraries

//Global constants

//User objects
class pDate{
private:
    //Integer for month, day, and year
    int dMnth, dDay, dYear;
public:
    //Constructor
    Date();
    
    //Setters for
    void setMnth(int);//Month
    void setDay(int); //Day
    void setYear(int);//Year
    
    //Output
    void outNDate(); //Numeric date
    void outWDate(); //Western format for date
    void outEDate(); //Eastern format for date

};

//Function Prototypes
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Date variable for current date
    pDate cDate;
    //Integers for month day and year
    int mnth,day,yr;
    //Flag for input Validation
    bool inVal;
    
    do{
        inVal = true;
        
        cout <<"Enter the following" <<endl
                <<"Day: ";
        cin >> day;
        cout <<"Month: ";
        cin >> mnth;
        cout <<"Year: ";
        cin >> yr;
    
        if(day < 1 || day > 31){
            cout <<"Invalid input! Days(1-31)" <<endl;
            inVal = false;
        }
        
        if(mnth < 1 || mnth > 12){
            cout << "Invalid input! Month(1-12)" <<endl;
            inVal = false;         
        }
        
        if(yr < 0){
            cout <<"Invalid input! Year(>0)" <<endl;
            inVal = false;
        }
        
    }while(!inVal);
    
    cDate.setDay(day);
    cDate.setMnth(mnth);
    cDate.setYear(yr);
    
    cDate.outNDate();
    cDate.outWDate();
    cDate.outEDate();
    
    
    return 0;
}

void pDate::setDay(int day){
    dDay = day;
}
void pDate::setMnth(int mnth){
    dMnth = mnth;
}
void pDate::setYear(int yr){
    dYear = yr;
}
void pDate::outNDate(){
    cout <<dMnth <<"/" <<dDay <<"/" <<dYear <<endl;
}
void pDate::outWDate(){
    switch(dMnth){
        case 1:
            cout <<"January "<<dDay <<", " <<dYear <<endl;
            break;
        case 2:
            cout <<"February "<<dDay <<", " <<dYear <<endl;
            break;
        case 3:
            cout <<"March "<<dDay <<", " <<dYear <<endl;
            break;
        case 4:
            cout <<"April "<<dDay <<", " <<dYear <<endl;
            break;
        case 5:
            cout <<"May "<<dDay <<", " <<dYear <<endl;
            break;
        case 6:
            cout <<"June "<<dDay <<", " <<dYear <<endl;
            break;
        case 7:
            cout <<"July "<<dDay <<", " <<dYear <<endl;
            break;
        case 8:
            cout <<"August "<<dDay <<", " <<dYear <<endl;
            break;
        case 9:
            cout <<"September "<<dDay <<", " <<dYear <<endl;
            break;
        case 10:
            cout <<"October "<<dDay <<", " <<dYear <<endl;
            break;
        case 11:
            cout <<"November "<<dDay <<", " <<dYear <<endl;
            break;
        case 12:
            cout <<"December "<<dDay <<", " <<dYear <<endl;
            break;
    }
}

void pDate::outEDate(){
    switch(dMnth){
        case 1:
            cout <<dDay <<" January "<<dYear <<endl;
            break;
        case 2:
            cout <<dDay <<" February "<<dYear <<endl;
            break;
        case 3:
            cout <<dDay <<" March "<<dYear <<endl;
            break;
        case 4:
            cout <<dDay <<" April "<<dYear <<endl;
            break;
        case 5:
            cout <<dDay <<" May "<<dYear <<endl;
            break;
        case 6:
            cout <<dDay <<" June "<<dYear <<endl;
            break;
        case 7:
            cout <<dDay <<" July "<<dYear <<endl;
            break;
        case 8:
            cout <<dDay <<" August "<<dYear <<endl;
            break;
        case 9:
            cout <<dDay <<" September "<<dYear <<endl;
            break;
        case 10:
            cout <<dDay <<" October "<<dYear <<endl;
            break;
        case 11:
            cout <<dDay <<" November "<<dYear <<endl;
            break;
        case 12:
            cout <<dDay <<" December "<<dYear <<endl;
            break;
    }
}

