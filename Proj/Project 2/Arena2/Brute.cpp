/* 
 * File:   Brute.cpp
 * Author: Kauru99
 * 
 * Created on December 12, 2015, 10:10 PM
 */

#include "Enemy.h"
#include "Brute.h"

Brute::Brute(){
    pName = "Barbarian";
    
    //Set max health
    eStat[E_MHLTH] = 50;
    //Set current health
    eStat[E_CHLTH] = 50;
    //Set stamina
    eStat[E_STMNA] = 0;
    
    //Set strength
    eStat[E_STR] = 30;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 5;
    //Set intelligence
    eStat[E_INT] = 0;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

Brute::Brute(string name){
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 50;
    //Set current health
    eStat[E_CHLTH] = 50;
    //Set stamina
    eStat[E_STMNA] = 0;
    
    //Set strength
    eStat[E_STR] = 30;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 5;
    //Set intelligence
    eStat[E_INT] = 0;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

