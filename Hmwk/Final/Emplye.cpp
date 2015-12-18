/* 
 * File:   Emplye.cpp
 * Author: Kauru99
 * 
 * Created on December 17, 2015, 2:08 PM
 */

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Emplye.h"


Emplye::Emplye(char name[], char title[], float hrRate){
    //Copies name to object name
    strcpy(eName, name);
    //Copies job title to object job title
    strcpy(eTitle, title);
    //Sets hourly rate
    eHrRate = hrRate;
    
    //Sets hours worked
    eHrWork = 0;
    //Sets gross pay
    eGrssPay = 0;
    //Sets net pay
    eNetPay = 0;
}

float Emplye::tax(float amount){
    //Tax total and tax counter
    float tax=0, taxCt=0;
    
    //While the amount is greater than 0
    while(amount > 0){
        //For pay 500 or less
        if(taxCt < 501){
            //Tax 10%
            tax += 1*0.1;
        }
        //For pay over 500 and below 1000
        else if(taxCt > 500 && taxCt < 1001){
            //Tax 20%
            tax+= 1*0.2;
        }
        else{
            //Tax 30%
            tax+=1*0.3;
        }
        //Decrement the amount
        amount--;
        //Increment the counter
        taxCt++;
    }
    //Returns the tax
    return tax;
}

float Emplye::CalculatePay(float rate, int hrs){
    return getNetPay(getGrossPay(setHourlyRate(rate), setHoursWorked(hrs)));
}

float Emplye::getGrossPay(float rate, int hrs){
    float pay=0, payCt=0;
    
    while(hrs > 0){
        if(payCt < 40){
            pay += rate;
        }
        else if(payCt > 39 && payCt < 50){
            pay += (rate+(rate/2.0));
        }
        else{
            pay += (rate*2);
        }
        
        hrs--;
        payCt++;
    }
    
    eGrssPay = pay;
    return eGrssPay;
}
float Emplye::getNetPay(float gross){
    eNetPay = gross - tax(gross);
    return eNetPay;
}

void Emplye::toString(){
    int index = 0;
    
    cout <<setprecision(2) <<fixed 
            <<"Employee Information" <<endl;
    
    cout <<"Name: ";
    while(eName[index]!='\0'){
        cout << eName[index];
        index++;
    }
    
    cout <<"  Title: ";
    index = 0;
    while(eTitle[index]!='\0'){
        cout <<eTitle[index];
        index++;
    }
    cout <<endl;
    
    cout <<"Hourly Rate: " <<eHrRate <<" Hours Worked: " <<eHrWork
            <<" Gross Pay: " <<eGrssPay <<" Net Pay: " <<eNetPay <<endl;
}

int Emplye::setHoursWorked(int hrs){
    if(hrs > 0 && hrs < 84){  
        eHrWork = hrs;
    }
    else{
        cout <<"Unacceptable hours!" <<endl;
    }
    return eHrWork;
}
float Emplye::setHourlyRate(float rate){
    if(rate > 0 && rate < 200){   
        eHrRate = rate;
    }
    else{
        cout << "Unacceptable rate!" <<endl;
    }
    return eHrRate;
}


