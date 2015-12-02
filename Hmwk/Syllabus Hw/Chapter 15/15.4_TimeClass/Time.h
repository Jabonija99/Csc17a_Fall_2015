/* 
 * File:   Time.h
 * Author: rcc
 *
 * Created on December 1, 2015, 10:43 AM
 */

#ifndef TIME_H
#define	TIME_H

class Time{
 protected:
 int tHour;
 int tMin;
 int tSec;
 
 public:
 // Default constructor
 Time(){ 
     tHour = 0; tMin = 0; tSec = 0; 
 }

 // Constructor
 Time(int h, int m, int s) { 
     tHour = h; tMin = m; tSec = s; 
 }

 // Accessor functions
 int getHour() const { 
     return tHour; 
 }

int getMin() const { 
    return tMin; 
}

 int getSec() const { 
     return tSec; 
 }
 
 };

#endif	/* TIME_H */

