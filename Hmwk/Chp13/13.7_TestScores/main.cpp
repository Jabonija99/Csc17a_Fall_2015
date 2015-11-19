/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on November 18, 2015, 9:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Test score class
class Tstscr{
private:
    //Test score 1, 2, and 3
    int tScre1, tScre2, tScre3;
    //Test score average
    float tAvg;
public:
    //
    Tstscr();
    Tstscr(int, int, int);
    
    int gtScre1();
    int gtScre2();
    int gtScre3();
    
    void stScre1(int);
    void stScre2(int);
    void stScre3(int);
    float screAvg();
};

/*
 * 
 */
int main(int argc, char** argv) {
    int scre1, scre2, scre3;
    
    cout <<"Enter test score 1: ";
    cin >> scre1;
    cout <<"Enter test score 2: ";
    cin >> scre2;
    cout <<"Enter test score 3: ";
    cin >> scre3;
    
    Tstscr math1(scre1, scre2, scre3);
    
    cout  <<endl <<endl <<left <<setprecision(2) <<fixed <<setw(15) 
            <<"Score 1" <<setw(15) <<"Score 2" <<setw(15) <<"Score 3" 
            <<setw(15) <<"Average" <<endl
            <<"------------------------------------------------------------"
            <<endl <<setw(15) <<math1.gtScre1() <<setw(15) <<math1.gtScre2()
            <<setw(15) <<math1.gtScre3() <<setw(15) <<math1.screAvg() <<endl;
    
    
    
    return 0;
}

Tstscr::Tstscr(){
    tScre1 = 0;
    tScre2 = 0;
    tScre3 = 0;
}
Tstscr::Tstscr(int scre1, int scre2, int scre3){
    tScre1 = scre1;
    tScre2 = scre2;
    tScre3 = scre3;
}

int Tstscr::gtScre1(){
    return tScre1;
}
int Tstscr::gtScre2(){
    return tScre2;
}
int Tstscr::gtScre3(){
    return tScre3;
}

void Tstscr::stScre1(int scre){
    tScre1 = scre;
}
void Tstscr::stScre2(int scre){
    tScre2 = scre;
}
void Tstscr::stScre3(int scre){
    tScre3 = scre;
}
float Tstscr::screAvg(){
    int total = tScre1+ tScre2 + tScre3;
    tAvg = static_cast<float>(total)/3.0;
    return tAvg;
}
