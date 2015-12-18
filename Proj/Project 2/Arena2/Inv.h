/* 
 * File:   Inv.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 9:20 PM
 */

#ifndef INV_H
#define	INV_H


//Inventory structure
template<class T>
struct Inv{
    T max; //Maximum cap
    T cap; //Allowed capacity
    T size; //Number of items
    T *stck; //Pointer of items
};


#endif	/* INV_H */

