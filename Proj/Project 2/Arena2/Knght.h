/* 
 * File:   Knght.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 10:20 PM
 */
#include "Enemy.h"

using namespace std;

#ifndef KNGHT_H
#define	KNGHT_H

//Knight enemy class
class Knght : public Enemy {
public:
    //Base constructor
    Knght();
    //User named object
    Knght(string name);
    
    //Dialogue when attacking
    void dAtt(){cout <<pName <<" makes precise swings with his sword!" <<endl;}
    //Dialogue when defending
    void dDef(){cout <<pName <<" raises his mighty shield!" <<endl;}
    //Dialogue when getting stunned
    void dStn(){cout <<pName <<"'s sword is parried!" <<endl;}
    //Dialogue when stunned
    void dStnnd(){cout <<pName <<" stands dazed in his armor!" <<endl;}

};

#endif	/* KNGHT_H */

