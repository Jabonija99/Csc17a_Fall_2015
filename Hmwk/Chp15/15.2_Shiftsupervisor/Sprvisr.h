/* 
 * File:   Sprvisr.h
 * Author: Kauru99
 *
 * Created on November 24, 2015, 7:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"

using namespace std;

#ifndef SPRVISR_H
#define	SPRVISR_H

//Supervisor class
class Sprvisr: public Emplye{
private:
    float sSal, sBonus; //Supervisor salary and bonus pay from production
public:
    Sprvisr(); //Base constructor
    Sprvisr(float, float); //User defined object

    void stSal(float); //Assigns new value to salary
    void stBonus(float); //Assigns new value to bonus

    float gtSal(); //Returns the salary
    float gtBonus(); //Returns the bonus
};

#endif	/* SPRVISR_H */

