/* 
 * File:   Game.h
 * Author: Kauru99
 *
 * Created on October 14, 2015, 9:15 PM
 */

#include <string>
#include <fstream>
#include "Player.h"

//using namespace std;

#ifndef GAME_H
#define	GAME_H

class Game{
private:
    //Int for game completion and checkpoint for the player's location
    int gCmplte, gChckpt;
    //File name
    string gFile;
    //Load File
    ifstream gLoad;
    //Save File
    ofstream gSave;
    
public:
    Game();
    
    void modCmplte(int);
    void setChckpt(int);
    
    int getCmplte();
    int getChckpt();
    
    bool load(Player&, string);
    bool save(Player);
};

#endif	/* GAME_H */

