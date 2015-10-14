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

using namespace std;

class Game{
private:
    //Int for game completion and checkpoint for the player's location
    int gCmplte, gChckpt;
    //Save file
    ofstream gLoad;
    //Load File
    ifstream gSave;
    
public:
    Game(Player);
    
    void setCmplte();
    void setChckpt();
    void setPlyr(Player);
    
    void load();
    void save();
};

/*
 * 
 */
void cls(); //Pseudo cls

int main(int argc, char** argv) {
    srand(time(0));
    
    Player hero("Jay");
    Enemy slime("slime", 1,1,10,1,70,1,1,1);
    
    
    cout << "Slime receives "<<slime.dmged(hero.attck()) <<" damage!" <<endl;
    cout << hero.name() <<" receives " <<hero.dmged(slime.attck()) <<" damage!"
            <<endl;
    return 0;
}

void cls(){
    for(int i = 0; i < 10; i++){
        cout <<endl;
    }
}