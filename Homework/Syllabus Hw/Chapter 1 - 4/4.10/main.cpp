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
 * 
 */
int main(int argc, char** argv) {
    float sales, comRate, bonus;
    
    cout <<"Enter sales amount: " <<endl;
    cin >> sales;
    
    if(sales > 50000){
        comRate = 0.25;
        bonus = 250;
    }
    else{
        comRate = 0;
        bonus = 0;
    }
    
    cout <<"Sales: $" <<sales <<endl
            <<"Commission Rate: $" <<comRate <<endl
            <<"Bonus: $" <<bonus <<endl;
    
    return 0;
}

