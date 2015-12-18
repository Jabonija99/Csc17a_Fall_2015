/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on December 13, 2015, 11:30 AM
 */

#include <cstdlib>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//User Libraries

//Problem 1
#include "Prob1Random.h"
//Problem 2
#include "Prob2Sort.h"
//Problem 3
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
//Problem 4
#include "AccSve.h"
//Problem 5
#include "Emplye.h"





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
    
    //Retrieve words from text
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    //Create sorted array
    char *zc=rc.sortArray(ch2p,column,ascending);
    for(int i=0;i<10;i++)
    {
            for(int j=0;j<16;j++)
            {
                    cout<<zc[i*16+j];
            }
    }
    delete []zc;
    cout<<endl;
    
    char delay;
    cout <<"Enter anything to continue: ";
    cin >> delay;
}

void problem3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                    cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
    
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
            for(int j=0;j<=cols;j++)
            {
                    cout<<augT[i*(cols+1)+j]<<" ";
            }
            cout<<endl;
    }
}


void problem4(){
    AccSve mine(-300);
    
    for(int i=1;i<=10;i++)
    {
            mine.transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.totalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
        
    char delay;
    cout <<"Enter any number to continue: ";
    cin >> delay;
}



void problem5(){
    Emplye Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Emplye Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();

    char delay;
    cout <<"Enter anything to continue: ";
    cin >> delay;
}



void problem6(){
    cout <<"a) 0.125" <<endl
            <<"Binary: " <<0.001 <<endl
            <<"Octal: " <<0.1 <<endl
            <<"Hex: " << 0.2 <<endl <<endl;
    
    cout <<"b) 0.3" <<endl
            <<"Binary: " <<"0.01001" <<endl
            <<"Octal: " <<"0.2314" <<endl
            <<"Hex: " <<"0.4CC" <<endl <<endl;
    
    cout <<"c) 89.3" <<endl
            <<"Binary: " <<"1011001.01001" <<endl
            <<"Octal: " <<"131.2314" <<endl
            <<"Hex: " <<"59.4CC" <<endl <<endl;
    
    char delay;
    cout <<"Enter anything to continue: ";
    cin >> delay;
}


void cls(){
    for(int i = 0; i < 20; i++){
        cout <<endl;
    }
}