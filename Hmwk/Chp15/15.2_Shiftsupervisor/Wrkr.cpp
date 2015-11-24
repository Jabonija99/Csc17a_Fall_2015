/* 
 * File:   Wrkr.cpp
 * Author: rcc
 * 
 * Created on November 24, 2015, 11:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Wrkr.h"


using namespace std;

Wrkr::Wrkr(){
    wShft = 1; //Default shift to 1
    wRate = 9.00; //Default rate to 9.00
}
Wrkr::Wrkr(int shft, float rate){
    wShft = shft; //Assign user defined shift(1 for day, 2 for night)
    wRate = rate; //Assign rate of pay
}
void Wrkr::stShft(int shft){
    wShft = shft; //Assign user shift
}
void Wrkr::stRate(float rate){
    wRate = rate; //Assign user rate of pay
}
int Wrkr::gtShft(){
    return wShft; //Return worker shift
}
float Wrkr::gtRate(){
    return wRate; //Return rate of pay
}

