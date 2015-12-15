/* 
 * File:   Prob1Random.cpp
 * Author: Kauru99
 * 
 * Created on December 14, 2015, 7:26 PM
 */
#include <cstdlib>

#include "Prob1Random.h"

Prob1Random::Prob1Random(const char nSet, const char* set){
    //Sets the size for the set
    pNmSet = nSet;
    
    //Creates an array for the set
    pSet = new char[pNmSet];
    //Goes through the size of the array
    for(int i = 0; i < pNmSet; i++){
        //Copies contents to class set
            pSet[i] = set[i];
    }
    
    //Frequency of number array
    pFreq = new int[pNmSet];
    //Goes through the size of the array
    for(int i = 0; i < pNmSet; i++){
        //Assigns to 0
        pFreq[i] = 0;
    }
    
    //Set function call counter to 0
    pNmRand = 0;
}
Prob1Random::~Prob1Random(void){
    delete [] pSet;
    delete [] pFreq;
}
char Prob1Random::randFromSet(void){
    int nRand = rand()%pNmSet;
    pNmRand++;
    pFreq[nRand]++;
    return pSet[nRand];
}

