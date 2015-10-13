/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 13, 2015, 12:06 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Personal Data class
class PData{
private:
    //Person name and address
    string pName, pAddrs;
    //Person age and phone
    int pAge, pPhone;
public:
    //Constructor
    PData(string, string, int, int);
    void modName(string);
    void modAddr(string);
    void modAge(int);
    void modPhne(int);
    //Outputs info
    void outInfo();
};

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}

PData::PData(string name, string addrs, int age, int phone){
    pName = name;
    pAddrs = addrs;
    pAge = age;
    pPhone = phone;
}
void PData::modName(string name){
    pName = name;
}
void PData::modAddr(string name){
    
}

