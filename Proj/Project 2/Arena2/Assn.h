/* 
 * File:   Assn.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 10:29 PM
 */

#include "Enemy.h"

using namespace std;

#ifndef ASSN_H
#define	ASSN_H

class Assn : public Enemy{
public:
    //Base constructor
    Assn();
    //User named object
    Assn(string name);
    
    //Dialogue when attacking
    void dAtt()
    {cout <<pName <<" thrusts his daggers towards your blind spots!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<"'s shadows rise between you!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<" is knocked back by your shield!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" lies stunned on the floor!" <<endl;}

};

#endif	/* ASSN_H */

