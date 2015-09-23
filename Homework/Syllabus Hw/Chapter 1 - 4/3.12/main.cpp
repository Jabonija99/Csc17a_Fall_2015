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
 * 
 */
int main(int argc, char** argv) {
    char letter;
    
    cout <<"Enter a letter: ";
    cin >> letter;
    
    cout <<"Letter: " <<letter <<endl
            <<"ASCII code: " <<static_cast<int> (letter) <<endl;
    

    return 0;
}

