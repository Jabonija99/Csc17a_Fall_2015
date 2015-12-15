/* 
 * File:   Enemy.h
 * Author: Kauru99
 *
 * Created on December 11, 2015, 8:36 PM
 */

#include <cstdlib> //General functions
#include <iostream> //Input/Output
#include <iomanip> //Input/Output Manipulation
#include <fstream> //Read/Write to files

using namespace std;

#include "Person.h" //Base person class
#include "Player.h" //Player class

#ifndef ENEMY_H
#define	ENEMY_H

//Enumeration of Stats
enum EStats{
    E_MHLTH, //Max health
    E_CHLTH, //Current health
    E_STMNA, //Stamina
    E_STR, //Strength
    E_DEF, //Defense
    E_ACC, //Accuracy
    E_DEX, //Dexterity
    E_INT, //Intelligence
    E_LUC, //Luck
    E_EXP, //Experience worth
    E_SIZE //Stat size
};

//Enemy class inherited from person class
class Enemy: public Person{
protected:
    //Stat array
    int eStat[E_SIZE];
    //Incremented stun chance
    int eStun;
    //Death flag and block flag
    bool eDead, eBlck;
public:
    //Base constructor
    Enemy();
    //Constructor takes name
    Enemy(string);
    //Constructor takes name and stats
    Enemy(string, int[]);
    
    //Sets indicated stat by a value
    void stStat(int index, int val){eStat[index]=val;}
    //Modifies the indicated stat by a value
    void mStat(int index, int val){eStat[index] += val;}
    //Returns indicated stat
    int gtStat(int index){return eStat[index];}
    
    //Calculates and returns damage
    int attck();
    //Calculates and returns damage received
    int dmged(int);
    //Set blocking status
    void guard(bool flag){eBlck = flag;}
    //Returns blocking status
    bool blck(){return eBlck;}
    //Calculates and returns stun status
    bool stun();
    
    //Calculates and returns health healed
    int heal();
    //Returns death flag
    bool dead();
    //Enemy AI
    int choice(Player, bool);
    
    //Dialogue when attacking
    void dAtt(){cout <<pName <<" attacks!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<" defends!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<" got stunned!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" is stunned!" <<endl;}
    
};


#endif	/* ENEMY_H */

