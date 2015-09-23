/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 23, 2015, 4:34 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void timesTen(int number);

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    
    cout <<"Enter a number: ";
    cin >> num;
    
    timesTen(num);
    return 0;
}

void timesTen(int number){
    int prod = number*10;
    cout << number <<" * 10 = " <<prod <<endl;
}
