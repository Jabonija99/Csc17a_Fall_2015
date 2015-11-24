/* 
 * File:   Wrkr.h
 * Author: rcc
 *
 * Created on November 24, 2015, 11:47 AM
 */

#ifndef WRKR_H
#define	WRKR_H


class Wrkr: public Emplye{
private:
    int wShft; //Worker shift
    float wRate; //Worker rate of pay
    
public:
    Wrkr(); //Base constructor
    Wrkr(int, float); //Constructor with arguments
    
    void stShft(int); //Set shift
    void stRate(float); //Set rate of pay
    
    int gtShft(); //Return shift
    float gtRate(); //Return rate of pay
    
    
};

#endif	/* WRKR_H */

