/* 
 * File:   RItem.cpp
 * Author: rcc
 * 
 * Created on October 14, 2015, 9:52 AM
 */

#include "RItem.h"
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

RItem::RItem(string desc, int unts, float prce){
    modData(desc, unts, prce);
}
void RItem::modData(string desc, int unts, float prce){
    iDesc = desc;
    iUnts = unts;
    prce = roundf(prce * 100) / 100; 
    iPrce = prce;
}
string RItem::getDesc(){
    return iDesc;
}
int RItem::getUnts(){
    return iUnts;
}
float RItem::getPrce(){
    return iPrce;
}
