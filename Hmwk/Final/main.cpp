/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on December 13, 2015, 11:30 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//User Libraries
#include "Prob1Random.h"

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);

void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Clear screen function
void cls();

/*
 * 
 */

int main(int argv,char *argc[]){
    srand(time(0));
    
    //User input
    int inN;
    do{
        //Menu prompt
        Menu();
        //Receives user input
        inN=getN();
        //Runs problem based on input
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
        
        //Clear screen
        cls();
    //Repeat while input is = 1~6
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}
int getN(){
    int inN;
    cin>>inN;
    return inN;
}
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void problem1(){
    char n=5;
    char rndseq[]={16,34,57,79,127};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
            a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    char delay;
    cout <<"Enter any number to continue: ";
    cin >> delay;
    
}


void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;

    //Create a char template object
    Prob2Sort<char> rc;
    //set ascending order flag to true
    bool ascending=true;
    //Input file
    ifstream infile;
    
    //Open text file
    infile.open("Problem2.txt",ios::in);
    //Creates multidimensional array 10x16
    char *ch2=new char[10*16];
    //Pointer
    char *ch2p=ch2;
    
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
            for(int j=0;j<16;j++)
            {
                    cout<<zc[i*16+j];
            }
    }
    delete []zc;
    cout<<endl;
}

void problem3(){

}

void problem4(){

}
void problem5(){

}

void problem6(){

}


void cls(){
    for(int i = 0; i < 20; i++){
        cout <<endl;
    }
}