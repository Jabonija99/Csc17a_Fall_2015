/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 14, 2015, 10:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

class Inv{
private:
    //Item number, and quantity
    int iNItm, iQty;
    //Item cost and total
    float iCst, iTot;
    
public:
    //Constructor
    Inv();
    //Constructs object with item number, quantity, and cost
    Inv(int,int,float);
    
    void setNItm(int); //Set item number
    void setQty(int); //Set item quantity
    void setCst(float); //Set item cost
    void setTot(); //Calculates total
    
    int getNItm(); //Returns item number
    int getQty(); //Returns item quantity
    float getCst(); //Returns item cost
    float getTot(); //Returns item total  
};

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Inv stock;
    float ans;
    
    cout <<"Enter item number: ";
    cin >> ans;
    stock.setNItm(static_cast<int>(ans));
    
    cout <<"Enter quantity: ";
    cin >> ans;
    stock.setQty(static_cast<int>(ans));
    
    cout <<"Enter item cost: ";
    cin >> ans;
    stock.setCst(ans);
    
    
    
    
    
    

    return 0;
}

Inv::Inv(){
    //Initialize all variables to zero
    iNItm = 0; //Item number
    iQty = 0; //Quantity
    iCst = 0; //Cost
    iTot = 0; //Calculates total
}

Inv::Inv(int nItm, int qty, float cst){
    //Set indicated data
    iNItm = nItm; //Item number
    iQty = qty; //Quantity
    iCst = cst; //Cost
    setTot(); //Calculates total
}

void Inv::setNItm(int nItm){
    //Set item number
    iNItm = nItm;
}

void Inv::setQty(int qty){
    //Set item quantity
    iQty = qty;
}

void Inv::setCst(float cst){
    //Set item cost
    iCst = cst;
}

void Inv::setTot(){
    //Calculates total cost
    iTot = static_cast<float>(iQty) * iCst;
}

int Inv::getNItm(){
    //Returns item number
    return iNItm;
}

int Inv::getQty(){
    //Returns item quantity
    return iQty;
}

float Inv::getCst(){
    //Return item cost
    return iCst;
}

float Inv::getTot(){
    //Return item total
    return iTot;
}