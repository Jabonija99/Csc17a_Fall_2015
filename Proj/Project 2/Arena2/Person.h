/* 
 * File:   Person.h
 * Author: Kauru99
 *
 * Created on December 10, 2015, 9:15 PM
 */

#include <string>

using namespace std;

#ifndef PERSON_H
#define	PERSON_H

//Basic Person Class
class Person{
protected:
    //Person Name
    string pName;
public:
    //Base constructor
    Person(){pName="";}
    //Constructor with parameters
    Person(string name){pName = name;}
    //Assigns an array of characters to the name
    void stName(char name[]){pName = name;}
    //Returns the name
    string gtName(){return pName;}
};


#endif	/* PERSON_H */

