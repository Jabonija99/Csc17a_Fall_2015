/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 17, 2015, 10:27 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Staff{
private:
    string sName, sDep, sTitle;
    int sID;
    
public:
    Staff();
    Staff(string, int);
    Staff(string, int, string, string);
    
    void stNme(string);
    void stID(int);
    void stDep(string);
    void stTtle(string);
    
    string gtNme();
    int gtID();
    string gtDep();
    string gtTtle();
    
};

/*
 * 
 */
int main(int argc, char** argv) {
    Staff membrs[3];
    string name, dep, ttle;
    int id;
    
    
    for(int i = 0; i < 3; i++){
        cout <<"Enter employee name: ";
        cin >> name;
        membrs[i].stNme(name);
        
        cout <<"Enter employee ID: ";
        cin >> id;
        membrs[i].stID(id);
        
        cout <<"Enter employee Department: ";
        cin >> dep;
        membrs[i].stDep(dep);
        
        cout <<"Enter employee ttle: ";
        cin >> ttle;
        membrs[i].stTtle(ttle);
        
        cout <<endl;
    }
    
    cout <<left <<"======================================================"
            <<endl
            <<setw(10) <<"Name" 
            <<setw(20) <<"ID Number"
            <<setw(20) <<"Department" 
            <<setw(20) <<"Position" <<endl
            <<"------------------------------------------------------" 
            <<endl;
    
    for(int i = 0; i < 3; i++){
        cout <<setw(10) <<membrs[i].gtNme() 
                <<setw(20) <<membrs[i].gtID()
                <<setw(20) <<membrs[i].gtDep() 
                <<setw(20) <<membrs[i].gtTtle()
                <<endl;
    }
    
    cout <<"------------------------------------------------------" <<endl;

    return 0;
}

Staff::Staff(){
    sName = "";
    sID = 0;
    sDep = "";
    sTitle = "";
}

Staff::Staff(string name, int id){
    sName = name;
    sID = id;
    sDep = "";
    sTitle = "";
}

Staff::Staff(string name, int id, string dep, string title){
    sName = name;
    sID = id;
    sDep = dep;
    sTitle = title;
}

void Staff::stNme(string name){
    sName = name;
}
void Staff::stID(int id){
    sID = id;
}
void Staff::stDep(string dep){
    sDep = dep;
}
void Staff::stTtle(string title){
    sTitle = title;
}

string Staff::gtNme(){
    return sName;
}
int Staff::gtID(){
    return sID;
}
string Staff::gtDep(){
    return sDep;
}
string Staff::gtTtle(){
    return sTitle;
}