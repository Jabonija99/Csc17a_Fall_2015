/* 
 * File:   Brute.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 10:10 PM
 */


#include "Enemy.h"

using namespace std;

#ifndef BRUTE_H
#define	BRUTE_H

//Brute enemy class
class Brute : public Enemy{
public:
    //Base constructor
    Brute();
    //User named object
    Brute(string name);
    
    //Dialogue when attacking
    void dAtt(){cout <<pName <<" swings a violent axe!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<" raises his axe to guard!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<"'s axe reflects off your shield!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" appears dumbfounded!" <<endl;}
};

#endif	/* BRUTE_H */

