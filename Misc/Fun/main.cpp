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
#include "Inv.h"

using namespace std;



/*
 * 
 */
//Creates new game
void newGme();
//Loads game
void loadGme();

//Basic level menu
void level(Player&, Game&, bool&);
//Arena function
void arena(Player&, Game&, bool&);
//Shop function
void shop(Player&, Game&);

//Battle interface
void bttlUi(Player&, Enemy&, bool&);
void ui(string, Player, Enemy);
void use(Player&, Enemy);

//Story chapters
void chp1(Player&, Game&);
void chp2(Player&, Game&);

//Prints dialogue
void prntD(string);
//Pseudo cls
void cls();
//Delays text for an indicated time
void delay(int); 


int main(int argc, char** argv) {
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
                //Call new game function
                newGme();
                break;
            case 2:
                //Call load game function
                loadGme();
                break;
            case 3:
                //Flag quit
                quit = true;
                break;
            default:
                //Prompt invalid input
                cout <<"Invalid input!" <<endl;
                //Delay text
                delay(399999999);
                break;
        }
        //Clear screen
        cls();
    //Repeat until user prompts to quit
    }while(!quit);
    
    cout <<"======================" <<endl
                <<"       Goodbye!" <<endl
                <<"======================" <<endl;
    //Delay text
    delay(399999999);
    
    return 0;
}

void newGme(){
    //Variables for the player name and answer
    string name, ans;
    do{
        //Clear screen
        cls();
        //Prompt user
        cout <<"----------------------" <<endl
            <<"       New Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
        //Receives name
        cin >> name;
    
        //Prompt confirm 
        cout <<"Confirm (Y/N)? ";
        cin >> ans;
    
    //Repeat until player inputs yes
    }while(tolower(ans[0]) != 'y');
    
    //Initiate hero
    Player hero(name);
    //Initiate game
    Game rpg;
    //Save the game
    if(!rpg.save(hero)){
        //Prompt user if error
        cout <<"Error: Failed to create save file!" <<endl;
    }
    else{
        //Prompt successful save
        cout <<"Gave saved." <<endl;
        //Delay text
        delay(399999999);
        //Clear screen
        cls();
        
        //Begin game
        chp1(hero, rpg);
    }
}
void loadGme(){
    //Clear screen
    cls();
    //User name
    string name;
    //Prompt user
    cout <<"----------------------" <<endl
            <<"     Load Game" <<endl
            <<"----------------------" <<endl
            <<"Enter your name: ";
    //Input name of save
    cin >> name;
    
    //Initiate hero
    Player hero;
    //Initiate game
    Game rpg;
    //Load the game
    if(!rpg.load(hero, name)){
        //Prompt user when error
        cout <<"Error: File does not exist!" <<endl;
        delay(399999999);
    }
    else{
        //Prompt user when successful
        cout <<"Load successful"<<endl;
        delay(399999999);
        
        //Load level from game checkpoint
        switch(rpg.getChckpt()){
            case 1:
                //Load chapter one
                chp1(hero, rpg);
                break;
            case 2:
                //Load chapter two
                chp2(hero, rpg);
                break;
        }
    }
}

void level(Player&hero, Game&rpg, bool&lvComp){
    //User answer
    int ans;
    //Flag to allow the player to continue
    bool cont = false;
    //Clear screen
    cls();
    
    do{
        //Prompt menu
        cout <<"======================" <<endl
                    <<"       Barracks" <<endl
                    <<"======================" <<endl
                    <<"----------------------" <<endl
                    <<"1] Bed(Save)" <<endl;
        if(rpg.getChckpt() > 1){
            cout <<"2] Shop" <<endl;
        }
        cout<<"3] Arena (Fight)" <<endl
                    <<"4] Profile" <<endl
                    <<"5] Main Menu" <<endl
                    <<"----------------------" <<endl
                    <<"Enter choice: ";
        cin >> ans;

        //Processes user choice
        switch(ans){
            case 1:
                //Save game
                if(!rpg.save(hero)){
                    //Prompt if error
                    cout <<"Error: Failed to save game!" <<endl;
                    //Delay text
                    delay(399999999);
                }
                else{
                    //Prompt if successful
                    cout <<"Save successful!" <<endl;
                    //Delay text
                    delay(399999999);
                }
                break;
            case 2:
                //If player unlocked
                if(rpg.getChckpt() > 1){
                    //Open shop
                    shop(hero, rpg);
                }
                break;
            case 3:
                //Call arena function
                arena(hero, rpg, lvComp);
                //Allow user to continue
                cont = true;
                break;
            case 4:
                //Clear screen
                cls();
                //Output stats
                hero.seeStat();
                break;
            case 5:
                //Return to menu
                return;
                break;
            default:
                //Prompt invalid input
                cout <<"Invalid input!" <<endl;
                //Delay text
                delay(399999999);
                break;
        }
        //Clear screen
        cls();
    }while(!cont);
    
}

