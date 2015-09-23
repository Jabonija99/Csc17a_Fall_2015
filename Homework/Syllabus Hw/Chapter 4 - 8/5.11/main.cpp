/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 23, 2015, 4:25 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout <<"Every fifth number(0-100): ";
    int j = 0;// counter for every fifth number
    
    //Increments through numbers 0 - 100
    for(int i = 0; i < 101; i++){
        j++; //Counts the numbers
        if(j == 5){ //If it is the fifth number
            cout <<i <<" "; //Output the number
            j = 0; //Reset the counter
        }
    }
    
    return 0;
}

