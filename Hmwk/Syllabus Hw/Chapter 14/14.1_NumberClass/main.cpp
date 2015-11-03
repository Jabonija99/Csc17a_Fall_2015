/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 3, 2015, 10:04 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Nums{
private:
    void error(); //Error output
    
    int nNum; //Number to translate
    //Words from 0 - 19
    string nWrd20[20] = {"zero","one","two","three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen"};
    //Words of ten multiples
    string nTens[8] = {"twenty","thirty","fourty","fifty","sixty","seventy",
    "eighty","ninety"};
    //Hundred word
    string nHnrd = "hundred";
    //Thousand word
    string nThsnd = "thousand";
public:
    //Constructor
    Nums(int);
    //Output words
    void print();
    

};

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    cout <<"Enter a number(0 ~ 9999): "<<endl;
    cin >> num;
    
    Nums wrdNum(num);
    
    wrdNum.print();

    return 0;
}

Nums::Nums(int num){
    if(num > -1){
        nNum = num;
    }
    else{
        error();
    }
}

void Nums::error(){
    cout <<"Invalid input! Number must be non negative!" <<endl;
}

void Nums::print(){
    //The individual digit values
    int dig1, dig2, dig3, dig4;
    
    //Separate the digits
    dig1 = (nNum/1000);
    dig2 = (nNum/100) - (dig1*10);
    dig3 = (nNum/10) - ((dig1*100)+(dig2*10));
    dig4 = nNum - ((dig1*1000)+(dig2*100)+(dig3*10));
    
    if(nNum < 20){
        cout <<nWrd20[dig4+(dig3*10)] <<endl;
    }
    else if(nNum < 100){
        cout <<nTens[dig3-2] <<" ";
        if(dig4 > 0){
            cout <<nWrd20[dig4];
        }
        cout <<endl;
    }
    else if(nNum < 1000){
        cout <<nWrd20[dig2] <<"-" <<nHnrd <<" "; 
        if(dig3 > 0){
            cout <<nTens[dig3-2] <<" ";
        }
        
        if(dig4 > 0){
            cout <<nWrd20[dig4];
        }
        cout <<endl;
    }
    else if(nNum < 10000){
        cout <<nWrd20[dig1] <<"-" <<nThsnd <<" ";
        if(dig2 > 0){
            cout <<nWrd20[dig2] <<"-" <<nHnrd <<" ";
        }
        
        if(dig3 > 0){
            cout <<nTens[dig3-2] <<" ";
        }
        
        if(dig4 > 0){
            cout <<nWrd20[dig4];
        }
        cout <<endl;
    }
    else{
        cout <<"Input Error! Number exceeds valid range(0 ~ 9999)!" <<endl;
    }
}