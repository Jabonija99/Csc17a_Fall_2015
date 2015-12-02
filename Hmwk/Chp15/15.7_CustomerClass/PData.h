/* 
 * File:   PData.h
 * Author: Kauru99
 *
 * Created on December 1, 2015, 7:43 PM
 */
#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef PDATA_H
#define	PDATA_H

//Personal data class
class PData{
private:
    //Last and first name, address, city, state
    string pLNme, pFNme, pAddrs, pCity, pSt;
    //Zip code and phone number
    int pZip, pPhne;
public:
    PData(); //Base constructor
    //Constructor with parameters
    PData(string, string, string, string, string, int, int);
    
    void stLNme(string); //Sets Last name
    void stFNme(string); //Sets First name
    void stAddr(string); //Sets Address
    void stCity(string); //Sets City
    void stSt(string); //Sets State
    void stZip(int); //Sets Zip
    void stPhne(int); //Sets Phone
    
    string gtLNme(); //Returns last name
    string gtFNme(); //Returns first name
    string gtAddr(); //Returns address
    string gtCity(); //Returns city
    string gtSt(); //Returns State
    int gtZip(); //Returns zip
    int gtPhne(); //Returns phone

};

#endif	/* PDATA_H */

