/* 
 * File:   Player.h
 * Author: Kauru99
 *
 * Created on December 10, 2015, 9:41 PM
 */

#include <cstdlib> //General functions
#include <iostream> //Input/Output
#include <iomanip> //Input/Output Manipulation
#include <fstream> //Read/Write to files

using namespace std;

#include "Person.h" //Base person class
#include "Inv.h" //Inventory class

#ifndef PLAYER_H
#define	PLAYER_H

//Enumeration for stats
enum PStats{
    S_MHLTH, //Maximum health
    S_CHLTH, //Current health
    S_STMNA, //Stamina
    S_STR, //Strength
    S_DEF, //Defense
    S_ACC, //Accuracy
    S_DEX, //Dexterity
    S_INT, //Intelligence
    S_LUC, //Luck
    S_MEXP, //Maximum Experience
    S_CEXP, //Current Experience
    S_LVL, //Level
    S_SIZE //Stat size        
};

//Player class inherited from person class
class Player:public Person{
private:
    //Array of player stats
    int pStat[S_SIZE];
    
    //Incremented stun chance
    int pStun=0;
    //Flag for player death and guard
    bool pDead, pBlck;
    
    //Player inventory
    Inv *pInv;
    //Function to fill inventory
    void fillInv();
    //Checks current hp with max
    void chckhp();
    
public:
    //Base constructor
    Player();
    //Constructor with parameters
    Player(string);
    
    //Sets the indicated stat with the given value
    void stStat(int index, int val){pStat[index] = val;}
    //Modifies the indicated state with the given value
    void mStat(int index, int val);
    //Returns the indicated stat
    int gtStat(int index){return pStat[index];}
    //Returns the stat size
    int gtStSze(){return S_SIZE;}
    
    //Calculates and returns damage
    int attck();
    //Calculates and returns damage recieved
    int dmged(int);
    //Sets player block status
    void guard(bool flag){pBlck = flag;}
    //Returns block status
    bool blck(){return pBlck;}
    //Returns stun status
    bool stun();
    //Calculates heal and returns value
    int heal();
    //Returns death flag
    bool dead();
    
    //Calculates added exp
    bool setExp(int);
    
    //Creates inventory
    void crtInv(); 
    //Increases inventory size to the indicated value
    void incInv(int val){pInv->cap = val;}
    //Sets item to indicated slot *Does not adjust size*
    void setItm(int, int); 
    //Sets item to last inventory slot
    bool setItm(int);
    //Removes indicated item
    void remItm(int);
    
    //Sets the inventory capacity
    void stCap(int val){pInv->cap = val;}
    //Sets inventory size
    void stSze(int val){pInv->size = val;}
    
    
    //Returns indicated item
    int getItm(int); 
    //Returns the inventory size
    int invSze(){return pInv->size;}
    //Returns the cap
    int invCap(){return pInv->cap;}
    //Returns max size of inv
    int invMax(){return pInv->max;} 
};

#endif	/* PLAYER_H */

