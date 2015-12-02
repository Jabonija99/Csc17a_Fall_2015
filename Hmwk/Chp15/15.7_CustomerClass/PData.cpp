/* 
 * File:   PData.cpp
 * Author: Kauru99
 * 
 * Created on December 1, 2015, 7:43 PM
 */


#include <cstdlib>
#include <iostream>
#include "PData.h"

using namespace std;

PData::PData(){
    pLNme = ""; //Last name
    pFNme = ""; //First name
    pAddrs = ""; //Address
    pCity = ""; //City
    pSt = ""; //State
    pZip = 00000; //Zip
    pPhne = 1112223333; //Phone
}
PData::PData(string lNme, string fNme, string addr, string city, string st, 
        int zip, int phne){
    pLNme = lNme; //Last name
    pFNme = fNme; //First name
    pAddrs = addr; //Address
    pCity = city; //City 
    pSt = st; //State
    pZip = zip; //Zip
    pPhne = phne; //Phone
}
void PData::stLNme(string lNme){
    pLNme = lNme; //Sets last name
}
void PData::stFNme(string fNme){
    pFNme = fNme; //Sets first name
}
void PData::stAddr(string addrs){
    pAddrs = addrs; //Sets address
}
void PData::stCity(string city){
    pCity = city; //Sets city
}
void PData::stSt(string st){
    pSt = st; //Sets State
}
void PData::stZip(int zip){
    pZip = zip; //Sets zip code
}
void PData::stPhne(int phne){
    pPhne = phne; //Sets phone
}
string PData::gtLNme(){
    return pLNme; //Returns last name
}
string PData::gtFNme(){
    return pFNme; //Returns first name
}
string PData::gtAddr(){
    return pAddrs; //Returns address
}
string PData::gtCity(){
    return pCity; //Returns city
}
string PData::gtSt(){
    return pSt; //Returns State
}
int PData::gtZip(){
    return pZip; //Returns zip
}
int PData::gtPhne(){
    return pPhne; //Returns phone
}

