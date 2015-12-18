/* 
 * File:   Prob3Table.h
 * Author: Kauru99
 *
 * Created on December 16, 2015, 1:25 PM
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

template<class T>
class Prob3Table{
protected:
        int pRows;                                 //Number of rows in the table
        int pCols;                                 //Number of cols in the table
        T *pRowSum;                                //RowSum array
        T *pColSum;                                //ColSum array
        T *pTable;                                 //Table array
        T pGrndTotal;                             //Grand total
        void calcTable(void);                     //Calculate all the sums
public:
        Prob3Table(char *,int,int);               //Constructor then Destructor
        virtual ~Prob3Table(){delete [] pTable;delete [] pRowSum;delete [] pColSum;};
        const T *getTable(void){return pTable;};
        const T *getRowSum(void){return pRowSum;};
        const T *getColSum(void){return pColSum;};
        T getGrandTotal(void){return pGrndTotal;};
};


template<class T>
Prob3Table<T>::Prob3Table(char* array, int row, int col){
    fstream file;
    string fileNme = "";
    while(*array != '\0'){
        fileNme+= *array;
        array++;
    }
    int index = 0;
    pTable = new T[row*col];
    
    file.open(fileNme.c_str(), ios::in);
    
    while(file.get(*pTable)){
        pTable++;
    }
    
   
    file.close();
}



#endif	/* PROB3TABLE_H */