void arena(Player &hero,Game &rpg, bool &lvComp){
    //Generate enemies
    Enemy foe1("Knight", 10, 5, 100, 10, 80, 6, 6, 6, 80);
    Enemy foe2("Demon", 100, 50, 25, 0, 80, 6, 6, 6, 100);
    
    //Load arena level based on game checkpoint
    switch(rpg.getChckpt()){
        case 1:
            //Dialogue
            cout <<"Fight 1" <<endl;
            //Delay text
            delay(399999999);
           
            //Call battle ui function
            bttlUi(hero, foe1, lvComp);
            break;
            
        case 2:
            //Dialogue
            cout <<"Fight 2" <<endl;
            //Delay text
            delay(399999999);
            
            //Call battle ui function
            bttlUi(hero, foe2, lvComp);
            break;
            
    }
}

void shop(Player &hero, Game &rpg){
    int ans;
    bool quit = false;
    Inv *sInv;
    sInv = new Inv;
    
    
    switch(rpg.getChckpt()){
        case 2:
            sInv->size = 1;
            sInv->stck = new int[sInv->size];
            sInv->stck[0] = 1;
            break;
        case 3:
            sInv->size = 2;
            sInv->stck = new int[sInv->size];
            sInv->stck[0] = 1;
            sInv->stck[1] = 2;
            break;
        default:
            return;
    }
    
    
    
    do{
        cls();
        //Prompt menu
        cout <<"======================" <<endl
                <<"       Shop" <<endl
                <<"======================" <<endl
                <<"----------------------" <<endl;
        //For the size of inventory
        for(int i = 0; i < sInv->size; i++){
            //Output items
            cout <<i+1 <<"] ";
            switch(sInv->stck[i]){
                case 1:
                    cout <<"Health potions" <<endl;
                    break;
                case 2:
                    cout <<"Mystic glove" <<endl;
                    break;
            }
        }
        cout <<"5] Exit" <<endl 
                <<"----------------------" <<endl
                <<"Enter choice: ";
        //Receive input
        cin >> ans;
        
        
        
        
        switch(ans){
            case 1:
                if(rpg.getChckpt() > 1){
                    if(!hero.setItm(1)){
                        cout <<"Inventory full!" <<endl;
                        //Delay text
                        delay(399999999);
                    }
                    else{
                        cout <<hero.name() <<" purchased health potions!" 
                                <<endl;
                        //Delay text
                        delay(399999999);
                    }
                } 
                break;
            case 2:
                if(rpg.getChckpt() > 2){
                    if(!hero.setItm(2)){
                        cout <<"Inventory full!" <<endl;
                        //Delay text
                        delay(399999999);
                    }
                    else{
                        cout <<hero.name() <<" purchased the mystic glove!" 
                                <<endl;
                        //Delay text
                        delay(399999999);
                    }
                } 
                break;
            case 5:
                quit = true;
                break;
            default:
                cout <<"Invalid input!" <<endl;
                //Delay text
                delay(399999999);
                break;
        }
    
    }while(!quit);
    
}


