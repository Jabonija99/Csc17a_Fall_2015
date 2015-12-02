/* 
 * File:   Sprvisr.cpp
 * Author: Kauru99
 * 
 * Created on November 24, 2015, 7:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Sprvisr.h"

using namespace std;

Sprvisr::Sprvisr(){
    sSal = 9.00;
    sBonus = 0.00;
}
Sprvisr::Sprvisr(float sal, float bonus){
    sSal = sal;
    sBonus = bonus;
}
void Sprvisr::stSal(float sal){
    sSal = sal;
}
void Sprvisr::stBonus(float bonus){
    sBonus = bonus;
}
float Sprvisr::gtSal(){
    return sSal;
}
float Sprvisr::gtBonus(){
    return sBonus;
}

