/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 1, 2015, 12:12 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//User Library
#include "Array.h"

//Global Constants

//Function Prototypes
Array *fillAry(int);
void prntAry(Array *, int);

/*
 * 
 */


int main(int argc, char** argv) {
    //Set random seed and size of the array
    srand(static_cast<unsigned int>(time(0)));
    int size = 100, perLine = 10;
    //Declare and size are ADT
    Array *array = fillAry(size);
    //Print results
    prntAry(array, perLine);
    //Destroy/Deallocate memory
    delete []array->data;
    delete array;
    
    //Exit
    return 0;
}

Array *fillAry(int n){
    //Check n
    if (n<=1)n=2;
    //Allocate Memory
    Array *a = new Array;
    a->size = n;
    //Alternate notation:
    //*a.size = n;
    a->data = new int[a->size];
    //Loop and fill with random numbers
    for (int indx = 0; indx < a->size; indx++){
        a->data[indx] = rand()%90+10;
        //(*a).data[indx] = rand()%90+10;
        //Convert the array to pointer notation
        //Teacher's "Attempt": ((*a).data+indx) = rand()%90+10
    }
    //Exit
    return a;
}

void prntAry(Array *a, int perLine){
    for(int indx = 0; indx < a->size; indx++){
        cout <<a->data[indx] <<" ";
        if(indx % perLine == (perLine - 1)){
            cout <<endl;
        }
    }
}