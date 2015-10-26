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
void use(Player&, Enemy, bool&);

//Story chapters
void chp1(Player&, Game&);
void chp2(Player&, Game&);
void chp3(Player&, Game&);
void chp4(Player&, Game&);
void chp5(Player&, Game&);

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
                <<"       The Arena" <<endl
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
                delay(4);
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
    delay(4);
    
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
        delay(4);
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
        delay(4);
    }
    else{
        //Prompt user when successful
        cout <<"Load successful"<<endl;
        delay(4);
        
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
            case 3:
                //Load chapter three
                chp3(hero, rpg);
                break;
            case 4:
                //Load chapter four
                chp4(hero, rpg);
                break;
            case 5:
                //Load chapter five
                chp5(hero, rpg);
                break;
            case 0:
                //Reset game to chapter 1
                rpg.setChckpt(1);
                //Decrement game completion to 0
                rpg.modCmplte(-55);
                //Load chapter 1
                chp1(hero,rpg);
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
                //Heals player
                hero.modCHlth(hero.getMxHlth() - hero.getCHlth());
                
                //Save game
                if(!rpg.save(hero)){
                    //Prompt if error
                    cout <<"Error: Failed to save game!" <<endl;
                    //Delay text
                    delay(4);
                }
                else{
                    //Prompt if successful
                    cout <<"Save successful!" <<endl;
                    //Delay text
                    delay(4);
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
                delay(4);
                break;
        }
        //Clear screen
        cls();
    }while(!cont);
    
}

