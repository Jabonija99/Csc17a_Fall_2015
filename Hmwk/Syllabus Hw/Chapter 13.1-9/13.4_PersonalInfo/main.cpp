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
    PData();
    //Modify data
    void modData(string, string, int, int);
    //Outputs info
    void outInfo();
};

/*
 * 
 */
int main(int argc, char** argv) {
    //User name address
    string name, addrs;
    //User age phone and array size
    int age, phone, size = 3;
    //Array for Personal Data
    PData data[size];
    //Input validation
    bool inVal;
    
    for(int i = 0; i < size; i++){
        //do{
            //inVal = true;
            
            cout <<"Enter the following\n"
                    <<"Name: ";
            getline(cin, name);
            cout <<"Address: ";
            getline(cin, addrs);
            cout <<"Age: ";
            cin >> age;
            cout <<"Phone: ";
            cin >> phone;
        
            //if(age < 0){
             //   cout <<"Invalid input! Age(>0)" <<endl;
             //   inVal = false;
           // }
        
       // }while(!inVal);
        
        data[i].modData(name, addrs, age, phone);
    }
    
    for(int i = 0; i < size; i++){
        cout <<endl;
        data[i].outInfo();
    }
    
    
    
    return 0;
}

PData::PData(){
    
}
void PData::modData(string name, string addrs, int age, int phne){
    pName = name;
    pAddrs = addrs;
    pAge = age;
    pPhone = phne;
}
void PData::outInfo(){
    cout <<"Name: " <<pName <<endl
            <<"Address: " <<pAddrs <<endl
            <<"Age: " <<pAge <<endl
            <<"Phone: " <<pPhone <<endl;
}

