/* 
 * File:   Enemy.h
 * Author: rcc
 *
 * Created on October 14, 2015, 10:46 AM
 */
#include <string>

using namespace std;

#ifndef ENEMY_H
#define	ENEMY_H

class Enemy{
public:
    //Base constructor
    //Parameters:enemy name, mxHlth, stmna, str, def,acc,dex,int,luc
    Enemy(string name, int, int, int, int ,int ,int, int, int);
    
    int getCHlth(); //Returns current health
    
    int attck(); //Sets damage
    int dmged(int pAtt); //Calculates and returns damage
    
    
private:
    string eName;
    int eMxHlth, eCHlth, eStmna;
    int eStr, eDef, eAcc;
    int eDex, eInt, eLuc;
};

#endif	/* ENEMY_H */

