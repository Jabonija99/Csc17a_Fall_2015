/* 
 * File:   Emplye.h
 * Author: rcc
 *
 * Created on November 24, 2015, 11:46 AM
 */

#include <cstdlib>


using namespace std;

#ifndef EMPLYE_H
#define	EMPLYE_H

class Emplye{ //Employee class
private:
    string eName, eHDate; //Employee name and hire date
    int eNum; //Employee number 
public:
    Emplye(); //Base constructor
    Emplye(string, int, string); //Constructor with parameters
    
    void stName(string); //Set name
    void stNum(int); //Set employee number
    void stDate(string); //Set hire date
    
    string gtName(); //Returns name
    int gtNum(); //Returns employee number
    string gtDate(); //Returns date
};

#endif	/* EMPLYE_H */

