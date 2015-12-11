/* 
 * File:   Player.cpp
 * Author: Kauru99
 * 
 * Created on December 10, 2015, 9:41 PM
 */

#include <cstdlib> //General functions
#include <iostream> //Input/Output
#include <iomanip> //Input/Output Manipulation
#include <fstream> //Read/Write to files

using namespace std;

#include "Person.h" //Base person class
#include "Player.h"


Player::Player(){
    //Blank player name
    pName = "";
    
    //Sets Maximum health
    pStat[S_MHLTH] = 100;
    //Sets current health
    pStat[S_CHLTH] = 100;
    //Sets stamina
    pStat[S_STMNA] = 20;
    
    //Sets strength
    pStat[S_STR] = 20;
    //Sets defense
    pStat[S_DEF] = 5;
    //Sets accuracy
    pStat[S_ACC] = 85;
    //Sets dexterity
    pStat[S_DEX] = 10;
    //Sets intelligence
    pStat[S_INT] = 10;
    //Sets luck
    pStat[S_LUC] = 10;
    
    //Sets maxiumum exp
    pStat[S_MEXP] = 100;
    //Sets current exp
    pStat[S_CEXP] = 0;
    //Sets player level
    pStat[S_LVL] = 1;
    
    //Sets death flag
    pDead = false;
    //Sets block flag
    pBlck = false;
}
Player::Player(string name){
    //Blank player name
    pName = name;
    
    //Sets Maximum health
    pStat[S_MHLTH] = 100;
    //Sets current health
    pStat[S_CHLTH] = 100;
    //Sets stamina
    pStat[S_STMNA] = 20;
    
    //Sets strength
    pStat[S_STR] = 20;
    //Sets defense
    pStat[S_DEF] = 5;
    //Sets accuracy
    pStat[S_ACC] = 85;
    //Sets dexterity
    pStat[S_DEX] = 10;
    //Sets intelligence
    pStat[S_INT] = 10;
    //Sets luck
    pStat[S_LUC] = 10;
    
    //Sets maxiumum exp
    pStat[S_MEXP] = 100;
    //Sets current exp
    pStat[S_CEXP] = 0;
    //Sets player level
    pStat[S_LVL] = 1;
    
    //Sets death flag
    pDead = false;
    //Sets block flag
    pBlck = false;
}
int Player::attck(){
    //Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 80% of the strength
    unsigned short int dmg = pStat[S_STR]*0.8;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < pStat[S_LUC]){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > pStat[S_ACC]){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;

}
int Player::dmged(int eAtt){
int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = eAtt - pStat[S_DEF]; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < pStat[S_DEX] * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    pStat[S_CHLTH] -= dmg;
    
     //If the health drops below zero
    if(pStat[S_CHLTH] < 0){
        //Set health to zero
        pStat[S_CHLTH] = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;
}
bool Player::stun(){
    //Increment stun chances
    pStun++;
    
    //Generate random number for stun chance
    int stun = rand()%101;
    
    //Minimum of 10% chance to get stunned
    if(stun < 10 + (pStun*10)){
        //Reset increased stun increment
        pStun = 0;
        //Return stunned flag
        return true;
    }
    else{
        //Return false stunned flag
        return false;
    }
}
int Player::heal(){
     if(pStat[S_STMNA] > 10){
        //Calculates heal with intelligence
        int hl = 5 + (pStat[S_INT]*0.5);

        //Applies heal to current health
        pStat[S_CHLTH] += hl;
        
        //Decrement stamina
        pStat[S_STMNA] -= 10;
        
        //Return healing value
        return hl;
    }
    else{
        return 0;
    }
}
bool Player::dead(){
    //If the player's health is below 1
    if(pStat[S_CHLTH] < 1){
        //Flag player death
        pDead = true;
    }
    //Return death flag
    return pDead;
}
bool Player::setExp(int exp){
    //Adds experience to current exp
    pStat[S_CEXP] += exp;
    
    //If the current exp reaches the max exp
    if(pStat[S_CEXP] >= pStat[S_MEXP]){
        //Calculates the remaining difference to current exp
        pStat[S_CEXP] -= pStat[S_MEXP];
        //Returns true for level up
        return true;
    }
    //Returns false for level up
    return false;
}

