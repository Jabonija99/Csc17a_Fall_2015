/* 
 * File:   Game.cpp
 * Author: Kauru99
 * 
 * Created on December 11, 2015, 10:04 PM
 */


#include <string>
#include <fstream>
#include <iostream>

#include "Game.h"
#include "Player.h"

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
    //Create game save under the player name///////////////////////////////////
    gFlNme = "deps/Saves/" + user.gtName() + ".dat";
    
    //Try to open the file
    try{
        //Opens a file to write, truncates contents
        gFile.open(gFlNme.c_str(), ios::out | ios::trunc);
        
        //If file fails to open
        if(!gFile){
            //Throw an exception
            throw -1;
        }
        
        //Saves Player and game information
        //Writes name
        gFile << user.gtName() <<endl;
        
        //Writes all player stats
        for(int i = 0; i < user.gtStSze(); i++){
            gFile <<user.gtStat(i) <<endl;
        }
        
        //Writes inventory capacity
        gFile <<user.invCap() <<endl;
        
        //Write inventory size
        gFile <<user.invSze() <<endl;
        
        //Write inventory
        for(int i = 0; i < user.invSze(); i++){
            gFile <<user.getItm(i) <<endl;
        }
        
        //Writes Game progress
        gFile << gCmplte <<endl;
        //Writes Game checkpoint
        gFile << gChckpt <<endl;
        
        /**
        //Writes all player stats
        for(int i = 0; i < user.gtStSze(); i++){
            int stat = user.gtStat(i);
            gFile.write(reinterpret_cast<char*>(&stat),
                    sizeof(int));
        }
        
        //Writes inventory capacity
        int cap = user.invCap();
        gFile.write(reinterpret_cast<char *>(&cap), sizeof(int));
        
        //Write inventory size
        int sze = user.invSze();
        gFile.write(reinterpret_cast<char *>(&sze), sizeof(int));
        
        //Writes all items
        for(int i = 0; i < user.invSze(); i++){
            int item = user.getItm(i);
            gFile.write(reinterpret_cast<char *>(&item), sizeof(int));
        }
        
        //Writes the character in the binary file
        //gFile.write(reinterpret_cast<char *> (&user), sizeof(user));
    */
    //Catch any errors
    }catch(...){
        //Set error to false
        error = false;
    }
    
    //Close the file
    gFile.close();
    
    /**
    //Create game save for game progress //////////////////////////////////////
    gFlNme = "deps/Saves/" + user.gtName() + "_game.dat";
    
    //Try to open the file
    try{
        //Opens a file to write, truncates contents
        gFile.open(gFlNme.c_str(), ios::out | ios::trunc);
        
        //If file fails to open
        if(!gFile){
            //Throw an exception
            throw -1;
        }
        
        //Write character name
        gFile <<user.gtName() <<endl;
        
        //Writes completion % and checkpoint
        gFile << gCmplte <<endl
                <<gChckpt <<endl;
    
    //Catch any errors
    }catch(...){
        //Set error to false
        error = false;
    }
    
    //Close the file
    gFile.close();
     * */
    
    
    //Returns error status
    return error;
}
bool Game::load(Player  &user, string name){
    //Error checking flag
    bool error = true;
    
    //User Save file//////////////////////////////////////////////////////////
    gFlNme = "deps/Saves/" + name + ".dat";
    
    //Try to open the file
    try{
        //Open a read file
        gFile.open(gFlNme.c_str(), ios::in);
        
        //If the file fails to open
        if(!gFile){
            //Throw an exception
            throw -1;
        }
        
        //Reads Player and game information
        
        //Reads Player name
        string name;
        gFile >> name;
        //Sets name
        user.stName(name);
        
        //Reads all player stats
        for(int i = 0; i < user.gtStSze(); i++){
            int stat;
            gFile >> stat;
            //Sets stats
            user.stStat(i, stat);
        }
        
        //Reads inventory capacity
        int cap;
        gFile >> cap;
        //Sets capacity
        user.stCap(cap);
        
        //Reads inventory size
        int sze;
        gFile >> sze;
        //Reads capacity
        user.stSze(sze);
        
        //Reads inventory
        for(int i = 0; i < user.invSze(); i++){
            int item;
            gFile >> item;
            //Sets item in inventory
            user.setItm(item, i);
        }
        
        //Sets Game progress
        gFile >> gCmplte;
        //Sets Game checkpoint
        gFile >> gChckpt;
        
        /**
        //Goes through all stats
        for(int i = 0; i < user.gtStSze(); i++){
             //Variable to hold all stats
            int stat;
            //Reads in values
            gFile.read(reinterpret_cast<char*>(&stat),sizeof(stat));
            cout <<stat <<endl;
            //Sets stat to indicated value
            user.stStat(i, stat);
        }
     
        
        //Reads inventory cap
        int cap;
        gFile.read(reinterpret_cast<char *>(&cap), sizeof(cap));
        user.stCap(cap);
        
        //Reads inventory size
        int sze;
        gFile.read(reinterpret_cast<char *>(&sze), sizeof(sze));
        user.stSze(sze);
        
        
        //Reads all items
        for(int i = 0; i < user.invSze(); i++){
            int item;
            gFile.write(reinterpret_cast<char *>(&item), sizeof(int));
            user.setItm(item);
        }
        
        //Loads the saved Player to the player object
        //gFile.read(reinterpret_cast<char *>(&user), sizeof(Player));
    */
        //If there was an error reading
        if(gFile.fail()){
            //Throw an exception
            throw -2;
        }
        
    //If it catches any exceptions
    }catch(...){
        //Flag error
        error = false;
    }
    
    //Close Player stat file
    gFile.close();
   
    /*
    //Game saves file name////////////////////////////////////////////////////
    gFlNme = "deps/Saves/" + name + "_game.dat";
    
    //Try to open the file
    try{
        //Open a read file
        gFile.open(gFlNme.c_str(), ios::in);
        
        //If the file fails to open
        if(!gFile){
            //Throw an exception
            throw -1;
        }
    
        //Read character game
        string name;
        gFile >> name;
        user.stName(name);
        
        //Read completion % and checkpoint
        gFile >> gCmplte;
        gFile >> gChckpt;
    
    //If it catches any exceptions
    }catch(...){
        //Flag error
        error = false;
    }
    
    //Close the file
    gFile.close();
    */
    
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


