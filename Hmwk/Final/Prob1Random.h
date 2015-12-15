/* 
 * File:   Prob1Random.h
 * Author: Kauru99
 *
 * Created on December 14, 2015, 7:26 PM
 */



#ifndef PROB1RANDOM_H
#define	PROB1RANDOM_H

class Prob1Random{
private:
    char *pSet;      //The set of numbers to draw random numbers from
    char  pNmSet;     //The number of variables in the sequence
    int  *pFreq;     //Frequency of all the random numbers returned
    int   pNmRand;  //The total number of times the random number function is called
public:
    Prob1Random(const char,const char *); //Constructor
    ~Prob1Random(void);                   //Destructor
    char randFromSet(void);              //Returns a random number from the set
    int *getFreq(void) const             //Returns the frequency histogram
        {return pFreq;}               
    char *getSet(void) const            //Returns the set used
        {return pSet;}
    int getNumRand(void) const       //Gets the number of times randFromSet has
        {return pNmRand;}            //been called
};
#endif	/* PROB1RANDOM_H */

