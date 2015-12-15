/* 
 * File:   Enemy.cpp
 * Author: Kauru99
 * 
 * Created on December 11, 2015, 8:36 PM
 */

#include <cstdlib> //General functions
#include <iostream> //Input/Output
#include <iomanip> //Input/Output Manipulation
#include <fstream> //Read/Write to files

using namespace std;

#include "Person.h" //Base person class
#include "Player.h" //Player class
#include "Enemy.h" // Enemy class


Enemy::Enemy(){
    //Blank enemy name
    pName = "";
    
    //Set max health
    eStat[E_MHLTH] = 100;
    //Set current health
    eStat[E_CHLTH] = 100;
    //Set current stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 10;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 100;
    //Set dexterity
    eStat[E_DEX] = 10;
    //Set intelligence
    eStat[E_INT] = 10;
    //Set luck
    eStat[E_LUC] = 10;
    
    //Set experience worth
    eStat[E_EXP] = 100;
    
    //Set death flag as false
    eDead = false;
    //Set block flag as false
    eBlck = false;
    
    //Set stun to zero
    eStun = 0;
}
Enemy::Enemy(string name){
    //Assign name to enemy
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 100;
    //Set current health
    eStat[E_CHLTH] = 100;
    //Set stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 10;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 100;
    //Set dexterity
    eStat[E_DEX] = 10;
    //Set intelligence
    eStat[E_INT] = 10;
    //Set luck
    eStat[E_LUC] = 10;
    
    //Set experience worth
    eStat[E_EXP] = 100;
    
    //Set death flag as false
    eDead = false;
    //Set death flag as false
    eBlck = false;
    
    //Set stun incrementor to 0
    eStun = 0;
}
Enemy::Enemy(string name, int stats[]){
    //Assign name to Enemy
    pName = name;
    
    //Copies stat to enemy stat
    //Max health
    eStat[E_MHLTH] = stats[E_MHLTH];
    //Current health
    eStat[E_CHLTH] = stats[E_CHLTH];
    //Stamina
    eStat[E_STMNA] = stats[E_STMNA];
    
    //Strength
    eStat[E_STR] = stats[E_STR];
    //Defense
    eStat[E_DEF] = stats[E_DEF];
    //Accuracy
    eStat[E_ACC] = stats[E_ACC];
    //Dexterity
    eStat[E_DEX] = stats[E_DEX];
    //Intelligence
    eStat[E_INT] = stats[E_INT];
    //Luck
    eStat[E_LUC] = stats[E_LUC];
    
    //Experience
    eStat[E_EXP] = stats[E_EXP];
    
    //Set death flag to false
    eDead = false;
    //Set block flag to false
    eBlck = false;
    
    //Incrementor set to 0
    eStun = 0;
}
int Enemy::attck(){
    //Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = eStat[E_STR]*0.7;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < eStat[E_LUC]){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > eStat[E_ACC]){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
}
int Enemy::dmged(int pAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = pAtt - eStat[E_DEF]; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < eStat[E_DEX] * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    eStat[E_CHLTH] -= dmg;
    
    //If the health drops below zero
    if(eStat[E_CHLTH] < 0){
        //Set health to zero
        eStat[E_CHLTH] = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;

}
bool Enemy::stun(){
    //Increment stun chances
    eStun++;
    
    //Generate random number for stun chance
    int stun = rand()%101;
    
    //Minimum of 10% chance to get stunned
    if(stun < 10 + (eStun*10)){
        //Reset increased stun increment
        eStun = 0;
        //Return stunned flag
        return true;
    }
    else{
        //Return false stunned flag
        return false;
    }
}
int Enemy::heal(){
    //Calculates heal with intelligence
    int hl = 5 + (eStat[E_INT]*0.5);
    
    //Applies heal to current health
    eStat[E_CHLTH] += hl;
    
    //Return healing value
    return hl;
}
bool Enemy::dead(){
    //If the current health is less than 1
    if(eStat[E_CHLTH] < 1){
        //Flag enemy death
        eDead = true;
    }
    //Return death flag
    return eDead;
}
int Enemy::choice(Player hero, bool stun){
    //Enemy's chosen input
    int eIn;
    //Read player max/current health
    int pMHP = hero.gtStat(E_MHLTH), pCHP = hero.gtStat(E_CHLTH);
    
    //If current health is less than 10% of max hp
    if(eStat[E_CHLTH] < static_cast<float>(eStat[E_MHLTH])*0.10 &&
            //And if he cant kill the player in the next hit
            pCHP > eStat[E_STR]*0.5 && eStat[E_STMNA] > 0){
        //Select to heal
        eIn = 3;
        //Decrement stamina
        eStat[E_STMNA] -= 10;
    }
    //If player can be killed with a single blow
    else if(pCHP< eStat[E_STR]*0.5){
        //Attack and finish player 
        eIn = 1;
    }
    //If the player is stunned
    else if(stun){
        //Attack the vulerable player
        eIn = 1;
    }
    //If current health greater than 60%
    else if(eStat[E_CHLTH] > static_cast<float>(eStat[E_MHLTH])*0.60 &&
            //and player health grater than 30%
            pCHP > static_cast<float>(pMHP)*0.30){
        //Enemy is careful but still on the offensive
        
        //Roll ai
        eIn = rand()%101;
        
        //70% chance to throw an attack
        if(eIn <= 100 && eIn > 30){
            //Attack
            eIn = 1;
        }
        //30% chance to block
        else{
            //Guard
            eIn = 2;
        }
    }
    //If enemy is healthy (60%)
    else if (eStat[E_CHLTH] > static_cast<float>(eStat[E_MHLTH])*0.60 &&
            //and user is dying (30%)
            pCHP < static_cast<float>(hero.gtStat(pMHP))*0.30){
        //Enemy is aggressive and attacks more often
        
        //Roll ai
        eIn = rand()%101;
        
        //90% chance to throw an attack
        if(eIn <= 100 && eIn > 10){
            //Attack
            eIn = 1;
        }
        //10% chance to block
        else{
            //Guard
            eIn = 2;
        }
        
    }
    //If enemy is dying (30%)
    else if(eStat[E_CHLTH] < static_cast<float>(eStat[E_MHLTH])*0.30 &&
            //and user is healthy (60%)
            pCHP > static_cast<float>(pMHP)*0.60){
        //Plays defensively but still fights
        //Roll ai
        eIn = rand()%101;
        
        //30% chance to throw an attack
        if(eIn <= 100 &&  eIn > 70){
            //Attack
            eIn = 1;
        }
        //30% chance to heal
        else if(eIn <= 70 && eIn > 40 && eStat[E_STMNA] > 0){
            //Heal
            eIn = 3;
            //Decrement stamina
            eStat[E_STMNA]-=10;
        }
        //40% chance to block
        else{
            //Guard
            eIn = 2;
        }
    }
    //If enemy is dying (40%)
    else if(eStat[E_CHLTH] < static_cast<float>(eStat[E_MHLTH])*0.40 &&
            //and player is dying (40%)
            pCHP < static_cast<float>(pMHP)*0.40){
        //Enemy will continue fighting but heal if necessary
        
        
        //70% chance to throw an attack
        if(eIn <= 100 &&  eIn > 30){
            //Attack
            eIn = 1;
        }
        //20% chance to heal
        else if(eIn <= 30 && eIn > 0 && eStat[E_STMNA] > 0){
            //Heal
            eIn = 3;
            //Decrement stamina
            eStat[E_STMNA] -= 10;
        }
        //10% chance to block
        else{
            //Guard
            eIn = 2;
        }
    }
    //Default state
    else{
        
         //Roll ai
        eIn = rand()%101;
        
        //80% chance to throw an attack
        if(eIn <= 100 && eIn > 20){
            //Attack
            eIn = 1;
        }
        //20% chance to block
        else{
            //Guard
            eIn = 2;
        }
    
    }
    
    //Returns the enemy's choice
    return eIn;
}