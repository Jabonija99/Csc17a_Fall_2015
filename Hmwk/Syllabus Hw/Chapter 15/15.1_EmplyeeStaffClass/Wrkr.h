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
    int wShft;
    float wRate;
public:
    Wrkr();
    Wrkr(int, float);
    
    void stShft(int);
    void stRate(float);
    
    int gtShft();
    float gtRate();
};

#endif	/* WRKR_H */

