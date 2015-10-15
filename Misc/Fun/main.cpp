/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 22, 2015, 10:12 AM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

//User Libraries
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

using namespace std;

class Area{
private:
    //Name of the area and description
    string aName, aDesc;
    //Type of terrain
    int aTerrn;
public:
    //Constructors
    Area();
    Area(string, string, int);
    
    //Set name of the area
    void setName(string);
    //Set description of the area
    void setDesc(string);
    //Set terrain type
    void setTerr(int);
    
    //Returns the name of the area
    string name(); 
    //Returns the description of the area
    string desc();
    //Returns the type of terrain
    int terrn();
    //Output the type of terrain
    void outTer();
    
    
};

/*
 * 
 */
void newGme();
void loadGme();
void cls(); //Pseudo cls

int main(int argc, char** argv) {
    /*
    srand(time(0));
    //User input
    int userIn;
    //Flag for exit
    bool quit = false;
  
    do{
        cout <<"======================" <<endl
                <<"       RPG Game" <<endl
                <<"======================" <<endl
                <<"       Menu" <<endl
                <<"----------------------" <<endl
                <<"1] New Game" <<endl
                <<"2] Load Game" <<endl
                <<"3] Quit" <<endl
                <<"----------------------" <<endl
                <<"Make your choice: ";
        cin >> userIn;

        switch (userIn){
            case 1:
                newGme();
                break;
            case 2:
                loadGme();
                break;
            case 3:
                quit = true;
                break;
            default:
                cout <<"Invalid input!" <<endl;
                break;
        }
        
    }while(!quit);
    */
    
    return 0;
}

Area::Area(){
    aName = "New Area";
    aDesc = " ";
    aTerrn = 0;
}
Area::Area(string name, string desc, int terr){
    aName = name;
    aDesc = desc;
    aTerrn = terr;
}
void Area::setName(string name){
    aName = name;
}
void Area::setDesc(string desc){
    aDesc = desc;
}
void Area::setTerr(int val){
    aTerrn = val;
}
string Area::name(){
    return aName;
}
string Area::desc(){
    return aDesc;
}
int Area::terrn(){
    return aTerrn;
}
void Area::outTer(){
    switch(aTerrn){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
}


void newGme(){
    string name, ans;
    do{
        cls();
         cout <<"----------------------" <<endl
            <<"       New Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
        cin >> name;
    
        cout <<"Name: " <<name <<endl
                <<"Confirm (Y/N)? ";
        cin >> ans;
    
    }while(tolower(ans[0]) != 'y');
    
    Player hero(name);
    Game rpg;
    if(!rpg.save(hero)){
        cout <<"Error: Failed to create save file!" <<endl;
    }
}
void loadGme(){
    cls();
    string name;
    cout <<"----------------------" <<endl
            <<"     Load Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
    cin >> name;
    
    Player hero;
    Game rpg;
    if(!rpg.load(hero, name)){
        cout <<"Error: File does not exist!" <<endl;
    }
    else{
        cout <<"Load successful"<<endl;
        
        
    }
}

void cls(){
    for(int i = 0; i < 10; i++){
        cout <<endl;
    }
}
