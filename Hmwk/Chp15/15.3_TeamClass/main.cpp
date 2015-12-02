/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on November 28, 2015, 7:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Emplye.h"
#include "Wrkr.h"

using namespace std;

//Team leader class inherited from worker
class Team: public Wrkr{
private:
    float tMBnus, tCHrs; //Team leader monthly bonus and current training hours
    int tMHrs; //Team leader mandatory training hours
    
public:
    Team(); //Base constructor
    Team(float, int, float); //Constructor with parameters
    
    void stBnus(float); //Sets value to monthly bonus
    void stMHrs(int); //Sets value to maximum required hours
    void stCHrs(float); //Sets value to current training hours
    
    float gtBnus(); //Returns monthly bonus
    int gtMHrs(); //Returns mandatory training hours
    float gtCHrs(); //Returns the current training hours
    
    void addHrs(float); //Adds hours to the current total
};

void fillTeam(Team&, string, int, string, int, float, float , int, float);
void outTeam(Team);

/*
 * 
 */
int main(int argc, char** argv) {
    Team leadr; //Team leader object
    string name, date; //Team leader name and hire date
    float bnus, cHrs, rate; //Team leader bonus, current hours, and rate
    int mHrs, shft, num; 
    bool error; //Error flag
    
    do{
        error = false; //Default to no error
   
        
        cout <<setprecision(2) <<fixed <<"Enter Team leader name: ";
        cin >> name;
        cout <<"Enter employee number: ";
        cin >> num;
        cout <<"Enter the hire date(mm/dd/yyyy): ";
        cin >> date;
        cout <<"Enter the shift type(1 for day; 2 for night): ";
        cin >> shft;
        cout <<"Enter rate of pay: ";
        cin >> rate;
        cout <<"Enter monthly bonus amount: ";
        cin >> bnus;
        cout <<"Enter total mandatory training hours: ";
        cin >> mHrs;
        cout <<"Enter current total training hours: ";
        cin >> cHrs;
        
        
        if(date.size() != 10){
            error = true;
            cout <<endl <<endl 
                    <<"Invalid date! Format must be mm/dd/yyyy" <<endl;
        }
        else{
            cout <<endl <<endl;
        }
        
    }while(error);
    
    fillTeam(leadr, name, num, date, shft, rate, bnus, mHrs, cHrs);
    outTeam(leadr);
    
    return 0;
}

Team::Team(){
    tMBnus = 0.00; //Monthly bonus
    tMHrs = 0; //Mandatory training hours
    tCHrs = 0.00; //Current training hours
}
Team::Team(float bnus, int mHrs, float cHrs){
    tMBnus = bnus; //Defined monthly bonus
    tMHrs = mHrs; //Defined mandatory hours
    tCHrs = cHrs; //Defined current hours
}
void Team::stBnus(float bnus){
    tMBnus = bnus; //Sets monthly bonus
}
void Team::stMHrs(int mHrs){
    tMHrs = mHrs; //Sets mandatory hours
}
void Team::stCHrs(float cHrs){
    tCHrs = cHrs; //Sets current training hours
}
float Team::gtBnus(){
    return tMBnus; //Returns the monthly bonus
}
int Team::gtMHrs(){
    return tMHrs; //Returns the mandatory hours
}
float Team::gtCHrs(){
    return tCHrs; //Returns the current hours
}
void Team::addHrs(float hrs){
    tCHrs += hrs; //Adds hours to the current training hours
}

void fillTeam(Team &leadr, string name, int eNum, string date, int shft,
        float rate, float bnus, int mHrs, float cHrs){
    leadr.stName(name); //Sets the name of the team leader
    leadr.stNum(eNum); //Sets employee number
    leadr.stDate(date); //Sets date of hire
    leadr.stShft(shft); //Sets shift type
    leadr.stRate(rate); //Sets rate of pay
    leadr.stBnus(bnus); //Sets monthly bonus
    leadr.stMHrs(mHrs); //Sets mandatory training hours
    leadr.stCHrs(cHrs); //Sets current training hours
}
void outTeam(Team leadr){
    cout <<"** Employee Information **" <<endl
            <<"Name: " <<leadr.gtName() <<endl
            <<"Number: " <<leadr.gtNum() <<endl
            <<"Hire Date: " <<leadr.gtDate() <<endl
            <<"Shift type: " <<leadr.gtShft() <<endl
            <<"Rate of pay: " <<leadr.gtRate() <<endl
            <<"Monthly bonus: " <<leadr.gtBnus() <<endl
            <<"Mandatory Training hours: " <<leadr.gtMHrs() <<endl
            <<"Current Training hours: " <<leadr.gtCHrs() <<endl;
}

