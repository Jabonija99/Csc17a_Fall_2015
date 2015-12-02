/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on December 1, 2015, 7:16 PM
 */

#include <cstdlib>
#include <iostream>
#include "PData.h"

using namespace std;

class CData: public PData{
private:
    int cNum;
    bool cMList;
public:
    CData();
    CData(int);
    
    void stCNum(int);
    int gtCNum();
    
    bool mList(int); 
};


void fillData(CData &, string, string, string, string, string, int, int, int);
void outData(CData &, int);

/*
 * 
 */
int main(int argc, char** argv) {
    //Customer data object
    CData custmr; 
    //Customer number, zip, phone, and mail list preference
    int num, zip, phne, mail; 
    //Last and first name, address, city, state
    string lNme, fNme, addr, city, st;
    //Blank buffer string
    string buffr;
    
    cout <<"Customer Data Input" <<endl
            <<"Last Name: ";
    cin >> lNme;
    cout <<"First Name: ";
    cin >> fNme;
    cin.ignore();
    cout <<"Address: ";
    getline(cin, addr);
    cout <<"City: ";
    getline(cin, city);
    cout <<"State: ";
    cin >> st;
    cout <<"Zip Code: ";
    cin >> zip;
    cout <<"Phone number: ";
    cin >> phne;
    cout <<"Customer number: ";
    cin >> num;
    cout <<"Mailing list(1 for YES, 0 for NO): ";
    cin >> mail;
    cout <<endl <<endl;
    
    fillData(custmr, lNme, fNme, addr, city, st, zip, phne, num);
    outData(custmr, mail);
    
    
    return 0;
}

CData::CData(){
    cNum = 0;
    cMList = false;
}
CData::CData(int num){
    cNum = num;
    cMList = false;
}
void CData::stCNum(int num){
    cNum = num;
}
int CData::gtCNum(){
    return cNum;
}
bool CData::mList(int list){
    if(list == 1){
        cMList = true;
    }
    else{
        cMList = false;
    }
}


void fillData(CData &custmr, string lNme, string fNme, string addr, string city, 
        string st, int zip, int phne, int num){
    custmr.stLNme(lNme);
    custmr.stFNme(fNme);
    custmr.stAddr(addr);
    custmr.stCity(city);
    custmr.stSt(st);
    custmr.stZip(zip);
    custmr.stPhne(phne);
    custmr.stCNum(num);
}
void outData(CData &custmr, int mail){
    cout <<"Customer #" <<custmr.gtCNum() <<endl
            <<"Name: " <<custmr.gtLNme() <<", " <<custmr.gtFNme() <<endl
            <<"Address: " <<custmr.gtAddr() <<endl <<custmr.gtCity() <<", "
            <<custmr.gtSt() <<" " <<custmr.gtZip() <<endl
            <<"Phone: " <<custmr.gtPhne() <<endl
            <<"Mailing List: ";
    if(custmr.mList(mail)){
        cout <<"YES";
    }
    else{
        cout <<"NO";
    }
    cout <<endl;
}