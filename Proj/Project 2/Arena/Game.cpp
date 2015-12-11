/* 
 * File:   Game.cpp
 * Author: Kauru99
 * 
 * Created on October 14, 2015, 9:15 PM
 */

#include <string>
#include <fstream>
#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Inv.h"

using namespace std;

Game::Game(){
    //Set initial game completion and checkpoint values
    gCmplte = 0;
    gChckpt = 1;
}

void Game::modCmplte(int val){
    //Increment completion % by the given value
    gCmplte += val;
}
void Game::setChckpt(int val){
    //Set checkpoint to indicated value
    gChckpt = val;
}

bool Game::save(Player user){
    //Error checker
    bool error = true;
    //Create game save under the player name
    gFile = "deps/Saves/" + user.name();
    //Opens file
    gSave.open(gFile.c_str());
    
    //If file does not exist
    if(!gSave){
        //Prompt user and flag error
        error = false;
    }
    else{
        //Save user stats
        gSave << user.name() <<endl
                <<gCmplte <<endl
                <<gChckpt <<endl;
        //Retrieves all of the stats
        for (int i = 1; i < 15; i++){
            gSave <<user.getStat(i) <<endl;
        }
        
        //Save inventory
        for (int i = 0; i < user.sizeInv(); i++){
            gSave <<user.getItm(i) <<endl;
        }
    }
    
    //Close the file
    gSave.close();
    
    //Returns error status
    return error;
}
bool Game::load(Player&user, string name){
    //Error checking flag
    bool error = true;
    //Variables to read content
    int cmplte, chckpt; //Game progress and checkpoint
    int stat; //User stats
    //File name
    gFile = "deps/Saves/" + name;
    
    //Open the file
    gLoad.open(gFile.c_str());
    
    //If the file does not exit
    if(!gLoad){
        //Prompt and flag for error
        error = false;
    }
    else{
        //Load information from file
        gLoad >>name >>cmplte >>chckpt;
        //Assign name
        user.setName(name);
        //Assign completion %
        gCmplte = cmplte;
        //Assign checkpoint
        gChckpt = chckpt;
        
        //Sets all of the stats
        for(int i = 1; i < 15; i++){
            //Retrieves stat
            gLoad >> stat;
            //Assigns value to the correct stat
            user.setStat(i, stat);
        }
        
        //Sets all items
        for(int i = 0; i < user.sizeInv(); i++){
            //Retrieve itm
            gLoad >> stat;
            //Input itm in proper slot
            user.setItm(stat, i);
        }
        
        
    }
    
    //Close the file
    gLoad.close();
    
    //Return error status
    return error;
}

int Game::getCmplte(){
    //Return game complete percentage
    return gCmplte;
}
int Game::getChckpt(){
    //Return game checkpoint
    return gChckpt;
}
