/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 8, 2015, 12:00 PM
 */

#include <cstdlib>
#include "SimpleVector.h"

using namespace std;

/*
 * Create function member for SimpleVector that pushes in a new value
 */
int main(int argc, char** argv) {
    int nUsr; //User number
    
    //Prompt for ending factorial
    cout <<"Factorials" <<endl
            <<"Enter a stopping value: ";
    cin >> nUsr;
    
    SimpleVector<int> vFctrl[nUsr]; //create array of factorials
    
    //calculate factorials and stores it into the vector
    for(int i = 0; i < vFctrl[i].size(); i++){
        int fVal; //temporarily stores a factorial value
        fVal = (i*(i+1))/2;
        vFctrl[i] = fVal;
    }
    
    //Output contents
    for(int i = 0; i < vFctrl[i].size(); i++){
        cout <<vFctrl[i].getElementAt(i);
    }
    
    

    return 0;
}

