/* 
 * File:   AccSve.cpp
 * Author: Kauru99
 * 
 * Created on December 16, 2015, 5:18 PM
 */
#include <iostream>
#include <iomanip>
#include "AccSve.h"

using namespace std;

AccSve::AccSve(float bal){
    if(bal > 0){
        aBalance = bal;
    }
    else{
        aBalance = 0;
    }
    
    aFreqWithdraw = 0;
    aFreqDeposit = 0;
}
void AccSve::transaction(float amount){
    if(amount > 0){
        deposit(amount);
    }
    else{
        if(withdraw(amount) == -1){
            cout <<"Insufficient funds!" <<endl;
        }
    }
}
float AccSve::total(float savint, int time){
    float interest = 1;
    for(int i = 0; i < time; i++){
        interest *= (1+savint);
    }
    return (aBalance*interest);
}
float AccSve::totalRecursive(float savint, int time){
    pInt *= (1+savint);
    time--;
    if(time != 0){
        totalRecursive(savint, time);
    }
    
    return (aBalance*pInt);
}
void AccSve::toString(){
    cout <<setprecision(2) <<fixed <<"Balance: $" <<aBalance <<endl
            <<"Withdraws: " <<aFreqWithdraw <<endl
            <<"Deposits: " <<aFreqDeposit <<endl;
            

}
float AccSve::withdraw(float amount){
    amount *= -1;
    
    if(aBalance < amount){
        return -1;
    }
    else{    
        aBalance -= amount;
        aFreqWithdraw++;
        return amount;
    }
}
float AccSve::deposit(float amount){
    aBalance += amount;
    aFreqDeposit++;
}

