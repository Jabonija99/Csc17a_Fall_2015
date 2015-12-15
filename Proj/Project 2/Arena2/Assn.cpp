/* 
 * File:   Assn.cpp
 * Author: Kauru99
 * 
 * Created on December 12, 2015, 10:29 PM
 */

#include "Assn.h"

Assn::Assn(){
    pName = "Assassin";
    
    //Set max health
    eStat[E_MHLTH] = 120;
    //Set current health
    eStat[E_CHLTH] = 120;
    //Set stamina
    eStat[E_STMNA] = 80;
    
    //Set strength
    eStat[E_STR] = 40;
    //Set defense
    eStat[E_DEF] = 20;
    //Set accuracy
    eStat[E_ACC] = 90;
    //Set dexterity
    eStat[E_DEX] = 30;
    //Set intelligence
    eStat[E_INT] = 20;
    //Set luck
    eStat[E_LUC] = 30;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

Assn::Assn(string name){
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 120;
    //Set current health
    eStat[E_CHLTH] = 120;
    //Set stamina
    eStat[E_STMNA] = 80;
    
    //Set strength
    eStat[E_STR] = 40;
    //Set defense
    eStat[E_DEF] = 20;
    //Set accuracy
    eStat[E_ACC] = 90;
    //Set dexterity
    eStat[E_DEX] = 30;
    //Set intelligence
    eStat[E_INT] = 20;
    //Set luck
    eStat[E_LUC] = 30;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

