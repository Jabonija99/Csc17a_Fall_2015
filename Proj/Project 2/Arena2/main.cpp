/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on December 10, 2015, 6:25 PM
 */

#include <cstdlib> //General functions
#include <iostream> //Input/Output
#include <iomanip> //Input/Output Manipulation
#include <fstream> //Read/Write to files

using namespace std;

#include "Game.h" //Game class
#include "Player.h" //Player class

#include "Brute.h" //Brute enemy
#include "Mage.h" //Mage enemy
#include "Knght.h" //Knight enemy
#include "Assn.h" //Assassin enemy
#include "Boss.h" //Boss enemy


//Base stats
enum BSTAT{
    MHLTH, //Max health
    CHLTH, //Current health
    STMNA, //Stamina
    STR, //Strength
    DEF, //Defense
    ACC, //Accuracy
    DEX, //Dexterity
    INT, //Intelligence
    LUC, //Luck
    MEXP, //Max exp
    CEXP, //Current exp
    LVL, //Level
    SSIZE //Stat size
};

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


//Templated function
template<class T>
//Battle ui
void bttlUi(Player&, T&, bool&);
//Name and enemy ui
void ui(string, Player, Enemy);
//Use item function
void use(Player&, Enemy, bool&);

//Story chapters
void chp1(Player&, Game&);
void chp2(Player&, Game&);
void chp3(Player&, Game&);
void chp4(Player&, Game&);
void chp5(Player&, Game&);

