/* 
 * File:   main.cpp
 * Author: Jarone Jabonillo
 *
 * Created on October 6, 2015, 11:18 AM
 * 
 * Purpose: Show utility of a structure referenced  
 * to a database sort. Indexed column in database
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

//User library
#include "IndexedColumn.h"

//Global constants

//Function prototypes
IndxCol *fill(int);
void prntStr(IndxCol *, int);
void prntAry(int *, int, int);
void mrkSort(IndxCol*);

using namespace std;

/*
 * [Homework] 
 * Convert:
 * Structure notation to the dot operator
 * Array notation to pointer notation
 */
int main(int argc, char** argv){
    //Call random number generate seem function
    srand(static_cast<unsigned int>(time(0)));
    //Allocate memory for the structure
    int n = 100, col = 10;
    IndxCol *str = fill(n);
    //Print structure
    cout <<"=== Original index array ==="<<endl;
    prntAry(str->indx, str->size, col);
    cout <<"=== Original data array ==="<<endl;
    prntAry(str->array, str->size, col);
    cout <<"=== Original data array using indexed array ==="<<endl;
    prntStr(str, col);
    
    //Sort the data using an index, hence data base sort
    mrkSort(str);
    
    //Print structure
    cout <<"=== Sorted index array ==="<<endl;
    prntAry(str->indx, str->size, col);
    cout <<"=== Sorted data array ==="<<endl;
    prntAry(str->array, str->size, col);
    cout <<"=== Sorted data array using indexed array ==="<<endl;
    prntStr(str, col);
    
    return 0;
}

IndxCol *fill(int n){
    //Allocate memory
    IndxCol *col = new IndxCol;
    
    if(n <= 1){
        n = 2;
    }
    
    col->size = n;
    col->array = new int[n];
    col->indx = new int [n];
    
    //Fill Array
    for(int i = 0;  i < n; i ++){
        col->indx[i] = i;
        col->array[i] = rand() %90 + 10;
    }
    //Return allocated memory and size
    return col;
}

void prntStr(IndxCol *a, int perLine){
    cout <<endl;
    for(int i = 0; i <a->size; i++){
        cout<< a->array[a->indx[i]] <<" ";
        if(i%perLine == (perLine - 1)) cout <<endl;
    }
    cout <<endl;
}


void prntAry(int *a, int size, int perLine){
    cout <<endl;
    for(int i = 0; i <size; i++){
        cout<< a[i] <<" ";
        if(i%perLine == (perLine - 1)) cout <<endl;
    }
    cout <<endl;
}

void mrkSort(IndxCol *a){
    //Pick a position to sort
    //Example (struct to dot op.): (*a).size-1
    for(int pos; pos < a->size-1; pos++){
        //Sort the list by position
        for(int lst = pos + 1; lst<a->size; lst++){
            if(a->array[a->indx[pos]] <a->array[a->indx[lst]]){
                int temp = a->indx[pos];
                a->indx[pos] = a->indx[lst];
                a->indx[lst] = temp;
            }
        }
    }
}