/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 22, 2015, 5:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

//Global constants
float YEN_PER_DOLLAR = 98.93;
float EUROS_PER_DOLLAR = 0.74;

using namespace std;


/*
 * Currency Conversion
 */
int main(int argc, char** argv) {
    float dollar, yen, euro; //Variables for dollar amounts
    
    cout << "Dollar conversion" <<endl
            <<"Enter a dollar amount: ";
    cin >> dollar;
    
    //Convert dollar amount
    yen = YEN_PER_DOLLAR * dollar;
    euro = EUROS_PER_DOLLAR * dollar;
    
    //Output result
    cout <<setprecision(2) <<fixed << "Dollar: $" <<dollar <<endl
            <<"Yen:  $" <<yen <<endl
            <<"Euros: $" <<euro <<endl;
    
    
    return 0;
}

