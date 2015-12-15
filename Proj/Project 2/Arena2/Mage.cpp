/* 
 * File:   Mage.cpp
 * Author: Kauru99
 * 
 * Created on December 12, 2015, 10:13 PM
 */

#include "Mage.h"

Mage::Mage(){
    pName = "Mystic";
    
    //Set max health
    eStat[E_MHLTH] = 70;
    //Set current health
    eStat[E_CHLTH] = 70;
    //Set stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 30;
    //Set defense
    eStat[E_DEF] = 5;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 3;
    //Set intelligence
    eStat[E_INT] = 50;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

Mage::Mage(string name){
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 70;
    //Set current health
    eStat[E_CHLTH] = 70;
    //Set stamina
    eStat[E_STMNA] = 50;
    
    //Set strength
    eStat[E_STR] = 30;
    //Set defense
    eStat[E_DEF] = 5;
    //Set accuracy
    eStat[E_ACC] = 80;
    //Set dexterity
    eStat[E_DEX] = 3;
    //Set intelligence
    eStat[E_INT] = 50;
    //Set luck
    eStat[E_LUC] = 5;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

