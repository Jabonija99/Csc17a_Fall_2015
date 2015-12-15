/* 
 * File:   Mage.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 10:13 PM
 */

#include "Enemy.h"

using namespace std;


#ifndef MAGE_H
#define	MAGE_H

//Mage enemy class
class Mage : public Enemy {
public:
    //Base constructor
    Mage();
    //User named object
    Mage(string name);
    
    //Dialogue when attacking
    void dAtt(){cout <<pName <<" casts a bolt of lightning!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<" cast a magic bubble!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<"'s spell rebounds back!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" twitches in his electrified state!" <<endl;}
};

#endif	/* MAGE_H */

