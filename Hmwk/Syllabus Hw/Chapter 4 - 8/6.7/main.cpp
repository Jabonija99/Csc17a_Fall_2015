/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 23, 2015, 4:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float celsius(float);

/*
 * 6.7 Celsius Temperature Table
 */
int main(int argc, char** argv) {
    cout <<left <<setw(15) <<"Fahrenheit" <<setw(6) <<"||" <<" Celsius" <<endl
            <<"========================================" <<endl;
    for(int i = 0; i < 21; i++){
        cout <<setw(15) <<i <<setw(6) <<"||" <<celsius(i) <<endl;
    }
            
    return 0;
}

float celsius(float fDeg){
    float cDeg = 5.0/9.0*(fDeg - 32);
    return cDeg;
}