/* 
 * File:   Enemy.cpp
 * Author: rcc
 * 
 * Created on October 14, 2015, 10:46 AM
 */
#include <cstdlib>
#include <string>

#include "Enemy.h"
#include "Player.h"


using namespace std;

Enemy::Enemy(string name, int mxHlth, int stmna,  int str, int 
def, int acc, int dex, int intl, int luc, int exp){
    eName = name;
    
    eMxHlth = mxHlth;
    eCHlth = eMxHlth;
    eStmna = stmna;
    
    eStr = str;
    eDef = def;
    eAcc = acc;
    eDex = dex;
    eInt = intl;
    eLuc = luc;
    
    eExp = exp;
    
    eDead = false;
    eBlck = false;
    
    eStun = 0;
}

string Enemy::name(){
    return eName;
}

int Enemy::getMxHlth(){
    return eMxHlth;
}
int Enemy::getCHlth(){
    return eCHlth;
} 
int Enemy::getStmna(){
    return eStmna;
}

int Enemy::attck(){
//Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 70% of the strength
    unsigned short int dmg = eStr*0.7;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < eLuc){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > eAcc){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
} 
int Enemy::dmged(int pAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = pAtt - eDef; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < eDex * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    eCHlth -= dmg;
    
    //If the health drops below zero
    if(eCHlth < 0){
        //Set health to zero
        eCHlth = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;
}
void Enemy::guard(int val){
    if(val == 1){
        eBlck = true;
    }
    else{
        eBlck = false;
    }
}
bool Enemy::blck(){
    return eBlck;
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


int Enemy::exp(){
    //Returns experience value
    return eExp;
}
bool Enemy::dead(){
    if(eCHlth < 1){
        eDead = true;
    }
    return eDead;
}
int Enemy::heal(){
    //Calculates heal with intelligence
    int hl = 5 + (eInt*0.5);
    
    //Applies heal to current health
    eCHlth += hl;
    
    //Return healing value
    return hl;
}
int Enemy::choice(Player hero){
    //Enemy's chosen input
    int eIn;
    
    //If current health is less than 10% of max hp
    if(eCHlth < static_cast<float>(eMxHlth)*0.20 &&
            //And if he cant kill the player in the next hit
            hero.getCHlth() > eStr*0.5 && eStmna > 0){
        //Select to heal
        eIn = 3;
        //Decrement stamina
        eStmna -= 10;
    }
    //If player can be killed with a single blow
    else if(hero.getCHlth() < eStr*0.5){
        //Attack and finish player 
        eIn = 1;
    }
    //If current health greater than 60%
    else if(eCHlth > static_cast<float>(eMxHlth)*0.60 &&
            //and player health grater tna 30%
            hero.getCHlth() > static_cast<float>(hero.getMxHlth())*0.30){
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
    else if (eCHlth > static_cast<float>(eMxHlth)*0.60 &&
            //and user is dying (30%)
            hero.getCHlth() < static_cast<float>(hero.getMxHlth())*0.30){
        //enemy is aggressive and attacks more often
        
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
    else if(eCHlth < static_cast<float>(eMxHlth)*0.30 &&
            //and user is healthy (60%)
            hero.getCHlth() > static_cast<float>(hero.getMxHlth())*0.60){
        //Plays defensively but still fights
        //Roll ai
        eIn = rand()%101;
        
        //20% chance to throw an attack
        if(eIn <= 100 &&  eIn > 90){
            //Attack
            eIn = 1;
        }
        //30% chance to heal
        else if(eIn <= 90 && eIn > 60 && eStmna > 0){
            //Heal
            eIn = 3;
            //Decrement stamina
            eStmna-=10;
        }
        //60% chance to block
        else{
            //Guard
            eIn = 2;
        }
    }
    //If enemy is dying (40%)
    else if(eCHlth < static_cast<float>(eMxHlth)*0.40 &&
            //and player is dying (40%)
            hero.getCHlth() < static_cast<float>(hero.getMxHlth())*0.40){
        //Enemy will continue fighting but heal if necessary
        
        
        //70% chance to throw an attack
        if(eIn <= 100 &&  eIn > 30){
            //Attack
            eIn = 1;
        }
        //20% chance to heal
        else if(eIn <= 30 && eIn > 0 && eStmna > 0){
            //Heal
            eIn = 3;
            //Decrement stamina
            eStmna -= 10;
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
