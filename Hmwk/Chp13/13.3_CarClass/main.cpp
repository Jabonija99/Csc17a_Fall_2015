/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on November 17, 2015, 10:04 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Car{
private:
    //Car model year and speed
    int cMdl,cSpd;
    //Car make
    string cMake;
public:
    Car(int, string);
    
    int gtMdl();
    int gtSpd();
    string gtMke();
    
    void accel();
    void brake();
    
};

/*
 * 
 */
int main(int argc, char** argv) {
    int model;
    string make;
    
    cout <<"Enter the model number: ";
    cin >> model;
    
    cout <<"Enter the make: ";
    cin >> make;
    
    Car usrCar(model, make);
    
    for(int i = 0; i < 5; i++){
        usrCar.accel();
        cout <<usrCar.gtMke() <<" (" <<usrCar.gtMdl() <<") Speed: "
                <<usrCar.gtSpd() <<endl;
    }
    
    for(int i = 0; i < 5; i++){
        usrCar.brake();
        cout <<usrCar.gtMke() <<" (" <<usrCar.gtMdl() <<") Speed: "
                <<usrCar.gtSpd() <<endl;
    }
    
    return 0;
}

Car::Car(int model, string make){
    cMdl = model;
    cMake = make;
    cSpd = 0;
}

int Car::gtMdl(){
    return cMdl;
}

int Car::gtSpd(){
    return cSpd;
}

string Car::gtMke(){
    return cMake;
}

void Car::accel(){
    cSpd += 5;
}

void Car::brake(){
    cSpd -= 5;
    if(cSpd < 0){
        cSpd = 0;
    }
}