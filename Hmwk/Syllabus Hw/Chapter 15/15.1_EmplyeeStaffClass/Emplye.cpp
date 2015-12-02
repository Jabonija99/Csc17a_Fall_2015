/* 
 * File:   Emplye.cpp
 * Author: rcc
 * 
 * Created on November 24, 2015, 11:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"


using namespace std;

Emplye::Emplye(){
    eName = ""; //Name
    eNum = 0; //Employee number
    eHDate = "01/23/4567"; //Hire date
}
Emplye::Emplye(string name, int num, string date){
    eName = name; //Name
    eNum = num; //Employee number
    eHDate = date; //Hire date
}
void Emplye::stName(string name){
    eName = name; //Assign user name
}
void Emplye::stNum(int num){
    eNum = num; //Assign user number
}
void Emplye::stDate(string date){
    eHDate = date; //Assign user date
}
string Emplye::gtName(){
    return eName; //Return name
}
int Emplye::gtNum(){ 
    return eNum; //Return employee number
}
string Emplye::gtDate(){
    return eHDate; //Return hire date
}
