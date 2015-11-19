/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on November 18, 2015, 5:14 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Circle{
private:
    //Radius and Pi 
    float cRad, cPi = 3.14159; 
public:
    //Base constructor
    Circle();
    //User defined constructor
    Circle(float);
    //Sets circle radius
    void stRad(float);
    //Returns circle radius
    float gtRad();
    //Calculates and returns the area
    float gtArea();
    //Calculates and returns the diameters
    float gtDiamtr();
    //Calculates and returns the circumference
    float gtCirc();
};

/*
 * 
 */
int main(int argc, char** argv) {
    //User defined radius
    float radius;
    //Circle object
    Circle exmplA;
    
    //Prompt and receive user input
    cout << "Enter the radius: ";
    cin >> radius;
    
    //Set user radius to circle
    exmplA.stRad(radius);
    
    //Output radius, area, diameter, and circumference
    cout <<endl <<endl <<"Radius: " <<exmplA.gtRad() <<endl
            <<"Area: " <<exmplA.gtArea() <<endl
            <<"Diameter: " <<exmplA.gtDiamtr() <<endl
            <<"Circumference: " <<exmplA.gtCirc() <<endl;

    return 0;
}

Circle::Circle(){
    //Set radius to zero
    cRad = 0.0;
}
Circle::Circle(float radius){
    //Assign user input to radius
    cRad = radius;
}
void Circle::stRad(float radius){
    //Set radius to circle
    cRad = radius;
}
float Circle::gtRad(){
    //Returns the radius
    return cRad;
}
float Circle::gtArea(){
    //Calculates the area
    float area = cPi*cRad*cRad;
    //Returns the area
    return area;
}
float Circle::gtDiamtr(){
    //Calculates the diameter
    float diamtr = cRad * 2;
    //Returns the diameter
    return diamtr;
}
float Circle::gtCirc(){
    //Calculates the circumference
    float circ = 2 * cPi * cRad;
    //Returns the circumference
    return circ;
}
