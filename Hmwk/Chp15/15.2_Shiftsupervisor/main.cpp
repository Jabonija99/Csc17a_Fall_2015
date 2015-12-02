/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 24, 2015, 10:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Sprvisr.h"

using namespace std;

void fillEmpl(Sprvisr&, string, int, string, float, float);
void outEmpl(Sprvisr);

/*
 * 
 */
int main(int argc, char** argv){
    Sprvisr mnger1; //Supervisor object
    string name, date; //Supervisor name and hire date
    int num; //employee number
    float sal, bonus; //Supervisor's salary and bonus
    bool error; //Error flag
    
    do{
        error = false; //Default to no error
        
        cout <<setprecision(2) <<fixed <<"Enter supervisor name: ";
        cin >> name;
        cout <<"Enter employee number: ";
        cin >> num;
        cout <<"Enter the hire date(mm/dd/yyyy): ";
        cin >> date;
        cout <<"Enter the salary: ";
        cin >> sal;
        cout <<"Enter total bonus earned: ";
        cin >> bonus;
        
        if(date.size() != 10){
            error = true;
            cout <<endl <<endl 
                    <<"Invalid date! Format must be mm/dd/yyyy" <<endl;
        }
        else{
            cout <<endl <<endl;
        }
        
    }while(error);
    
    fillEmpl(mnger1, name, num, date, sal, bonus);
    outEmpl(mnger1);
    
    return 0;
}

void fillEmpl(Sprvisr& mngr, string name, int num, string date, float sal, 
        float bonus){
    mngr.stName(name);
    mngr.stNum(num);
    mngr.stDate(date);
    mngr.stSal(sal);
    mngr.stBonus(bonus);
}
void outEmpl(Sprvisr mngr){
    cout <<"** Employee Information **" <<endl
            <<"Name: " <<mngr.gtName() <<endl
            <<"Number: " <<mngr.gtNum() <<endl
            <<"Hire Date: " <<mngr.gtDate() <<endl
            <<"Salary: " <<mngr.gtSal() <<endl
            <<"Total Bonus: " <<mngr.gtBonus() <<endl;
    
}