void bttlUi(Player &hero,Enemy &foe, bool &lvComp){
    //User choice
    int choice;
    //Input validation
    bool inVal;
    //Enemy and player stunned flags
    bool pstun = false, estun = false;
    
    
    do{
        //Player's turn
        do{
            
            cls();
            ui("Fight!", hero, foe);
            cout <<"1] Attack" <<endl
                <<"2] Guard" <<endl
                <<"3] Use" <<endl
                <<"----------------------------"
                <<"----------------------------" <<endl;
            
            //If player stunned
            if(pstun){
                //Prompt user
                cout <<hero.name() <<" is stunned!" <<endl;
                //Reset stunned state
                pstun = false;
                //Delay text
                delay(399999999);
            }
            else{
                //Prompt user
                cout <<"Enter: ";
                cin >> choice;

                //Set input validation to true
                inVal = true;

                switch(choice){
                case 1:
                    //Clear screen
                    cls();
                    //Print attack ui
                    ui("Attack!", hero, foe);
                    //Prompt user attack
                    cout <<hero.name() <<" attacks!" <<endl;
                    //Delay text
                    delay(399999999);

                    //If the enemy is blocking
                    if(foe.blck()){
                        //Calculate stun chances
                        if(hero.stun()){
                            //Prompt if stunned
                            cout <<"The attack was reflected and left " 
                                    <<hero.name() <<" stunned!" <<endl;
                            //Flag stunned state
                            pstun = true;
                            //Delay text
                            delay(399999999);
                        }
                        else{
                            //Print reduced damage
                            cout <<foe.name() <<" receives " 
                                    <<foe.dmged(hero.attck() - 2) 
                                    <<" damage!" <<endl;
                            //Delay text
                            delay(399999999);
                        }

                        //Reset block status
                        foe.guard(0);
                    }
                    else{
                        //Print damage
                        cout <<foe.name() <<" receives " 
                                <<foe.dmged(hero.attck())
                                <<" damage!" <<endl;
                        //Delay text
                        delay(399999999);
                    }
                
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        hero.guard(1);
                        cout <<hero.name() <<" raises his guard!" <<endl;
                        break;
                    case 3:
                        use(hero, foe);
                        break;
                    default:
                        //Prompt invalid input
                        cout <<"Invalid input!" <<endl;
                        //Flag invalid input
                        inVal = false;
                        //Delay text
                        delay(399999999);
                        break;
                    }
            }
        //Repeat while the input is invalid
        } while(!inVal);
        
        //If the enemy is alive
        if(!foe.dead()){
            //If the enemy is stunned
            if(estun){
                //Prompt user
                cout <<foe.name() <<" is stunned!" <<endl;
                //Reset stun flag
                estun = false;
                //Delay text
                delay(399999999);
            }
            else{

                //Enemy's turn
                switch(foe.choice(hero)){
                    case 1:
                        //Clear screen
                        cls();
                        //Print attack ui
                        ui("Attack!", hero, foe);
                        //Prompt enemy attack
                        cout <<foe.name() <<" attacks!" <<endl;
                        //Delay text
                        delay(399999999);
                        //If the player is blocking
                        if(hero.blck()){
                            //Calculate stun chances
                            if(foe.stun()){
                                //Prompt if stunned
                                cout <<"The attack was reflected and left " 
                                        <<foe.name() <<" stunned!" <<endl;
                                estun = true;
                                //Delay text
                                delay(399999999);
                            }
                            else{
                                //Print reduced damage
                                cout <<hero.name() <<" receives " 
                                        <<hero.dmged(foe.attck() - 2) 
                                        <<" damage!" <<endl;
                                //Delay text
                                delay(399999999);
                            }

                            //Reset block status
                            hero.guard(0);
                        }
                        else{
                            //Print damage
                            cout <<hero.name() <<" receives " 
                                    <<hero.dmged(foe.attck())
                                    <<" damage!" <<endl;
                            //Delay text
                            delay(399999999);
                        }
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        foe.guard(1);
                        cout <<foe.name() <<" raises his guard!" <<endl;
                        //Delay text
                        delay(399999999);
                        break;
                    case 3:
                        //Clear screen
                        cls();
                        //Print Action ui
                        ui("Heal", hero, foe);
                        //Display healing value
                        cout <<foe.name() <<" heals " <<foe.heal() <<"!" <<endl;
                        //Delay text
                        delay(399999999);
                        break;
                    default:
                        //Prompt invalid input
                        cout <<"Invalid input!" <<endl;
                        //Flag invalid input
                        inVal = false;
                        //Delay text
                        delay(399999999);
                        break;
                }
            }
        }
        else{
            //Output enemy death
            cout << foe.name() <<" has fallen!" <<endl;
            //Delay text
            delay(399999999);
        }
        
    //Repeat while both players are alive.
    }while(!hero.dead() && !foe.dead());
    
    //If enemies dies and hero lives
    if(foe.dead() && !hero.dead()){
        //Flag for level completion
        lvComp = true;
        //Clear screen
        cls();
        //Prompt experience earned
        cout <<hero.name() <<" earned " <<foe.exp() <<" experience!" <<endl;
        //Delay text
        delay(399999999);
        
        //If the set exp levels up player
        if(hero.setExp(foe.exp())){
            //Prompt  level up
            cout<<hero.name() <<" leveled up!" <<endl;
            //Delay text
            delay(399999999);
            //Initiate level up screen
            hero.lvlUp();
        }
    }
    
            
}
void ui(string title, Player hero, Enemy foe){
    //Prompt ui for battle
    cout <<"============================" 
            <<"============================" <<endl
            //Output title
            <<right <<setw(30)<<title <<endl
            <<"============================" 
            <<"============================" <<endl
            //Hero name
            <<left <<hero.name() 
            <<right <<setw(52)
            //Enemy name
            <<foe.name() <<endl
            //Hero current/max hp
            <<left <<"HP: " <<hero.getCHlth() <<"/" <<hero.getMxHlth() 
            <<right <<setw(40) 
            //Enemy current/max hp
            <<foe.getCHlth() <<"/" <<foe.getMxHlth() <<" :HP"<<endl
            //Hero stamina
            <<left <<"Stamina: " <<hero.getStmna() 
            <<right <<setw(36)
            //Enemy stamina
            <<foe.getStmna() <<" :Stamina" <<endl
            <<"----------------------------"
            <<"----------------------------" <<endl;
}
void use(Player&hero, Enemy foe){
    //user input
    int ans;
    //Clear screen
    cls();
    //Screen title
    ui("Inventory", hero, foe);
    //If inventory is empty
    if(hero.sizeInv() == 0){
        //Prompt empty inventory
        cout <<"Inventory Empty!" <<endl
                <<"----------------------------"
                <<"----------------------------" <<endl;
        //Delay text
        delay(399999999);
    }
    else{
        //Output inventory
        for(int i = 0; i < hero.sizeInv(); i++){
            cout <<i+1 <<"] ";
            //Outputs item base on number
            switch(hero.getItm(i)){
                case 1:
                    cout <<i+1 <<"] Health potion" <<endl; 
                    break;
                case 2:
                    cout <<i+1 <<"] Mystic Glove" <<endl; 
                    break;
                default:
                    break;
             }
        }
        cout <<"----------------------------"
                <<"----------------------------" <<endl;
        cin >> ans;
        
        switch(ans){
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
            case 6:
                break;
        
        }
    }
    
    
    
}

