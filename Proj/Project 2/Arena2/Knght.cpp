/* 
 * File:   Knght.cpp
 * Author: Kauru99
 * 
 * Created on December 12, 2015, 10:20 PM
 */

#include "Knght.h"

Knght::Knght(){
    pName = "Great Knight";
    
    //Set max health
    eStat[E_MHLTH] = 110;
    //Set current health
    eStat[E_CHLTH] = 110;
    //Set stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 35;
    //Set defense
    eStat[E_DEF] = 20;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 2;
    //Set intelligence
    eStat[E_INT] = 10;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

Knght::Knght(string name){
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 110;
    //Set current health
    eStat[E_CHLTH] = 110;
    //Set stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 35;
    //Set defense
    eStat[E_DEF] = 20;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 2;
    //Set intelligence
    eStat[E_INT] = 10;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

