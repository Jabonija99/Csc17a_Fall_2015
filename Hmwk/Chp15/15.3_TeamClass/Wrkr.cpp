/* 
 * File:   Wrkr.cpp
 * Author: Kauru99
 * 
 * Created on November 24, 2015, 7:08 PM
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Wrkr.h"

using namespace std;

Wrkr::Wrkr(){
    wShft = 1;
    wRate = 9.00;
}
Wrkr::Wrkr(int shft, float rate){
    wShft = shft;
    wRate = rate;
}
void Wrkr::stShft(int shft){
    wShft = shft;
}
void Wrkr::stRate(float rate){
    wRate = rate;
}
string Wrkr::gtShft(){
    if(wShft == 1){
        return "Day";
    }
    else if(wShft == 2){
        return "Night";
    }
    else{
        return "";
    }
}
float Wrkr::gtRate(){
    return wRate;
}

