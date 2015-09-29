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
    
    int getCHlth();//Returns player's current health
    int getMxHlth();//Returns player's max health
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
    pName = name; //Player Name
    
    pMxHlth = 10; //Max Health
    pHlth = 10; //Current Health
    pStmna = 10; //Stamina
    
    pStr = 5; //Strength
    pDef = 5; //Defense
    pAcc = 70; //Accuracy
    pDex = 5; //Dexterity
    pInt = 5; //Intelligence
    pLuc = 5; //Luck
}

int Player::getCHlth(){
    return pHlth; //Returns current health
}

int Player::getMxHlth(){
    return pMxHlth;
}

void Player::modHlth(int value){
    pMxHlth += value; //Sets max health
}

int Player::attck(){
    //Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = pStr*0.7;
    //Generates a random number for hit/miss %
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
    if(dodge < pDex * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    pHlth -= dmg;
    
    //Return the amount of damage recieved
    return dmg;
}

void Player::modStat(int str, int def, int acc, int dex, int intl, int luc){
    pStr += str; // Modifies strength
    pDef += def; // Defense
    pAcc += acc; // Accuracy
    pDex += dex; // Dexterity
    pInt += intl; // Intelligence
    pLuc += luc; //Luck
}

void Player::seeStat(){
    int quit = 0;
    do{
        cout <<"--------------------------------" <<endl
                <<"============ Stats =============" <<endl
                <<"--------------------------------" <<endl
                <<"Name: " <<pName <<endl
                <<"Str: " <<pStr <<endl
                <<"Def: " <<pDef <<endl
                <<"Acc: " <<pAcc <<endl
                <<"Dex: " <<pDex <<endl
                <<"Int: " <<pInt <<endl
                <<"Luc: " <<pLuc <<endl
                <<"--------------------------------" <<endl
                <<"================================" <<endl;
        cout <<"Enter -1 to quit: ";
        cin >> quit;
    }while(quit != -1);
}

int Player::getStat(int stat){
    switch(stat){
        case 1:
            return pStr;
            break;
        case 2:
            return pDef;
            break;
        case 3:
            return pAcc;
            break;
        case 4:
            return pDex;
            break;
        case 5:
            return pInt;
            break;
        case 6:
            return pLuc;
            break;
    }
}