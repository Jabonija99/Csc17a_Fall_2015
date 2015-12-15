/* 
 * File:   Boss.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 10:36 PM
 */

#include "Enemy.h"

using namespace std;

#ifndef BOSS_H
#define	BOSS_H

class Boss : public Enemy{
public:
    //Base constructor
    Boss();
    //User named object
    Boss(string name);
    
    //Dialogue when attacking
    void dAtt()
    {cout <<pName <<"'s talons dig deep into your flesh!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<"'s demonic wings fold around him!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<" is repelled by the force of your defense!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" contemplates his next move!" <<endl;}

};

#endif	/* BOSS_H */

