/* 
 * File:   Player.cpp
 * Author: rcc
 * 
 * Created on October 14, 2015, 10:27 AM
 */

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "Player.h"
#include "Inv.h"

using namespace std;

Player::Player(){
    pName = "Hero"; //Player Name
    
    pMxHlth = 100; //Max Health
    pCHlth = 100; //Current Health
    pStmna = 20; //Stamina
    
    pStr = 20; //Strength
    pDef = 5; //Defense
    pAcc = 85; //Accuracy
    pDex = 10; //Dexterity
    pInt = 10; //Intelligence
    pLuc = 10; //Luck
    
    pCExp = 0; //Current Experience
    pMxExp = 100; //Max Experience to level
    pLvl = 1; //Current level
    
    
    pDead = false; //Death flag
    pBlck = false; //Guard flag
    
    pStun = 0; //Stun chance
    
   
    pInv = new Inv; //Create new inv
    crtInv(); //Create player inv
}
Player::Player(string name){
    pName = name; //Player Name
    
    pMxHlth = 100; //Max Health
    pCHlth = 100; //Current Health
    pStmna = 20; //Stamina
    
    pStr = 20; //Strength
    pDef = 5; //Defense
    pAcc = 85; //Accuracy
    pDex = 10; //Dexterity
    pInt = 10; //Intelligence
    pLuc = 10; //Luck
    
    pCExp = 0; //Current Experience
    pMxExp = 100; //Max Experience to level
    pLvl = 1; //Current level
    
    pDead = false; //Death flag
    pBlck = false; //Guard flag
    
    pStun = 0; //Stun chance
    
   
    pInv = new Inv; //Create new inv
    crtInv(); //Create player inv
}

string Player::name(){
    return pName;
}
void Player::setName(string name){
    pName = name;
}

int Player::getCHlth(){
    return pCHlth; //Returns current health
}
int Player::getMxHlth(){
    return pMxHlth; //Returns the max health
}
void Player::modCHlth(int val){
    pCHlth += val; //Modifies current health based on value
    
    //If the current health is greater than the max
    if(pCHlth > pMxHlth){
        //Set to max
        pCHlth = pMxHlth;
    }
}
void Player::modHlth(int value){
    pMxHlth += value; //Modifies max health based on value
}
void Player::modStmn(int val){
    pStmna += val; //Increases stamina by the value
}
int Player::getStmna(){
    return pStmna;
}

int Player::attck(){
    //Generates a random number from 0 - 100 for crit %
    unsigned short int crit = rand()%101;
    //Sets the initial damage of the player by 80% of the strength
    unsigned short int dmg = pStr*0.8;
    //Generates a random number for hit/miss %
    unsigned short int hit = rand()%101;
    
    //Checks if crit generated a number less than luck (luck% chance)
    if(crit < pLuc){
        //Doubles damage if crit
        dmg = dmg*2;
    }
    //Checks if player misses 
    if(hit > pAcc){
        //Sets the damage to 0 if miss
        dmg = 0;
    }
    
    //Returns the damage
    return dmg;
}
int Player::dmged(int eAtt){
    int dodge = rand()%101; //Calculates a number for dodge chance
    int dmg = eAtt - pDef; //Calculates damage
    
    //If the damage is less than 0
    if(dmg < 0){
        //Set damage to 0
        dmg = 0;
    }
    
    //Checks the dodge value for dodge chance
    if(dodge < pDex * 0.7){
        //Sets damage to 0
        dmg = 0;
    }
    
    //Apply damage to health
    pCHlth -= dmg;
    
     //If the health drops below zero
    if(pCHlth < 0){
        //Set health to zero
        pCHlth = 0;
    }
    
    //Return the amount of damage recieved
    return dmg;
}
void Player::guard(int val){
    if(val == 1){
        pBlck = true;
    }
    else{
        pBlck = false;
    }
}
bool Player::blck(){
    return pBlck;
}
bool Player::stun(){
    //Increment stun chances
    pStun++;
    
    //Generate random number for stun chance
    int stun = rand()%101;
    
    //Minimum of 10% chance to get stunned
    if(stun < 10 + (pStun*10)){
        //Reset increased stun increment
        pStun = 0;
        //Return stunned flag
        return true;
    }
    else{
        //Return false stunned flag
        return false;
    }

}
int Player::heal(){
    
    if(pStmna > 10){
        //Calculates heal with intelligence
        int hl = 5 + (pInt*0.5);

        //Applies heal to current health
        pCHlth += hl;
        
        //Decrement stamina
        pStmna -= 10;
        
        //Return healing value
        return hl;
    }
    else{
        return 0;
    }
    
}

