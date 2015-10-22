/* 
 * File:   Player.h
 * Author: rcc
 *
 * Created on October 14, 2015, 10:27 AM
 */

#include <string>

#include "Inv.h"
using namespace std;

#ifndef PLAYER_H
#define	PLAYER_H

class Player{
public:
    Player(); //Base constructor
    Player(string); //Constructor for new game
    
    string name();//Return's player name
    void setName(string); //set player name
    
    int getCHlth();//Returns player's current health
    int getMxHlth();//Returns player's max health
    void modHlth(int);//Modifies player's max health
    
    void modStmn(int); //Modifies player stamina
    int getStmna(); //Returns the player's stamina
    
    int attck(); //Sets the damage
    int dmged(int); //Calculates incoming damage
    void guard(int); //Set Player guard status
    bool blck(); //Flag for player guard
    bool stun(); // Return player stunned flag
    
    void modStat(int, int, int, int, int, int); //Modifies stats
    void seeStat(); //Displays stats
    int getStat(int); //Returns the indicated stat
    void setStat(int, int); //Set the indicated stat
    
    bool setExp(int); //Calculates added exp
    void lvlUp(); //Level up 
    int getLvl(); //Returns level
    
    bool dead(); //Returns death flag
    
    void createInv(); //Creates inventory for player
    void incInv(int); //Increases inventory size
    int sizeInv(); // Returns inventory size
    bool setItm(int); //Sets item to inventory
    int getItm(int); //Returns indicated item
    
private:
    void fillInv();
    void cls();
    
    string pName; //Player name
    int pMxHlth, pCHlth, pStmna; //Player max/current health and stamina
    int pStr, pDef, pAcc; //Combat stats
    int pDex, pInt, pLuc; //Social stats
    int pCExp, pMxExp, pLvl; //Current/max experience and level
    int pStun; //Stun chance
    
    //Flag for player death and guard
    bool pDead, pBlck;
    //Player inventory
    Inv *pInv;
};


#endif	/* PLAYER_H */

