/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on September 23, 2015, 4:43 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int value[5], count;
    
    for(count = 0; count < 5; count++){
        value[count] = count + 1;
    }
    
    for(count = 0; count < 5; count++){
        cout << value[count] <<endl;
    }
    
    /**
     * Output:
     * 1
     * 2
     * 3
     * 4
     * 5
     */
    
    return 0;
}

