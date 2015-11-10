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
    int days = dDay;
    int cDay = days;
    
    days-=31;
    if(days < 1){
        //January
        dMnth = 0;
        dDate = cDay%32;
    }
    else{
        cDay -= 31;
        days-=28;
        if(days < 1){
            //February
            dMnth = 1;
            dDate = cDay%29;
        }
        else{
            cDay -=28;
            days -=31;
            if(days < 1){
                //March
                dMnth = 2;
                dDate = cDay%32;
            }
            else{
                cDay -=31;
                days -=30;
                if(days < 1){
                    //April
                    dMnth = 3;
                    dDate = cDay%31;
                }
                else{
                    cDay -=30;
                    days -=31;
                    if(days < 1){
                        //May
                        dMnth = 4;
                        dDate = cDay%32;
                    }
                    else{
                        cDay -=31;
                        days -=30;
                        if(days < 1){
                            //June
                            dMnth = 5;
                            dDate = cDay%31;
                        }
                        else{
                            cDay -=30;
                            days -=31;
                            if(days < 1){
                                //July
                                dMnth = 6;
                                dDate = cDay%32;
                            }
                            else{
                                cDay -=31;
                                days -=31;
                                if(days < 1){
                                    //August
                                    dMnth = 7;
                                    dDate = cDay%32;
                                }
                                else{
                                    cDay -=31;
                                    days -=30;
                                    if(days < 1){
                                        //September
                                        dMnth = 8;
                                        dDate = cDay%31;
                                    }
                                    else{
                                        cDay -=30;
                                        days -=31;
                                        if(days < 1){
                                            //October
                                            dMnth = 9;
                                            dDate = cDay%32;
                                        }
                                        else{
                                            cDay -=31;
                                            days -=30;
                                            if(days < 1){
                                                //November
                                                dMnth = 10;
                                                dDate = cDay%31;
                                            }
                                            else{
                                                cDay -=30;
                                                days -=31;
                                                if(days < 1){
                                                    //December
                                                    dMnth = 11;
                                                    dDate = cDay%32;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    
    }
    
    cout <<"Day " <<dDay <<" would be " <<dMnths[dMnth] <<" " <<dDate <<endl;
}