void arena(Player &hero,Game &rpg, bool &lvComp){
    //Clear screen
    cls();
    
    //Generate enemies
    //Name, health, stamina, str, def, acc, dex, int, luc, exp
    Enemy foe1("Barbarian", 50, 0, 30, 10, 80, 5, 0, 5, 100);
    Enemy foe2("Mystic", 70, 50, 30, 5, 80, 3, 50, 5, 100);
    Enemy foe3("Great Knight", 110, 50, 35, 20, 80, 2, 10, 5, 100);
    Enemy foe4("Assassin", 120, 80, 40, 20, 90, 30, 20, 30, 100);
    Enemy foe5("Arena Lord", 150, 100, 45, 10, 80, 30, 50, 40, 100);
    
    //Load arena level based on game checkpoint
    switch(rpg.getChckpt()){
        case 1:
            //Dialogue
            cout <<"Fight 1" <<endl;
            //Delay text
            delay(4);
           
            //Call battle ui function
            bttlUi(hero, foe1, lvComp);
            break;
            
        case 2:
            //Dialogue
            cout <<"Fight 2" <<endl;
            //Delay text
            delay(4);
            
            //Call battle ui function
            bttlUi(hero, foe2, lvComp);
            break;
            
        case 3:
            //Dialogue
            cout <<"Fight 3" <<endl;
            //Delay text
            delay(4);
            
            //Call battle ui function
            bttlUi(hero, foe3, lvComp);
            break;
            
        case 4:
            //Dialogue
            cout <<"Fight 4" <<endl;
            //Delay text
            delay(4);
            
            //Call battle ui function
            bttlUi(hero, foe4, lvComp);
            break;
            
        case 5:
            //Dialogue
            cout <<"Fight 5" <<endl;
            //Delay text
            delay(4);
            
            //Call battle ui function
            bttlUi(hero, foe5, lvComp);
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
        case 4:
            sInv->size = 2;
            sInv->stck = new int[sInv->size];
            sInv->stck[0] = 1;
            sInv->stck[1] = 2;
            break;
        case 5:
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
                        delay(4);
                    }
                    else{
                        cout <<hero.name() <<" purchased health potions!" 
                                <<endl;
                        //Delay text
                        delay(4);
                    }
                } 
                break;
            case 2:
                if(rpg.getChckpt() > 2){
                    if(!hero.setItm(2)){
                        cout <<"Inventory full!" <<endl;
                        //Delay text
                        delay(4);
                    }
                    else{
                        cout <<hero.name() <<" purchased the mystic glove!" 
                                <<endl;
                        //Delay text
                        delay(4);
                        cout <<"A trembling sensation courses through your " 
                                <<"hand." <<endl;
                        //Delay text
                        delay(7);
                    }
                } 
                break;
            case 5:
                quit = true;
                break;
            default:
                cout <<"Invalid input!" <<endl;
                //Delay text
                delay(4);
                break;
        }
    
    }while(!quit);
    
    //Deallocate from memory
    delete sInv->stck;
    delete sInv;
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
                delay(4);
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
                        delay(4);

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
                                delay(4);
                            }
                            else{
                                //Print reduced damage
                                cout <<foe.name() <<" receives " 
                                        <<foe.dmged(hero.attck() - 2) 
                                        <<" damage!" <<endl;
                                //Delay text
                                delay(4);
                            }

                            //Reset enemy guard state
                            foe.guard(0);
                        }
                        else{
                            //Print damage
                            cout <<foe.name() <<" receives " 
                                    <<foe.dmged(hero.attck())
                                    <<" damage!" <<endl;
                            //Delay text
                            delay(4);
                        }

                        //Reset player guard state
                        hero.guard(0);
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        //Set player guard state
                        hero.guard(1);
                        cout <<hero.name() <<" raises his guard!" <<endl;
                        //Delay text
                        delay(4);
                        break;
                    case 3:
                        //Call item use function
                        use(hero, foe, inVal);
                        //Reset player guard state
                        hero.guard(0);
                        break;
                    default:
                        //Prompt invalid input
                        cout <<"Invalid input!" <<endl;
                        //Flag invalid input
                        inVal = false;
                        //Delay text
                        delay(4);
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
                delay(4);
            }
            else{

                //Enemy's turn
                switch(foe.choice(hero,pstun)){
                    case 1:
                        //Clear screen
                        cls();
                        //Print attack ui
                        ui("Attack!", hero, foe);
                        //Prompt enemy attack
                        cout <<foe.name() <<" attacks!" <<endl;
                        //Delay text
                        delay(4);
                        //If the player is blocking
                        if(hero.blck()){
                            //Calculate stun chances
                            if(foe.stun()){
                                //Prompt if stunned
                                cout <<"The attack was reflected and left " 
                                        <<foe.name() <<" stunned!" <<endl;
                                estun = true;
                                //Delay text
                                delay(4);
                            }
                            else{
                                //Print reduced damage
                                cout <<hero.name() <<" receives " 
                                        <<hero.dmged(foe.attck() - 2) 
                                        <<" damage!" <<endl;
                                //Delay text
                                delay(4);
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
                            delay(4);
                        }
                        
                        //Reset enemy guard state
                        foe.guard(0);
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        //Set enemy guard state
                        foe.guard(1);
                        cout <<foe.name() <<" raises his guard!" <<endl;
                        //Delay text
                        delay(4);
                        break;
                    case 3:
                        //Clear screen
                        cls();
                        //Print Action ui
                        ui("Heal", hero, foe);
                        //Display healing value
                        cout <<foe.name() <<" heals " <<foe.heal() <<"!" <<endl;
                        
                        //Reset enemy guard state
                        foe.guard(0);
                        
                        //Delay text
                        delay(4);
                        break;
                    default:
                        //Prompt invalid input
                        cout <<"Invalid input!" <<endl;
                        //Flag invalid input
                        inVal = false;
                        //Delay text
                        delay(4);
                        break;
                }
            }
        }
        else{
            //Output enemy death
            cout << foe.name() <<" has fallen!" <<endl;
            //Delay text
            delay(4);
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
        delay(4);
        
        //If the set exp levels up player
        if(hero.setExp(foe.exp())){
            //Prompt  level up
            cout<<hero.name() <<" leveled up!" <<endl;
            //Delay text
            delay(4);
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
            <<right <<setw(38) 
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
void use(Player &hero, Enemy foe, bool &inVal){
    //user input
    int ans;
    //Clear screen
    cls();
    //Screen title
    ui("Inventory", hero, foe);
    //If inventory is empty
    if(hero.sizeInv() < 1){
        //Prompt empty inventory
        cout <<"Inventory Empty!" <<endl
                <<"----------------------------"
                <<"----------------------------" <<endl;
        inVal = false;
        //Delay text
        delay(4);
    }
    else{
        //Output inventory
        for(int i = 0; i < hero.sizeInv(); i++){
            //Outputs item base on number
            switch(hero.getItm(i)){
                case 0:
                    cout <<i+1 <<"] (Empty)" <<endl;
                    break;
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
        cout <<"6] Back" <<endl
                <<"----------------------------"
                <<"----------------------------" <<endl;
        cin >> ans;
        
        //Use selected item
        switch(ans){
            case 1:
                //If there is an item
                if(hero.sizeInv() > 0){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.name() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.name() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.modCHlth(25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.name() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.name() <<" heals " <<hero.heal() 
                                    <<" hp!" <<endl;
                            //Delay text
                            delay(4);
                            break;
                        default:
                            inVal = false;
                            break;
                    }
                }
                break;
            case 2:
                //If there is an item
                if(hero.sizeInv() > 1){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.name() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.name() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.modCHlth(25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.name() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.name() <<" heals " <<hero.heal() 
                                    <<" hp!" <<endl;
                            //Delay text
                            delay(4);
                            break;
                        default:
                            inVal = false;
                            break;
                    }
                    
                }
                break;
            case 3:
                if(hero.sizeInv() > 2){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.name() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.name() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.modCHlth(25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.name() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.name() <<" heals " <<hero.heal() 
                                    <<" hp!" <<endl;
                            //Delay text
                            delay(4);
                            break;
                        default:
                            inVal = false;
                            break;
                    }
                }
                break;
            case 4:
                if(hero.sizeInv() > 3){
                   //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.name() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.name() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.modCHlth(25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.name() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.name() <<" heals " <<hero.heal() 
                                    <<" hp!" <<endl;
                            //Delay text
                            delay(4);
                            break;
                        default:
                            inVal = false;
                            break;
                    }
                }
                break;
            case 5:
                if(hero.sizeInv() > 4){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.name() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.name() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.modCHlth(25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.name() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.name() <<" heals " <<hero.heal() 
                                    <<" hp!" <<endl;
                            //Delay text
                            delay(4);
                            break;
                        default:
                            inVal = false;
                            break;
                    }
                }
                break;
            default:
                inVal = false;
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
        
        cout <<"What did I do to deserve a fate like this?" <<endl;
        delay(7);
        cls();
        
        cout <<"Mother?" <<endl;
        delay(5);
        cout <<"Father?" <<endl;
        delay(5);
        cls();
        
        cout <<"Where did it all go wrong?" <<endl;
        delay(7);
        cls();
        
        
        cout <<"Chapter 1: Arrival" <<endl;
        delay(6);
        cls();
        
        prntD("     Light flashed through the thin slit at the back of the \n"
                "cramped carriage as the light danced beneath the shadows \n"
                "of the surrounding trees.");
        cls();
        prntD("     The wooden wagon creaked and rocked as it was led further\n"
                "into the mysterious valley. There was only one other man in\n"
                "the carriage with "+ hero.name()+". He sat in the opposite "
                "corner,\n"
                "his old and wrinkled face scowling as he met " + hero.name() + 
                "’s gaze.");
        cls();
        prntD("     The wood rattled as they came to a sudden halt, jostling \n"
                "the hero in his seat. The back doors slammed open, allowing \n"
                "the warm evening light to stream over his surroundings.");
        cls();
        prntD("     "+hero.name() + " stepped out of the vehicle and looked "
                "upward, staring \n"
                "at the massive stone fortress shadowing overhead. The walls \n"
                "were featureless, aside from a single wooden door and two\n"
                "torches lighting its sides.");
        cls();
        prntD("     “The arena” is what they called it. Not a very creative \n"
                "name, but it was simple and defined its purpose."); 
        cls();
        prntD("     It was a coliseum of death, where participants would \n"
                "fight a series of foes in order to unbind themselves to "
                "their\n"
                "overruling gods. ");
        cls();
        prntD("     The rules of the arena were clear and simple: Win five \n"
                "fights and you earn your freedom.");
        cls();
        prntD("     The history of the monument was shrouded in mystery. No\n"
                "one even knows where it came from.");
        cls();
        prntD("     When the arena was first discovered, people treated it "
                "with\n"
                "scorn and regarded the structure as an unholy monument, but\n"
                "once the revelation happened and people discovered that they\n"
                "could rid themselves of their eternal suffering, it became\n"
                "their one chance at salvation.");
        cls();
        prntD("The wooden doors swung open, as if beckoning " + 
                hero.name() + " through.");
        cls();
        prntD("Reluctantly, he stepped passed the threshold into the halls \n"
                "of the arena.");
        cls();
    
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
            delay(7);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        
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
            delay(4);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(4);
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
        delay(4);
        
    
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
            delay(7);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        //Increase player inventory
        hero.incInv(4);
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 22
        //Set checkpoint to chapter 3
        rpg.setChckpt(3);
        
        //Save game
        if(!rpg.save(hero)){
            //Prompt if error
            cout <<"Error: Failed to save game!" <<endl;
            //Delay text
            delay(4);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(4);
        }
        //Chapter 3 function
        chp3(hero, rpg);
    }
    
}
void chp3(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //If scene not completed
    if(rpg.getCmplte() < 23){
        //Initiate dialogue
        cout <<"Chapter 3: Changes" <<endl;
        delay(4);
        
    
    }
    //Add percentage to game completion for scene
    rpg.modCmplte(1); //Total: 23
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"You died!" <<endl <<"Game Over!" <<endl;
            //Delay text
            delay(7);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        //Increase player inventory
        hero.incInv(5);
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 33
        //Set checkpoint to chapter 4
        rpg.setChckpt(4);
        
        //Save game
        if(!rpg.save(hero)){
            //Prompt if error
            cout <<"Error: Failed to save game!" <<endl;
            //Delay text
            delay(4);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(4);
        }
        //Chapter 4 function
        chp4(hero, rpg);
    }
    
}
void chp4(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //If scene not completed
    if(rpg.getCmplte() < 34){
        //Initiate dialogue
        cout <<"Chapter 3: Changes" <<endl;
        delay(4);
        
    
    }
    //Add percentage to game completion for scene
    rpg.modCmplte(1); //Total: 34
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"You died!" <<endl <<"Game Over!" <<endl;
            //Delay text
            delay(7);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 44
        //Set checkpoint to chapter 5
        rpg.setChckpt(5);
        
        //Save game
        if(!rpg.save(hero)){
            //Prompt if error
            cout <<"Error: Failed to save game!" <<endl;
            //Delay text
            delay(4);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(4);
        }
        //Chapter 5 function
        chp5(hero, rpg);
    }
    
}
void chp5(Player&hero, Game&rpg){
    //Flag for level completion
    bool lvComp = false;
    
    //If scene not completed
    if(rpg.getCmplte() < 45){
        //Initiate dialogue
        cout <<"Chapter 3: Changes" <<endl;
        delay(4);
        
    
    }
    //Add percentage to game completion for scene
    rpg.modCmplte(1); //Total: 45
    
    //Load level
    level(hero, rpg, lvComp);
    
    //If level was not completed
    if(!lvComp){
        //If the player died
        if(hero.dead()){
            //Prompt game over
            cout <<"You died!" <<endl <<"Game Over!" <<endl;
            //Delay text
            delay(7);
        }
        
        //Return to main
        return;
    }
    else{
        //Dialogue
        
        
        //Increment percentage completed
        rpg.modCmplte(10); //Total: 55
        //Set checkpoint to chapter 0
        rpg.setChckpt(0);
        
        //Save game
        if(!rpg.save(hero)){
            //Prompt if error
            cout <<"Error: Failed to save game!" <<endl;
            //Delay text
            delay(4);
        }
        else{
            //Prompt if successful
            cout <<"Game saved." <<endl;
            //Delay text
            delay(4);
        }
        //Epilogue
        cout <<"The End" <<endl;
        //Delay text
        delay(10);
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
    time *= 100000000;
    //Delay the text for the indicated time
    for(int i = 0; i < time; i++){}
}