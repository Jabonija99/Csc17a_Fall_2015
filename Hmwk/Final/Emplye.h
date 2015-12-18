/* 
 * File:   Emplye.h
 * Author: Kauru99
 *
 * Created on December 17, 2015, 2:08 PM
 */

#ifndef EMPLYE_H
#define	EMPLYE_H

//Employee class
class Emplye{
private:
    //Calculates and returns tax
    float tax(float);       //Utility Procedure
    //Employee name
    char   eName[20];       //Property
    //Employee title
    char   eTitle[20];      //Property
    //Hourly rate
    float  eHrRate;         //Property
    //Hours worked
    int    eHrWork;     //Property
    //Gross Pay
    float  eGrssPay;        //Property
    //Net Pay
    float  eNetPay;          //Property
    
public:
    Emplye(char[],char[],float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure

};

#endif	/* EMPLYE_H */