void Player::modStat(int str, int def, int acc, int dex, int intl, int luc){
    pStr += str; // Modifies strength
    pDef += def; // Defense
    pAcc += acc; // Accuracy
    pDex += dex; // Dexterity
    pInt += intl; // Intelligence
    pLuc += luc; //Luck
}
void Player::seeStat(){
    bool quit = false;
    int ans = 0;
    do{
        cout <<"=========== Profile ============" <<endl
                <<"--------------------------------" <<endl
                <<"Name: " <<pName <<setw(10) <<"Lvl: " <<pLvl <<endl
                <<"Hp: " <<pCHlth <<"/" <<pMxHlth
                <<setw(10) <<"Exp: " <<pCExp <<"/" <<pMxExp <<endl
                <<"Stamina: " <<pStmna <<endl
                <<"--------------------------------" <<endl
                <<setw(18) <<"Stats" <<endl
                <<"--------------------------------" <<endl
                <<"Str: " <<pStr <<endl
                <<"Def: " <<pDef <<endl
                <<"Acc: " <<pAcc <<endl
                <<"Dex: " <<pDex <<endl
                <<"Int: " <<pInt <<endl
                <<"Luc: " <<pLuc <<endl
                <<"--------------------------------" <<endl
                <<"1] Inventory" <<endl
                <<"2] Exit" <<endl
                <<"================================" <<endl;
        cout <<"Select: ";
        cin >> ans;
        
        switch(ans){
            case 1:
                //Output inventory
                do{
                    cls();
                    cout <<"=========== Profile ============" <<endl
                            <<"--------------------------------" <<endl
                            <<"Name: " <<pName <<setw(10) <<"Lvl: " <<pLvl 
                            <<endl <<"Hp: " <<pCHlth <<"/" <<pMxHlth
                            <<setw(10) <<"Exp: " <<pCExp <<"/" <<pMxExp <<endl
                            <<"Stamina: " <<pStmna <<endl
                            <<"--------------------------------" <<endl
                            <<setw(20) <<"Inventory" <<endl
                            <<"--------------------------------" <<endl;
                    
                    //if inventory empty
                    if(pInv->cap <= 0){
                        //Prompt empty inventory
                        cout <<"No Inventory" <<endl;
                    }
                    else{
                        //Output inventory
                        for(int i = 0; i < pInv->cap; i++){
                            switch(pInv->stck[i]){
                                case 1:
                                    cout <<i+1 <<"] Health potion" <<endl; 
                                    break;
                                case 2:
                                    cout <<i+1 <<"] Mystic Glove" <<endl; 
                                    break;
                                default:
                                    cout <<i+1 <<"] " <<endl;
                                    break;
                            }
                        }
                    
                    }
                    
                    cout <<"--------------------------------" <<endl
                        <<"1] Profile" <<endl
                        <<"2] Exit" <<endl
                        <<"================================" <<endl;
                    cout <<"Select: ";
                    cin >> ans;
                    
                    if(ans == 2){
                        return;
                    }
                }while(ans != 1);
                cls();
                break;
            case 2:
                quit = true;
                break;
        }
        
    }while(!quit);
    cls();
}
int Player::getStat(int stat){
    //Returns the given stat
    switch(stat){
        case 1:
            return pMxHlth;
            break;
        case 2:
            return pCHlth;
            break;
        case 3:
            return pStmna;
            break;
        case 4:
            return pStr;
            break;
        case 5:
            return pDef;
            break;
        case 6:
            return pAcc;
            break;
        case 7:
            return pDex;
            break;
        case 8:
            return pInt;
            break;
        case 9:
            return pLuc;
            break;
        case 10:
            return pMxExp;
            break;
        case 11:
            return pCExp;
            break;
        case 12:
            return pLvl;
            break;
        case 13:
            return pInv->cap;
            break;
        case 14:
            return pInv->size;
            break;
    }
}
void Player::setStat(int stat, int value){
    //Set the indicated stat with the given value
    switch(stat){
        case 1:
            pMxHlth = value;
            break;
        case 2:
            pCHlth = value;
            break;
        case 3:
            pStmna = value;
            break;
        case 4:
            pStr = value;
            break;
        case 5:
            pDef = value;
            break;
        case 6:
            pAcc = value;
            break;
        case 7:
           pDex = value;
            break;
        case 8:
            pInt = value;
            break;
        case 9:
            pLuc = value;
            break;
        case 10:
            pMxExp = value;
            break;
        case 11:
            pCExp = value;
            break;
        case 12:
            pLvl = value;
            break;
        case 13:
            pInv->cap = value;
            break;
        case 14:
            pInv->size = value;
            break;
    }
}

