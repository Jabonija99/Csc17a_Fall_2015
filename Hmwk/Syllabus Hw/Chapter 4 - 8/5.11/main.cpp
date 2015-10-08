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
 * Population
 */
int main(int argc, char** argv) {
    //Number of organisms, number of days
    int numOrg, numDays;
    //Population increase
    float incPop;
    //Input validation
    bool inVal; 
    
    cout <<"Enter the following" <<endl
            <<"-------------------------" <<endl;
    do{
        //Set input validation to true
        inVal = true;
        
        //Prompt user for data
        cout <<"Starting number of organisms( > 1 ): ";
        cin >> numOrg;
        cout <<"Average daily population increase ( > 0%): ";
        cin >> incPop;
        cout <<"Number of days( > 0 ): ";
        cin >> numDays;
        
        //If the number of organisms is < 2
        if(numOrg < 2){
            //Prompt the user for invalid input
            cout <<"Invalid input! Starting number must be greater than 2." 
                    <<endl;
            //Flag invalid input
            inVal = false;
        }
       
        //If the population increase is < 0
        if(incPop < 0){
            //Prompt user
            cout <<"Invalid input! Population increase must be greater than 0." 
                    <<endl;
            //Flag invalid input
            inVal = false;
        }
        
        //if the number of days is < 1
        if(numDays < 1){
            //Prompt user
            cout <<"Invalid input! Number of days must be greater than 0."
                    <<endl;
            //Flag invalid input
            inVal = false;
        }
    
    }while(!inVal);
    
    //Convert percent to decimal
    incPop = incPop * .01;
    
    for(int i = 0; i < numDays; i++){
        numOrg += (static_cast<float>(numOrg)*incPop);
        cout  <<"(Day " << i+1  <<") Population: " <<numOrg <<endl;
    }
    
    
    
    return 0;
}

