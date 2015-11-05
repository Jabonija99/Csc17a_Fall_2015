/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on November 3, 2015, 4:25 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

class Date{
private:
    int dDay, dDate, dMnth;
    string dMnths[12] = {"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
public:
    Date(int);
    void print();

};

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    cout <<"Enter a number of days: ";
    cin >> num;
    
    Date usrDte(num);
    
    usrDte.print();
    
    return 0;
}

Date::Date(int days){
    dDay = days;
    //dMnth = days/32;
    //dDate = (days%32);
}

void Date::print(){
    //January
    dMnth
    
    cout <<"Day " <<dDay <<" would be " <<dMnths[dMnth] <<" " <<dDate <<endl;
}
