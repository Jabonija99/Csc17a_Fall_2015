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

/*
 * 
 */
void newGme();
void loadGme();
void cls(); //Pseudo cls

int main(int argc, char** argv) {
    srand(time(0));
    //User input
    int userIn;
    //Flag for exit
    bool quit = false;
    
    /*
    string name;
    
    Player hero1("Jay");
    Player hero2("Stalin");
    Enemy slime("slime", 1,1,10,1,70,1,1,1);
    
    
    cout << "Slime receives "<<slime.dmged(hero1.attck()) <<" damage!" <<endl;
    cout << hero1.name() <<" receives " <<hero1.dmged(slime.attck()) <<" damage!"
            <<endl;
    Game one(hero1);
    hero1.modStat(12,34,56,78,90,12);
    cin >> name;
    one.save(hero1);
    one.load(hero2, name);
    hero2.seeStat();
    */
    
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
        cls();
    }while(!quit);
    
    
    return 0;
}

void newGme(){
    string name, ans;
    do{
        cls();
        cout << "Welcome to my rpg game!" <<endl
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
