/* 
 * File:   RItem.h
 * Author: rcc
 *
 * Created on October 14, 2015, 9:52 AM
 */

#include <string>

using namespace std;

#ifndef RITEM_H
#define	RITEM_H

class RItem{
private:
    string iDesc;
    int iUnts;
    float iPrce;
public:
    RItem(string, int, float);
    
    void modData(string, int, float);
    string getDesc();
    int getUnts();
    float getPrce();
    
};

#endif	/* RITEM_H */