void chp1(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //If scene not completed
    if(rpg.getCmplte() < 1){
        //Initiate dialogue
        cout <<"Chapter 1: Arrival" <<endl;
        delay(399999999);
        
    
    }
    //Add percentage to game completion for scene
    rpg.modCmplte(1); //Total: 1
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"Game over!" <<endl <<"You died!" <<endl;
            //Delay text
            delay(699999999);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        hero.createInv();
        hero.incInv(3);
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 11
        //Set checkpoint to chapter 2
        rpg.setChckpt(2);
        //Save game
        if(!rpg.save(hero)){
            //Prompt if error
            cout <<"Error: Failed to save game!" <<endl;
            //Delay text
            delay(399999999);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(399999999);
        }
        //Chapter 2 function
        chp2(hero, rpg);
    }
    
}
void chp2(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //If scene not completed
    if(rpg.getCmplte() < 12){
        //Initiate dialogue
        cout <<"Chapter 2: Mystics" <<endl;
        delay(399999999);
        
    
    }
    //Add percentage to game completion for scene
    rpg.modCmplte(1); //Total: 12
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"You died!" <<endl <<"Game Over!" <<endl;
            //Delay text
            delay(699999999);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 22
        //Set checkpoint to chapter 3
        rpg.setChckpt(3);
        //Chapter 3 function
    }
    
}


void prntD(string dialge){
    //Print dialogue
    cout <<dialge <<endl
            <<"------------------------------------------------------" <<endl
            <<"Enter anything to continue: ";
    //Input for player continue
    cin >> dialge;
}
void cls(){
    for(int i = 0; i < 20; i++){
        cout <<endl;
    }
}
void delay(int time){
    //Delay the text for the indicated time
    for(int i = 0; i < time; i++){}
}