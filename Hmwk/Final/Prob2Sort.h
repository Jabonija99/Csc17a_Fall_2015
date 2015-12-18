/* 
 * File:   Prob2Sort.h
 * Author: Kauru99
 *
 * Created on December 14, 2015, 7:30 PM
 */

#include <iostream>
#include <string>

using namespace std;


#ifndef PROB2SORT_H
#define	PROB2SORT_H

//This class sorts arrays either ascending or descending
template<class T>
class Prob2Sort
{
    private:
        //Index that is utilized in the sort
        int *index;
    public:
        //Constructor
        Prob2Sort(){index=NULL;};    
        //Destructor
        ~Prob2Sort(){delete []index;};
        //Sorts a single column array
        T * sortArray(const T*,int,bool);
        //Sorts a 2 dimensional array represented as a 1 dim array
        T * sortArray(const T*,int,int,int,bool);   
};


template<class T>
T * Prob2Sort<T>::sortArray(const T *array, int col, bool ascnd){
    //Create a 2d array of ints
    int iRow = 16;
    int iCol = 10;
    index = new int[iCol*iRow];
    T *words = new T[iCol*iRow];
    
    
    //Copy contents to index
    for(int i = 0; i < iCol; i++){
        for(int j = 0; j < iRow; j++){
            //Copies the integer version of the strings to index
            index[i*16+j] = array[i*16+j];
        }
    }
    
    //Sort copied contents
    //Goes through a single column
    for(int i = 0; i < iCol; i ++){
        
        //If sorting ascending order
        if(ascnd){
            //If the number is larger than the next
            if(index[i*16+col] > index[(i+1)*16+col]){
                //Swap the numbers
                int temp = index[i*16+col];
                index[i*16+col] = index[(i+1)*16+col];
                index[(i+1) * 16 + col] = temp;
            }
        }
        else{
            //If the number is smaller than the next
            if(index[i*16+col] < index[(i+1)*16+col]){
                //Swap the numbers
                int temp = index[i*16+col];
                index[i*16+col] = index[(i+1)*16+col];
                index[(i+1) * 16 + col] = temp;
            }
        }
        
    }
    
    for(int i = 0; i < iCol; i++){
        for(int j = 0; j < iRow; j++){
            words[i*16+j] = (char)index[i*16+j];
        }
    }
    
    return words;
}

template<class T>
T * Prob2Sort<T>::sortArray(const T* array, int aCol , int aRow, int col, bool ascnd){
    T* words = new T[aCol*aRow];
    index = new int[aCol*aRow];
    
    for(int i = 0; i < aCol; i++){
        for(int j = 0; j < aRow; j++){
            if(index[i*16+j] != 10||index[i*16+j]==13){
                index[i*16+j] = array[i*16+j];
            }
        }
    }
    
    cout <<endl <<" Index " <<endl;
    for(int i = 0; i < aCol; i++){
        for(int j = 0; j < aRow; j++){
            cout <<index[i*16+j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    
    for(int i = 0; i < aCol; i++){
        for(int j = 0; j <aRow-1; j++){
            index[i*16+col] = i*16+j;
            
            if(index[i*16+col] > index[(i+1)*16+col]){
                int temp = index[i*16+col];
                index[i*16+col] = index[(i+1)*16+col];
                index[(i+1)*16+col] = temp;
            }
        }
    }
   
    cout <<endl <<" Index Sorted " <<endl;
    for(int i = 0; i < aCol; i++){
        for(int j = 0; j < aRow; j++){
            cout <<index[i*16+j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    
    for(int i = 0; i < aCol; i++){
        for(int j = 0; j < aRow; j++){
            words[i*16+j] = (char)index[i*16+j];
        }
    }
    
    return words;
}


#endif	/* PROB2SORT_H */

