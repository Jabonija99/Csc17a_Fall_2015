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
    void modHlth(int);//Modifies player's max health
    
    int attck(); //Sets the damage
    int dmged(int eAtt); //Calculates incoming damage 
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int stat); //Returns the indicated stat
    
private:
    string pName; //Player name
    int pMxHlth, pHlth, pStmna; //Player max/current health and stamina
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
    pName = name; //Luck
    
    pMxHlth = 10; //Max Health
    pHlth = 10; //Current Health
    pStmna = 10; //Stamina
    
    pStr = 5; //Strength
    pDef = 5; //Defense
    pAcc = 60; //Accuracy
    pDex = 5; //Dexterity
    pInt = 5; //Intelligence
    pLuc = 5; //Luck
}

int Player::getHlth(){
    return pHlth; //Returns health
}

void Player::modHlth(int value){
    pMxHlth += value; //Sets max health
}

int Player::attck(){
    //Generates a random number from 0 - 100
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = pStr*0.7;
    //Generates a random number for hit/miss
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < pLuc){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > pAcc){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
}

int Player::dmged(int eAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = eAtt - pDef; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < pDex){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    pHlth -= dmg;
    
    //Return the amount of damage recieved
    return dmg;
}