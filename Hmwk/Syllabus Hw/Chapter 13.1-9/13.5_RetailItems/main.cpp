/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 14, 2015, 9:40 AM
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//User libraries
#include "RItem.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    RItem itm1("Jacket", 12, 60.124);
    RItem itm2("Designer Jeans", 1, 7000.126);
    RItem itm3("Simple Shirt", 40, 24.95);
    
    cout <<left <<"===================================================" <<endl
            <<setw(15) <<"Item #" <<setw(15) <<"Description"
            <<setw(15) <<"BOH" <<setw(15) <<"Price" <<endl
            <<"--------------------------------------------------------" <<endl
            <<setw(15) <<"Item #1" <<setw(15) <<itm1.getDesc() 
            <<setw(15) <<itm1.getUnts() <<setw(15) <<itm1.getPrce()<<endl
            <<setw(15) <<"Item #2" <<setw(15) <<itm2.getDesc() 
            <<setw(15) <<itm2.getUnts() <<setw(15) <<itm2.getPrce()<<endl
            <<setw(15) <<"Item #3" <<setw(15) <<itm3.getDesc() 
            <<setw(15) <<itm3.getUnts() <<setw(15) <<itm3.getPrce()<<endl
            <<"--------------------------------------------------------" <<endl;
    return 0;
}
