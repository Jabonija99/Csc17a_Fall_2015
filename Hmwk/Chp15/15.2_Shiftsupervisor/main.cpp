/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 24, 2015, 10:33 AM
 */

#include <cstdlib>
#include <iostream>

#include "Emplye.h"

using namespace std;

class Sprvisr: public Emplye{
private:
    float sSal, sBonus; //Supervisor salary and bonus pay from production
public:
      Sprvisr();
      Sprvisr(float, float);
      
      void stSal(float);
      void stBonus(float);
      
      float gtSal();
      float gtBonus();
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    
    return 0;
}

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