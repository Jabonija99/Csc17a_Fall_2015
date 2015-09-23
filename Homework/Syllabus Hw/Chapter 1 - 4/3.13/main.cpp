/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 22, 2015, 5:10 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int integer1, integer2;
    float result;
    integer1 = 19;
    integer2 = 2;
    
    result = integer1 / integer2;
    cout <<result <<endl;
    //Result = 9
    
    result = static_cast<float>(integer1)/ integer2;
    cout <<result <<endl;
    //Result = 9.5
    
    result = static_cast<float>(integer1 / integer2);
    cout <<result <<endl;
    //Result = 9
    
    return 0;
}

