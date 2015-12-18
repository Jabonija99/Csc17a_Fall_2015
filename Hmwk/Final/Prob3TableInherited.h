/* 
 * File:   Prob3TableInherited.h
 * Author: Kauru99
 *
 * Created on December 16, 2015, 1:26 PM
 */

#include "Prob3Table.h"

#ifndef PROB3TABLEINHERITED_H
#define	PROB3TABLEINHERITED_H

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
protected:
        T *augTable;                                //Augmented Table with sums
public:
        Prob3TableInherited(char *,int,int);          //Constructor
        ~Prob3TableInherited(){delete [] augTable;};  //Destructor
        const T *getAugTable(void){return augTable;}; 
};

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char * array, int col, int row){
    augTable = new T[col*row];

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            augTable[i*5+j] = array[i*5+j];
        }
    }
}

#endif	/* PROB3TABLEINHERITED_H */

