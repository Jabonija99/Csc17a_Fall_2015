/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 15, 2015, 5:53 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

int *findMode(int array[], int aSize, int &modSize);
/*** Finds the mode(s) of an array then inputs it into a dynamic array
 * @param array - an array of random numbers
 * @param aSize - the size of the array
 * returns the pointer of mode(s)*/
void fillArray(int[], int); //Fills the array with random values
void outArray(int *, int); //Outputs the array

/*
 * 
 */

int main(int argc, char** argv) {
    int aSize = 20; //Size of the array of numbers
    int modSize = 0; //Size of the array of modes 
    int numbers[aSize]; //Array of numbers
    
    srand(time(0)); //Timer for true random
    
    fillArray(numbers, aSize); //Fills the array with random numbers
    
    int *mode = findMode(numbers, aSize, modSize); 
        //Assigns the pointer to mode
   
    //Output the array and it's values
    cout <<"Array: ";
    outArray(numbers, aSize);
   
    cout <<"Mode: ";
    //If there is no mode
    if(modSize == 0){
        //Output 'no mode' message
        cout <<"No mode found!" <<endl;
    }
    else{
        //Output mode and its values
        outArray(mode, modSize);
    }
    //Delete the new pointer
    delete []mode;
    
    return 0;
}

int *findMode(int array[], int aSize, int &modSize){
    int cap = 10; //Capacity for the mode array
    int *mode = new int[cap]; //Pointer for mode
    bool dup = false; //Flag for duplicates
    int maxMode = 1, k = 0; //Maximum count for mode and the counter
   
    //Searches the array
    for(int i = 0; i < aSize; i++){
        //Search the array again to compare values
        for(int j = 0; j < aSize; j++){ 
            //If the values match and are not of the same address
            if(array[i] == array [j] && i != j){
                //Increment the counter
                k++;
            }
        }
        
        //Searches the mode array
        for(int j = 0; j < modSize; j++){
            //If the number exists in mode
            if(array[i] == mode[j]){
                //Flag for duplicate
                dup = true;
            }
        }
        
        //If it is not a duplicate and the number count is > the maximum mode
        if(!dup && k > maxMode){
            maxMode = k; //Set the maximum mode to the current count
            modSize = 0; //Reset the size, "deleting" any current numbers
            mode[modSize] = array[i]; //Assigns the value into the mode array
            modSize++; //Increment the size
        }
        //If the count is the same as the maximum Mode
        else if(!dup && k == maxMode){
            mode[modSize] = array[i]; //Add the number into the mode array
            modSize++; //Increment the size
        }
        
        k = 0; //Reset the counter
        dup = false; //Reset the duplicate flag
    }
    
    return mode; //Returns the pointer for modes
}

void fillArray(int array[], int size){
    //Goes through the entire array
    for (int i = 0; i < size; i++){
        array[i] = rand()%11; //Assigns random numbers(0~10) to the array
    }
}

void outArray(int *dArray, int size){
    //Goes through the entire array
    for(int i = 0; i < size; i ++){
        cout << dArray[i] <<" "; //Outputs it's values
    }
    cout <<endl;
}

