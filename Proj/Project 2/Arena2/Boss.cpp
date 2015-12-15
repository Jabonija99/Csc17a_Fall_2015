/* 
 * File:   Boss.cpp
 * Author: Kauru99
 * 
 * Created on December 12, 2015, 10:36 PM
 */

#include "Boss.h"

Boss::Boss(){
    pName = "Arena Lord";
    
    //Set max health
    eStat[E_MHLTH] = 150;
    //Set current health
    eStat[E_CHLTH] = 150;
    //Set stamina
    eStat[E_STMNA] = 100;
    
    //Set strength
    eStat[E_STR] = 45;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 85;
    //Set dexterity
    eStat[E_DEX] = 30;
    //Set intelligence
    eStat[E_INT] = 50;
    //Set luck
    eStat[E_LUC] = 40;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

Boss::Boss(string name){
    pName = name;
    
    //Set max health
    eStat[E_MHLTH] = 150;
    //Set current health
    eStat[E_CHLTH] = 150;
    //Set stamina
    eStat[E_STMNA] = 100;
    
    //Set strength
    eStat[E_STR] = 45;
    //Set defense
    eStat[E_DEF] = 10;
    //Set accuracy
    eStat[E_ACC] = 85;
    //Set dexterity
    eStat[E_DEX] = 30;
    //Set intelligence
    eStat[E_INT] = 50;
    //Set luck
    eStat[E_LUC] = 40;
    
    //Set experience worth
    eStat[E_EXP] = 100;
}

