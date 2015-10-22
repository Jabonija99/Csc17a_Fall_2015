/* 
 * File:   Enemy.h
 * Author: rcc
 *
 * Created on October 14, 2015, 10:46 AM
 */
#include <string>

#include "Player.h"

using namespace std;

#ifndef ENEMY_H
#define	ENEMY_H

class Enemy{
public:
    //Base constructor
    //Parameters:enemy name, mxHlth, stmna, str, def,acc,dex,int,luc, exp
    Enemy(string name, int, int, int, int ,int ,int, int, int, int);
    
    //Returns enemy name
    string name();
    
    //Returns max health
    int getMxHlth();
    //Returns current health
    int getCHlth();
    //Returns stamina
    int getStmna();
    
    //Sets damage 
    int attck(); 
    //Calculates and returns damage received. 
    int dmged(int pAtt); 
    //Set blocking status
    void guard(int);
    //Returns block flag
    bool blck();
    //Calculates and returns stun status
    bool stun();
    //Calculates health regen and returns value
    int heal();
    
    //Returns experience
    int exp();
    //Flag for death
    bool dead();
    //Enemy AI
    int choice(Player);
    
    
private:
    //Enemy name
    string eName;
    //Enemy max/current health and stamina
    int eMxHlth, eCHlth, eStmna;
    //Strength, defense, accuracy
    int eStr, eDef, eAcc;
    //Dexterity, intelligence, luck
    int eDex, eInt, eLuc;
    //Stun chance and experience amount
    int eStun, eExp;
    
    //Enemy death and block flag
    bool eDead, eBlck;
};

#endif	/* ENEMY_H */

