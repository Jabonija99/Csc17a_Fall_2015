/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 22, 2015, 10:12 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Player{
public:
    Player(); //Base constructor
    
    int getHlth();//Returns player's health
    void modHlth(int);//Modifies player's health
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int stat); //Returns the indicated stat
    
private:
    int pHlth, pStmna; //Player health and stamina
    int pStr, pDef, pAcc; //Combat stats
    int pDex, pInt, pLuc; //Social stats
    
};
/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