//Player functions
//Displays player stats
void dispStat(Player);
//Level up player
void lvlUp(Player &);



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
        //Output main menu
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
        //Receive user input
        cin >> userIn;

        //Switch user input
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
    
    //Give a friendly farewell
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
    
    //try to save the game
    try{
        //If the game fails to save
        if(!rpg.save(hero)){
            //Throw an exception
            throw -1;
        }
        
        //Prompt successful save
        cout <<"Gave saved." <<endl;
        //Delay text
        delay(4);
        //Clear screen
        cls();
        
        //Begin game
        chp1(hero, rpg);
    
    }catch(...){
        //Prompt user if error
        cout <<"Error: Failed to create save file!" <<endl;
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
    
    //Try to load game
    try{
        //If the game fails to load
        if(!rpg.load(hero,name)){
            //Throw an exception
            throw -1;
        }
        
        //Prompt user when successful
        cout <<"Load successful"<<endl;
        //Delay text
        delay(4);
        //Clear screen
        cls();
        
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
            default:
                //Return to main
                return;
        }
    
    }catch(...){
            //Prompt user for error
            cout <<"Error: File does not exist" <<endl;
            delay(4);
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

        //Calculates health difference
        int hpDif = (hero.gtStat(MHLTH) - hero.gtStat(CHLTH));
        
        //Processes user choice
        switch(ans){
            case 1:
                //Clear screen
                cls();
                //Heals player
                hero.mStat(CHLTH, hpDif);
                
                //Try to save game
                try{
                    //If the game does not save successfully
                    if(!rpg.save(hero)){
                        //Throw exception
                        throw -1;
                    }
                    
                    //Prompt if successful
                    cout <<"Save successful!" <<endl;
                    //Delay text
                    delay(4);
                    
                }catch(...){
                    //Prompt if error
                    cout <<"Error: Failed to save game!" <<endl;
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
                dispStat(hero);
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
    
    //Create enemy objects
    Brute foe1;
    Mage foe2;
    Assn foe3;
    Knght foe4;
    Boss foe5;
    
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
    //User input
    int ans;
    //Quit flag
    bool quit = false;
    //Structure object pointer
    Inv<int> *sInv;
    //Create new inventory
    sInv = new Inv<int>;
    
    //Loads inventory based on checkpoint
    switch(rpg.getChckpt()){
        case 2:
            //Sets size
            sInv->size = 1;
            //Create stock
            sInv->stck = new int[sInv->size];
            //Add Healing poition
            sInv->stck[0] = 1;
            break;
        case 3:
            //Sets size
            sInv->size = 2;
            //Create stock
            sInv->stck = new int[sInv->size];
            //Add Healing poition
            sInv->stck[0] = 1;
            //Add Healing glove
            sInv->stck[1] = 2;
            break;
        case 4:
            //Sets size
            sInv->size = 2;
            //Create stock
            sInv->stck = new int[sInv->size];
            //Add Healing poition
            sInv->stck[0] = 1;
            //Add Healing glove
            sInv->stck[1] = 2;
            break;
        case 5:
            //Sets size
            sInv->size = 2;
            //Create stock
            sInv->stck = new int[sInv->size];
            //Add Healing poition
            sInv->stck[0] = 1;
            //Add Healing glove
            sInv->stck[1] = 2;
            break;
        default:
            return;
    }
    
    //Loop menu
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
                //Verifies that the user can purchase
                if(rpg.getChckpt() > 1){
                    //If healing potion fails to be set
                    if(!hero.setItm(1)){
                        //Prompt full inventory
                        cout <<"Inventory full!" <<endl;
                        //Delay text
                        delay(4);
                    }
                    else{
                        //Output successful set
                        cout <<hero.gtName() <<" purchased health potions!" 
                                <<endl;
                        //Delay text
                        delay(4);
                    }
                } 
                break;
            case 2:
                //Verifies that item is unlocked
                if(rpg.getChckpt() > 2){
                    //If healing glove fails to be set
                    if(!hero.setItm(2)){
                        //Prompt full inventory
                        cout <<"Inventory full!" <<endl;
                        //Delay text
                        delay(4);
                    }
                    else{
                        //Output successful set
                        cout <<hero.gtName() <<" purchased the mystic glove!" 
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
    //Repeat until the user quits
    }while(!quit);
    
    //Deallocate stock from memory
    delete sInv->stck;
    //Deallocate inventory
    delete sInv;
}

template<class T>
void bttlUi(Player &hero,T &foe, bool &lvComp){
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
                cout <<hero.gtName() <<" is stunned!" <<endl;
                //Reset stunned state
                pstun = false;
                //Delay text
                delay(5);
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
                        cout <<hero.gtName() <<" attacks!" <<endl;
                        //Delay text
                        delay(5);

                        //If the enemy is blocking
                        if(foe.blck()){
                            //Calculate stun chances
                            if(hero.stun()){
                                //Prompt if stunned
                                cout <<"The attack was reflected and left " 
                                        <<hero.gtName() <<" stunned!" <<endl;
                                //Flag stunned state
                                pstun = true;
                                //Delay text
                                delay(5);
                            }
                            else{
                                //Print reduced damage
                                cout <<foe.gtName() <<" receives " 
                                        <<foe.dmged(hero.attck() - 2) 
                                        <<" damage!" <<endl;
                                //Delay text
                                delay(5);
                            }

                            //Reset enemy guard state
                            foe.guard(false);
                        }
                        else{
                            //Print damage
                            cout <<foe.gtName() <<" receives " 
                                    <<foe.dmged(hero.attck())
                                    <<" damage!" <<endl;
                            //Delay text
                            delay(5);
                        }

                        //Reset player guard state
                        hero.guard(false);
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        //Set player guard state
                        hero.guard(true);
                        cout <<hero.gtName() <<" raises his guard!" <<endl;
                        //Delay text
                        delay(5);
                        break;
                    case 3:
                        //Call item use function
                        use(hero, foe, inVal);
                        //Reset player guard state
                        hero.guard(false);
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
                //output stunned state
                foe.dStnnd();
                //Reset stun flag
                estun = false;
                //Delay text
                delay(6);
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
                        foe.dAtt();
                        //Delay text
                        delay(5);
                        //If the player is blocking
                        if(hero.blck()){
                            //Calculate stun chances
                            if(foe.stun()){
                                //Prompt if stunned
                                foe.dStn();
                                estun = true;
                                //Delay text
                                delay(5);
                            }
                            else{
                                //Print reduced damage
                                cout <<hero.gtName() <<" receives " 
                                        <<hero.dmged(foe.attck() - 2) 
                                        <<" damage!" <<endl;
                                //Delay text
                                delay(5);
                            }

                            //Reset block status
                            hero.guard(false);
                        }
                        else{
                            //Print damage
                            cout <<hero.gtName() <<" receives " 
                                    <<hero.dmged(foe.attck())
                                    <<" damage!" <<endl;
                            //Delay text
                            delay(5);
                        }
                        
                        //Reset enemy guard state
                        foe.guard(false);
                        break;
                    case 2:
                        //Clear screen
                        cls();
                        //Print Guard ui
                        ui("Guard", hero, foe);
                        //Set enemy guard state
                        foe.guard(true);
                        //Output defense dialogue
                        foe.dDef();
                        //Delay text
                        delay(5);
                        break;
                    case 3:
                        //Clear screen
                        cls();
                        //Print Action ui
                        ui("Heal", hero, foe);
                        //Display healing value
                        cout <<foe.gtName() <<" heals " <<foe.heal() <<"!" <<endl;
                        
                        //Reset enemy guard state
                        foe.guard(false);
                        
                        //Delay text
                        delay(5);
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
            cout << foe.gtName() <<" has fallen!" <<endl;
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
        cout <<hero.gtName() <<" earned " <<foe.gtStat(MEXP) <<" experience!" <<endl;
        //Delay text
        delay(4);
        
        //If the set exp levels up player
        if(hero.setExp(foe.gtStat(MEXP))){
            //Prompt  level up
            cout<<hero.gtName() <<" leveled up!" <<endl;
            //Delay text
            delay(4);
            //Initiate level up screen
            lvlUp(hero);
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
            <<left <<hero.gtName() 
            <<right <<setw(52)
            //Enemy name
            <<foe.gtName() <<endl
            //Hero current/max hp
            <<left <<"HP: " <<hero.gtStat(CHLTH) <<"/" <<hero.gtStat(MHLTH) 
            <<right <<setw(38) 
            //Enemy current/max hp
            <<foe.gtStat(CHLTH) <<"/" <<foe.gtStat(MHLTH) <<" :HP"<<endl
            //Hero stamina
            <<left <<"Stamina: " <<hero.gtStat(STMNA) 
            <<right <<setw(36)
            //Enemy stamina
            <<foe.gtStat(STMNA) <<" :Stamina" <<endl
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
    if(hero.invSze() < 1){
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
        for(int i = 0; i < hero.invSze(); i++){
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
                if(hero.invSze() > 0){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.gtName() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.gtName() <<" heals 25 hp!" <<endl;
                            //Modify current health
                            hero.mStat(CHLTH, 25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.gtName() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.gtName() <<" heals " <<hero.heal() 
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
                if(hero.invSze() > 1){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.gtName() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.gtName() <<" heals 25 hp!" <<endl;
                            //Modify current health
                            hero.mStat(CHLTH, 25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.gtName() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.gtName() <<" heals " <<hero.heal() 
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
                if(hero.invSze() > 2){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.gtName() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.gtName() <<" heals 25 hp!" <<endl;
                            //Modify current health
                            hero.mStat(CHLTH, 25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.gtName() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.gtName() <<" heals " <<hero.heal() 
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
                if(hero.invSze() > 3){
                   //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.gtName() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.gtName() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.mStat(CHLTH, 25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.gtName() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.gtName() <<" heals " <<hero.heal() 
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
                if(hero.invSze() > 4){
                    //Use item
                    switch(hero.getItm(ans-1)){
                        //If the item is 1
                        case 1:
                            //Use HP potion
                            cout <<hero.gtName() <<" uses health potion!" <<endl;
                            //Remove item
                            hero.remItm(ans - 1);
                            //Delay text
                            delay(4);
                            cout <<hero.gtName() <<" heals 25 hp!" <<endl;
                            //Increment health
                            hero.mStat(CHLTH, 25);
                            //Delay text
                            delay(4);
                            break;
                        //If item 2
                        case 2:
                            //Use healing glove
                            cout <<hero.gtName() <<" casts the mystic glove!" 
                                    <<endl;
                            //Delay text
                            delay(4);
                            //Apply healing effects
                            cout <<hero.gtName() <<" heals " <<hero.heal() 
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
        
        cout <<"Chapter 1: Arrival" <<endl;
        delay(6);
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
        
        //Prompt shop unlock
        cout <<"Shop unlocked!" <<endl;
        delay(4);
        cout <<"Shop now sells health potions!" <<endl;
        delay(6);
        cls();
        
        //Prompt inventory increase
        cout <<"Pack earned!" <<endl;
        delay(4);
        cout <<"Inventory size increased to 3!" <<endl;
        delay(6);
        cls();

        //Increase inventory by 3
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
        //Prompt glove earned
        cout <<"The mystic's glove vanishes from the floor!" <<endl;
        delay(7);
        cout <<"Mystic glove unlocked!" <<endl;
        delay(5);
        cls();
        
        //Prompt inventory increase
        cout <<"Inventory increased to 4!" <<endl;
        delay(6);
        cls();
        
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
        cout <<"Chapter 3: Great Armor" <<endl;
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
        //Prompt inventory increase
        cout <<"Inventory increased to 5!" <<endl;
        delay(5);
        cls();
        
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
        cout <<"Chapter 4: Dark knife" <<endl;
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
        cout <<"Chapter 5: Final fight" <<endl;
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


//Player functions========================================
void dispStat(Player hero){
    bool quit = false;
    int ans = 0;
    do{
        //Outputs stat display screen
        cout <<"=========== Profile ============" <<endl
                <<"--------------------------------" <<endl
                <<"Name: " <<hero.gtName() <<setw(10) 
                <<"Lvl: " <<hero.gtStat(LVL) <<endl
                <<"Hp: " <<hero.gtStat(CHLTH) <<"/" <<hero.gtStat(MHLTH)
                <<setw(10) <<"Exp: " <<hero.gtStat(CEXP) 
                <<"/" <<hero.gtStat(MEXP) <<endl
                <<"Stamina: " <<hero.gtStat(STMNA) <<endl
                <<"--------------------------------" <<endl
                <<setw(18) <<"Stats" <<endl
                <<"--------------------------------" <<endl
                <<"Str: " <<hero.gtStat(STR) <<endl
                <<"Def: " <<hero.gtStat(DEF) <<endl
                <<"Acc: " <<hero.gtStat(ACC) <<endl
                <<"Dex: " <<hero.gtStat(DEX) <<endl
                <<"Int: " <<hero.gtStat(INT) <<endl
                <<"Luc: " <<hero.gtStat(LUC) <<endl
                <<"--------------------------------" <<endl
                <<"1] Inventory" <<endl
                <<"2] Exit" <<endl
                <<"================================" <<endl;
        cout <<"Select: ";
        cin >> ans;
        
        switch(ans){
            case 1:
                //Output inventory display screen
                do{
                    cls();
                    cout <<"=========== Profile ============" <<endl
                        <<"--------------------------------" <<endl
                        <<"Name: " <<hero.gtName() <<setw(10) 
                        <<"Lvl: " <<hero.gtStat(LVL) <<endl
                        <<"Hp: " <<hero.gtStat(CHLTH) <<"/" <<hero.gtStat(MHLTH)
                        <<setw(10) <<"Exp: " <<hero.gtStat(CEXP) 
                        <<"/" <<hero.gtStat(MEXP) <<endl
                        <<"Stamina: " <<hero.gtStat(STMNA) <<endl
                        <<"--------------------------------" <<endl
                        <<setw(10) <<"Inventory: "  <<hero.invSze() 
                        <<"/" <<hero.invCap() <<endl
                        <<"--------------------------------" <<endl;
                    
                    try{
                        if(hero.invCap() <= 0){
                            throw -1;
                        }
                        
                        //Output inventory
                        for(int i = 0; i < hero.invCap(); i++){
                            switch(hero.getItm(i)){
                                //if item # 1
                                case 1:
                                    //Output health potion
                                    cout <<i+1 <<"] Health potion" <<endl; 
                                    break;
                                //if item # 2
                                case 2:
                                    //Output mystic glove
                                    cout <<i+1 <<"] Mystic Glove" <<endl; 
                                    break;
                                //Else
                                default:
                                    //Output blank slot
                                    cout <<i+1 <<"] " <<endl;
                                    break;
                            }
                        }
                        
                    }catch(...){
                        //Prompt empty inventory
                        cout <<"No Inventory" <<endl;
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
void lvlUp(Player &hero){
    int pts = 10, pIn; //Points to distribute and player input
    int stPts[6] = {0, 0, 0, 0, 0, 0}; //Stat pts
   
    string quit; //String for confirming quit
    
    hero.mStat(LVL, 1); //Increment lvl up
    
    do{
        //Displays level up screen
        cout <<"Distribute your stats! Points: " <<pts <<endl
                <<"---------------------------------------" <<endl
                <<"[1] Str: " <<hero.gtStat(STR) <<" + (" <<stPts[0] <<")" <<endl
                <<"[2] Def: " <<hero.gtStat(DEF) <<" + (" <<stPts[1] <<")" <<endl
                <<"[3] Acc: " <<hero.gtStat(ACC) <<" + (" <<stPts[2] <<")" <<endl
                <<"[4] Dex: " <<hero.gtStat(DEX) <<" + (" <<stPts[3] <<")" <<endl
                <<"[5] Int: " <<hero.gtStat(INT) <<" + (" <<stPts[4] <<")" <<endl
                <<"[6] Luc: " <<hero.gtStat(LUC) <<" + (" <<stPts[5] <<")" <<endl
                <<"---------------------------------------" <<endl;
        
        
        if(pts > 0){ //If the user still has points to distribute
            //User selects a stat to raise
            cout <<"Select a stat: "; 
            cin >> pIn;
            
            //Distributes the point
            switch(pIn){
                case 1: //Strength
                    stPts[0]++;
                    pts--;
                    break;
                    
                case 2: //Defense
                    stPts[1]++;
                    pts--;
                    break;
                    
                case 3: //Accuracy
                    stPts[2]++;
                    pts--;
                    break;
                    
                case 4: //Dexterity
                    stPts[3]++;
                    pts--;
                    break;
                    
                case 5: //Intelligence
                    stPts[4]++;
                    pts--;
                    break;
                    
                case 6: //Luck
                    stPts[5]++;
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
                for(int i = 0; i < 6; i++){
                    stPts[i] = 0;
                }
                
                //Reset points
                pts = 10;
            }
            else{ //If the user does select to quit
                //Modify max health
                hero.mStat(MHLTH, 10);
                //Modify player stamina
                hero.mStat(STMNA, 5);
                //Modify the stats by the selected values
                for(int i = 0; i < 6; i++){
                    hero.mStat(i+3, stPts[i]);
                }
            }
        }
                
        cls();
    }while(tolower(quit[0]) != 'y');

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
