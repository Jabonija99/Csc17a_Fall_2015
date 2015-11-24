/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 24, 2015, 10:37 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Wrkr.h"

using namespace std;

void fillWrkr(Wrkr &, string, int, string, int, float);
void outWrkr(Wrkr);
/*
 * 
 */
int main(int argc, char** argv) {
    Wrkr bob;
    string name, date;
    int num, shft;
    float rate;
    bool error;
    
    do{
        error = false;
        
        cout <<setprecision(2) <<fixed <<"Enter employee name: ";
        cin >> name;
        cout <<"Enter employee number: ";
        cin >> num;
        cout <<"Enter the date(mm/dd/yyyy): ";
        cin >> date;
        cout <<"Enter the shift(1:Day, 2:Night): ";
        cin >> shft;
        cout << "Enter the rate of pay: ";
        cin >> rate;
        
        if(date.size() != 10){
            error = true;
            cout <<endl <<endl 
                    <<"Invalid date! Format must be mm/dd/yyyy" <<endl;
        }
        else if(shft != 1 && shft != 2){
            error = true;
            cout <<endl <<endl
                    <<"Invalid shift! Value must be 1 or 2" <<endl;
        }
        else{
            cout <<endl <<endl;
        }
    }while(error);
    
    //Assign user input to worker class
    fillWrkr(bob, name, num, date, shft, rate);
    
    outWrkr(bob);
    
    
    
    
    return 0;
}

void fillWrkr(Wrkr &bob, string name, int num, string date, int shft, float rate){
    bob.stName(name);
    bob.stNum(num);
    bob.stDate(date);
    bob.stShft(shft);
    bob.stRate(rate);
}

void outWrkr(Wrkr bob){
    cout <<"** Employee Information **" <<endl
            <<"Name: " <<bob.gtName() <<endl
            <<"Number: " <<bob.gtNum() <<endl
            <<"Hire Date: " <<bob.gtDate() <<endl
            <<"Shift: " <<bob.gtShft() <<endl
            <<"Rate of Pay: " <<bob.gtRate() <<endl;
   
}