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
    //Buffer string
    string bffr;
    //User age phone and array size
    int age, phone, size = 3;
    //Array for Personal Data
    PData data[size];
    //Input validation
    bool inVal;
    
    //Repeat for the number of data entries
    for(int i = 0; i < size; i++){
        do{
            //Set input validation to true
            inVal = true;
            
            //Prompt the user
            cout <<"Enter the following\n"
                    <<"Name: ";
            getline(cin, name);
            cout <<"Address: ";
            getline(cin, addrs);
            cout <<"Age: ";
            cin >> age;
            cout <<"Phone: ";
            cin >> phone;
            //Clear buffer
            getline(cin, bffr);
        
            //If the age is invalid
            if(age < 0){
                //Prompt the user
                cout <<"Invalid input! Age(>0)" <<endl;
                //Flag for false input
                inVal = false;
            }
        //Repeat if the input is false
        }while(!inVal);
        //Submit the data to the array when valid
        data[i].modData(name, addrs, age, phone);
    }
    
    cout <<endl <<"== Output ==" <<endl;
    //Loop for the size of the array
    for(int i = 0; i < size; i++){
        cout <<endl;
        //Output the data info
        data[i].outInfo();
    }
    
    return 0;
}

PData::PData(){
    
}
void PData::modData(string name, string addrs, int age, int phne){
    //Person name
    pName = name;
    //Address
    pAddrs = addrs;
    //Age
    pAge = age;
    //Phone
    pPhone = phne;
}
void PData::outInfo(){
    //Output data
    cout <<"Name: " <<pName <<endl
            <<"Address: " <<pAddrs <<endl
            <<"Age: " <<pAge <<endl
            <<"Phone: " <<pPhone <<endl;
}

