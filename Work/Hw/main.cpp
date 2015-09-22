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
    Player(string); //Base constructor
    
    int getHlth();//Returns player's health
    void modHlth(int);//Modifies player's health
    
    int attck(int eDef); //Sets the damage
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int stat); //Returns the indicated stat
    
private:
    string pName; //Player name
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

Player::Player(string name){
    pName = name;
    
    pHlth = 10;
    pStmna = 10;
    
    pStr = 5;
    pDef = 5;
    pAcc = 60;
    pDex = 5;
    pInt = 5;
    pLuc = 5;
}

Player::getHlth(){
    return pHlth;
}

Player::modHlth(int value){
    pHlth += value;
}

Player::attck(int eDef){
    
}
