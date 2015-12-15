/* 
 * File:   Inv.h
 * Author: Kauru99
 *
 * Created on December 12, 2015, 9:20 PM
 */

#ifndef INV_H
#define	INV_H


//Inventory structure
struct Inv{
    int max; //Maximum cap
    int cap; //Allowed capacity
    int size; //Number of items
    int *stck; //Pointer of items
};


#endif	/* INV_H */

