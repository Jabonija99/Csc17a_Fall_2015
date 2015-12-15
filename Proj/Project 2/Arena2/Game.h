/* 
 * File:   Game.h
 * Author: Kauru99
 *
 * Created on December 11, 2015, 10:04 PM
 */

#include <string>
#include <fstream>
#include "Player.h"

#ifndef GAME_H
#define	GAME_H

class Game{
private:
    //Int for game completion and checkpoint for the player's location
    int gCmplte, gChckpt;
    //File name
    string gFlNme;
    //File input and output
    fstream gFile;
    
public:
    //Base constructor
    Game();
    
    //Modify game completion %
    void modCmplte(int);
    //Set game checkpoint
    void setChckpt(int);
    
    //Return the game completion
    int getCmplte();
    //Return the checkpoint
    int getChckpt();
    
    //Load game
    bool load(Player&, string);
    //Save game
    bool save(Player);
};

#endif	/* GAME_H */

