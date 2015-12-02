/* 
 * File:   Wrkr.h
 * Author: Kauru99
 *
 * Created on November 24, 2015, 7:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"

using namespace std;

#ifndef WRKR_H
#define	WRKR_H

class Wrkr: public Emplye{
private:
    int wShft; //Shift type
    float wRate; //Rate of pay
public:
    Wrkr(); //Base constructor
    Wrkr(int, float); //Constructor with parameters
    
    void stShft(int); //Sets the shift type
    void stRate(float); //Sets the rate of pay
    
    string gtShft(); //Returns the shift type
    float gtRate(); //Returns the rate of pay
};

#endif	/* WRKR_H */

