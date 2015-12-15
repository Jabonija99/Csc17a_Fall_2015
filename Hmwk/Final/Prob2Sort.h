/* 
 * File:   Prob2Sort.h
 * Author: Kauru99
 *
 * Created on December 14, 2015, 7:30 PM
 */

#include <cstdlib>

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

#endif	/* PROB2SORT_H */

