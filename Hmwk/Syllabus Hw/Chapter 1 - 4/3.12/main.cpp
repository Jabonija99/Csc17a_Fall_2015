/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 22, 2015, 5:00 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Celsius to Fahrenheit
 * F = 9/5C + 32
 */
int main(int argc, char** argv) {
    float cDeg, fDeg; // Variables for degrees in celsius and fahrenheit
    
    cout <<"Celsius to Fahrenheit Converter" <<endl
            <<"Enter temperature (Celsius): ";
    cin >> cDeg;
    
    //Convert celsius to fahrenheit
    fDeg = ((9.0/5.0) * cDeg ) + 32; 
    
    //Output result
    cout <<"Celsius: " <<cDeg <<endl
            <<"Fahrenheit: " <<fDeg <<endl;
    

    return 0;
}

