/* 
 * File:   AccSve.h
 * Author: Kauru99
 *
 * Created on December 16, 2015, 5:18 PM
 */

#ifndef ACCSVE_H
#define	ACCSVE_H

//Bank account savings class
class AccSve{
private:
    float withdraw(float);               //Utility Procedure
    float deposit(float);                //Utility Procedure
    float aBalance;                       //Property
    int   aFreqWithdraw;                  //Property
    int   aFreqDeposit;                   //Property
    float pInt = 1;
    
public:
    AccSve(float);               //Constructor
    void  transaction(float);            //Procedure
    float total(float=0,int=0);	         //Savings Procedure
    float totalRecursive(float=0,int=0);
    void  toString();                    //Output Properties

};

#endif	/* ACCSVE_H */