bool Player::setExp(int exp){
    pCExp += exp; //Sets experience to current exp level
    
    if(pCExp >= pMxExp){ //If the current exp exceeds the max exp
        pCExp -= pMxExp; //Assigns excess exp to current level
        return true; //Level up is true
    }
    
    return false; //Level up is false
}
void Player::lvlUp(){
    int pts = 10, pIn; //Points to distribute and player input
    int str = 0, def = 0, acc = 0, dex = 0, intl = 0, luc = 0; //Stat pts
   
    string quit; //String for confirming quit
    
    pLvl++; //Increment lvl up
    
    do{
        //Displays level up screen
        cout <<"Distribute your stats! Points: " <<pts <<endl
                <<"---------------------------------------" <<endl
                <<"[1] Str: " <<pStr <<" + (" <<str <<")" <<endl
                <<"[2] Def: " <<pDef <<" + (" <<def <<")" <<endl
                <<"[3] Acc: " <<pAcc <<" + (" <<acc <<")" <<endl
                <<"[4] Dex: " <<pDex <<" + (" <<dex <<")" <<endl
                <<"[5] Int: " <<pInt <<" + (" <<intl <<")" <<endl
                <<"[6] Luc: " <<pLuc <<" + (" <<luc <<")" <<endl
                <<"---------------------------------------" <<endl;
        
        
        if(pts > 0){ //If the user still has points to distribute
            //User selects a stat to raise
            cout <<"Select a stat: "; 
            cin >> pIn;
            
            //Distributes the point
            switch(pIn){
                case 1: //Strength
                    str++;
                    pts--;
                    break;
                    
                case 2: //Defense
                    def++;
                    pts--;
                    break;
                    
                case 3: //Accuracy
                    acc++;
                    pts--;
                    break;
                    
                case 4: //Dexterity
                    dex++;
                    pts--;
                    break;
                    
                case 5: //Intelligence
                    intl++;
                    pts--;
                    break;
                    
                case 6: //Luck
                    luc++;
                    pts--;
                    break;
            }
        }
        else{ //Else if the user is out of points
            //Prompt to confirm selection
            cout <<"Confirm (Y/N)? ";
            cin >> quit;
            
            //If the user does not select to quit
            if(tolower(quit[0]) != 'y'){
                //Reset stats
                str = 0;
                def = 0;
                acc = 0;
                dex = 0;
                intl = 0;
                luc = 0;
                
                //Reset points
                pts = 5;
            }
            else{ //If the user does select to quit
                //Modify max health
                modHlth(10);
                //Modify player stamina
                modStmn(5);
                //Modify the stats by the selected values
                modStat(str,def,acc,dex,intl,luc);
            }
        }
                
        cls();
    }while(tolower(quit[0]) != 'y');
}
int Player::getLvl(){
    return pLvl; //Returns the player's level
}
bool Player::dead(){
    if(pCHlth < 1){
        pDead = true;
    }
    //Returns death flag
    return pDead;
}
void Player::crtInv(){
    //Inventory
    pInv->max = 5; //Max cap
    pInv->cap = 0; //Capacity
    pInv->size = 0; //Size
    pInv->stck = new int[pInv->max];
    fillInv();
}
void Player::incInv(int val){
    //Sets allowable capacity
    pInv->cap = val;
}
int Player::sizeInv(){
    return pInv->size;
}
 void Player::setItm(int itm, int slot){
     //If inv is not empty
    if(pInv->size > 0){
        //Set item to current slot
        pInv->stck[slot] = itm;
    }
 }
bool Player::setItm(int itm){
    //If there is enough room
    if(pInv->size < pInv->cap){
        //Set item to current slot
        pInv->stck[pInv->size] = itm;
        //Increment size
        pInv->size++;
        //Return confirm
        return true;
    }
    else{
        //Returns error
        return false;
    }
}
void Player::remItm(int numItm){
    //Set item number to zero
    pInv->stck[numItm] = 0;
    
    //Sort inventory
    for(int i = 0; i < pInv->size; i++){
        for(int j = i; j < pInv->size - 1; j++){
            if(pInv->stck[j] < pInv->stck[j+1]){
                int temp = pInv->stck[j];
                pInv->stck[j] = pInv->stck[j+1];
                pInv->stck[j+1] = temp;
            }
        }
    }
    
    //Decrement size
    pInv->size--;
}

int Player::getItm(int val){
    switch(val){
        case 0:
            //Returns item 1
            return pInv->stck[0];
            break;
        case 1:
            //Returns item 2
            return pInv->stck[1];
            break;
        case 2:
            //Returns item 3
            return pInv->stck[2];
            break;
        case 3:
            //Returns item 4
            return pInv->stck[3];
            break;
        case 4:
            //Returns item 5
            return pInv->stck[4];
            break;
    }
}


void Player::fillInv(){
    //For the maximum size of the array
    for(int i = 0; i < pInv->max; i++){
        //Fill array with zeros
        pInv->stck[i] = 0;
    }
}

void Player::cls(){
    for(int i = 0; i < 20; i++){
        cout <<endl;
    }
}