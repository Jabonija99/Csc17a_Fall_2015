/* 
 * File:   main.cpp
 * Author: Jarone Jabonillo
 *
 * Created on October 15, 2015, 11:20 AM
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//User libraries

//Global constants

//Function prototypes
char suit(char);
char numVal(char);

/*
 * Purpose: Creating our first object oriented program
 */
int main(int argc, char** argv) {
    //Declare variables
    //char aSuit[4] ={'S', 'H', 'C', 'D'};
   
    
    /**
    //Loop on all potential 52 card
    cout <<"1st method" <<endl;
    for(int i = 1; i <  52; i++){
        if(i <= 13)suit = 'S';
        else if(i <= 26)suit = 'H';
        else if(i <=39)suit ='C';
        else suit = 'D';
        cout <<"Card number = " <<i <<"Suit = " <<suit <<endl;
        
    }
    
    cout <<"2nd method" <<endl;
    for(int i = 1; i <  52; i++){
        suit = aSuit[i-1/13];
        cout <<"Card number = " <<i <<"Suit = " <<suit(i) <<endl;
    }
     */
    for(int i = 1; i <  52; i++){
        
        
        cout <<"Card number = " <<i <<" Suit = " <<suit(i)
                <<" Numerical value = " <<static_cast<int>(numVal(i)) <<endl;
    }
   
    return 0;
}

char suit(char n){
    //Declare suit array
    char aSuit[4] ={'S', 'H', 'C', 'D'};
    if(n<1 || n>52) return 'X';
    return aSuit[(n-1)/13];
}

char numVal(char n){
    if(n<1 || n>52) return 0;
    char numVal = (n-1)%13 + 1;
    if(numVal > 10)numVal = 10;
    return numVal;
}