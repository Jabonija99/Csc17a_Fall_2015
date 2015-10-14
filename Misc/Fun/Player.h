/* 
 * File:   Player.h
 * Author: rcc
 *
 * Created on October 14, 2015, 10:27 AM
 */

#include <string>
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
public:
    Player(string); //Base constructor
    
    string name();//Return's player name
    
    int getCHlth();//Returns player's current health
    int getMxHlth();//Returns player's max health
    void modHlth(int);//Modifies player's max health
    
    int attck(); //Sets the damage
    int dmged(int eAtt); //Calculates incoming damage 
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int stat); //Returns the indicated stat
    
    bool setExp(int exp); //Calculates added exp
    void lvlUp(); //Level up 
    int getLvl(); //Returns level
    
private:
    void cls();
    
    string pName; //Player name
    int pMxHlth, pCHlth, pStmna; //Player max/current health and stamina
    int pStr, pDef, pAcc; //Combat stats
    int pDex, pInt, pLuc; //Social stats
    int pCExp, pMxExp, pLvl; //Current/max experience and level
};


#endif	/* PLAYER_H */

