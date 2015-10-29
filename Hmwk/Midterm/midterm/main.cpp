/* 
 * File:   main.cpp
 * Author: Kauru99
 *
 * Created on October 27, 2015, 5:49 PM
 */


//Library includes
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

struct Accnt{
    int accNum; //Account number
    float accBlnc; //Account balance
    float totChck; //Total checks written
    float totDep; //Total deposits checked
};
struct Emplye{
    string eName; //Employee name
    float eHrs, ePay; //Employee hours and rate of pay
};
struct ResltSt{
    float avg; //Average
    float med; //Median
    int *mode; //Array containing modes
    int nMode; //Number of modes
    int mxFrq; //Max frequency of modes
};

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);

void problem1();

void problem2();

void problem3();
ResltSt *avgMde(int *, int);
void prntSt(ResltSt *);

void problem4();
int encrpt(int, bool &);
int decrpt(int, bool&);

void problem5();
void problem6();



void cls();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
        
        cls();
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}
void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}
int getN(){
    int inN;
    cin>>inN;
    return inN;
}

void problem1(){
    //User input and original account balance
    float usrIn, blnc;
    //Input validation
    bool inVal = true;
    
    cls();
    cout <<fixed <<setprecision(2) <<"In problem # 1"<<endl<<endl;

    //Account for the user
    Accnt user;
    
    do{
        //Prompt user
        cout <<"Enter account number: ";
        //Receive user account number
        cin >> user.accNum;
    
        //Account number and size
        int acc, sze;
        //Assign account number
        acc = user.accNum;
        
        //If the account number is greater than 0
        if(acc > 0){
            //Repeat until all variables have been counted
            for(sze = 0; acc > 0; sze++){
                //Divide and count each digit
                acc /= 10;
            }
        }
        
        //If the size is greater than 5
        if(sze > 5){
            //Prompt invalid input
            cout <<"Invalid input! Account number must be five or less digits."
                    <<endl <<endl;
            //Flag invalid input
            inVal = false;
        }
        else{
            //Flag valid input
            inVal = true;
        }
        
    //Repeat while the input is invalid
    }while(!inVal);
    cout <<endl;
    
    //Prompt and receive user account balance
    cout <<"Enter starting account balance: $ ";
    cin >> blnc;
    //Assign account balance
    user.accBlnc = blnc;
    
    //Set total check to zero
    user.totChck = 0;
    do{
        //Prompt and receive total check amount
        cout <<"Enter all check amounts written(-1 to quit): $ ";
        cin >> usrIn;
        
        //If the user does not enter -1
        if(usrIn != -1){
            //Enter the amount in total check
            user.totChck += usrIn;
        }
    //Repeat until user enters -1
    }while(usrIn != -1);
    cout <<endl;
    
    //Set deposit total to zero
    user.totDep = 0;
    do{
        //Prompt and receive total deposit
        cout <<"Enter all deposit amounts credited(-1 to quit): $ ";
        cin >> usrIn;
        
        //If the user does not enter -1
        if(usrIn != -1){
            //Enter the amount in total deposit
            user.totDep += usrIn;
        }
    //Repeat until user enters -1
    }while(usrIn != -1);
        
    //Calculate new balance
    user.accBlnc -= (user.totChck + user.totDep);
    
    cls();
    //Output balance
    cout <<"Original Balance: $ " <<blnc <<endl
            <<"Total Check: $ " <<user.totChck <<endl
            <<"Total Deposit: $ " <<user.totDep <<endl
            <<"Current Balance: $ " <<user.accBlnc <<endl;
    
    //If the balance is less than 0
    if(user.accBlnc < 0){
        //Prompt overdraft warning
        cout <<"Overdraft Warning: A fee of $15 dollars will be taken "
                "from your account." <<endl;
        //Charge $15
        user.accBlnc -= 15;
        //Prompt overdraft total
        cout <<"Overdraft total: $ " <<user.accBlnc <<endl;
    }
    cout <<endl;
    
    //User controlled pause
    cout <<"Enter any number to quit: ";
    cin >> usrIn;
        
}

void problem2(){
    float hrs, pay; //Employee hours and pay
    int cap = 100000000; //Array capacity
    int size = 0; //Array size
    Emplye *staff = new Emplye[cap]; //Employee array
    
    //Clear screen
    cls();
    //Set decimals to two digits
    cout <<fixed <<setprecision(2);
    cout<<"In problem # 2"<<endl<<endl;
    
    do{
        //Set initial pay to zero
        pay = 0;
        
        //Prompt user
        cout <<"Enter all pertinent information" <<endl
                <<"(Enter negative values to hours or pay to quit)" <<endl;
        //Receive employee name
        cout <<"Employee name: ";
        cin >> staff[size].eName;
        //Receive employee hours
        cout <<"Hours Worked: ";
        cin >> staff[size].eHrs;
        hrs = staff[size].eHrs;
        //Receive employee rate of pay
        cout <<"Rate of Pay: $ ";
        cin >> staff[size].ePay;
    
        //If inputs are positive
        if(staff[size].eHrs > -1 && staff[size].ePay > -1){
            //Increment pay until 40 hours or out of hours
            for(int i = 0; i < 40 && hrs >= 1 ; i++){
                //Add pay for the hour
                pay += staff[size].ePay;
                //Decrement hour
                hrs--;
            }
            
            //If there are hourss remaining
            if(hrs >= 1){
                //For the ten hours of double pay
                for(int i = 0; i < 10 && hrs >= 1 ; i++){
                    //Add double pay per hour
                    pay += staff[size].ePay*2;
                    //Decrement hour
                    hrs--;
                }
                //If there are hours remaining
                if(hrs >=1){
                    //For the remaining amount of hours
                    for(int i = hrs; i >=1; i--){
                        //Add triple pay per hour
                        pay += staff[size].ePay*3;
                        //Decrement hours
                        hrs--;
                    }
                
                }
            }
            //If there are any decimals remaining
            if(hrs < 1 && hrs > 0){
                //Calculate decimal pay
                pay +=(staff[size].ePay*hrs);
            }
            
            //Output check 
            cout <<endl <<endl
                    <<"====================================================="
                    <<endl <<"Check" <<endl
                    <<"Pay to the order of: " <<staff[size].eName <<endl
                    <<"S " <<pay <<endl
                    <<"====================================================="
                    <<endl <<"Enter any number to continue:";
            cin >>pay;
            //Clear screen
            cls();
            //Increment size
            size++;
        }
    //Repeat until a negative number is inputted
    }while(staff[size].eHrs > -1 && staff[size].ePay > -1);
    
}

void problem3(){
    int usrIn, size;
    cls();
    cout<<"In problem # 3"<<endl<<endl;
    cout <<"Amount of numbers: ";
    cin >> size;
 
    int *aNum = new int[size];
    
    for(int i = 0 ; i < size; i++){
        cout <<"Enter a number: ";
        cin >> usrIn;
        aNum[i] = usrIn;
    }
    
    ResltSt *stats = avgMde(aNum, size);
    prntSt(stats);
    
    delete aNum;
    
     //User controlled pause
    cout <<"Enter any number to quit: ";
    cin >> usrIn;
}
ResltSt *avgMde(int *aNum, int aSize){
    int cap = aSize; //Capacity of new array
    int size = 0; //Size of array
    ResltSt *stat = new ResltSt[cap];// Size of array
    bool dup = false; //Flag for duplicates
    int k = 0; //Counter
    //If array is empty
    if(aSize == 0){
        stat->mxFrq = 0;//Set max freq to 0
    }
    else{    
        stat->mxFrq = 1; //Set max frequency to 1
    }
    stat->mode = new int[cap]; //array for mode
    
    //Mode
    //Searches the array
    for(int i = 0; i < aSize; i++){
        //Search the array again to compare values
        for(int j = 0; j < aSize; j++){ 
            //If the values match and are not of the same address
            if(aNum[i] == aNum [j]){
                //Increment the counter
                k++;
            }
        }
        
        //Searches the mode array
        for(int j = 0; j < size; j++){
            //If the number exists in mode
            if(aNum[i] == stat->mode[j]){
                //Flag for duplicate
                dup = true;
            }
        }
        
        //If it is not a duplicate and the number count is > the maximum mode
        if(!dup && k > stat->mxFrq){
            stat->mxFrq = k; //Set the maximum mode to the current count
            size = 0; //Reset the size, "deleting" any current numbers
            stat->mode[size] = aNum[i]; //Assigns the value into the mode array
            size++; //Increment the size
        }
        //If the count is the same as the maximum Mode
        else if(!dup && k == stat->mxFrq && k != 1){
            stat->mode[size] = aNum[i]; //Add the number into the mode array
            size++; //Increment the size
        }
        
        k = 0; //Reset the counter
        dup = false; //Reset the duplicate flag
    }
    stat->nMode = size;
    
    
    //Average
    float avg = 0;
    for(int i = 0; i < aSize; i++){
        avg += aNum[i];
    }
    stat->avg = avg/aSize;
    
    //Median
    float med;
    int *a = new int[aSize];
    for(int i = 0; i < aSize; i++){
        a[i] = aNum[i];
    }
    for(int i = 0; i < aSize; i++){
        for(int j = 0; j < aSize-1; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
            }
        }
    }
    
    if(aSize%2 != 0){
        stat->med = a[aSize/2];
    }
    else{
        int num1,num2;
        num1 = a[aSize/2];
        num2 = a[(aSize/2)+1];
        
        stat->med = static_cast<float>(num1+num2)/2.0;
    }
    delete a;
    
    return stat;
}
void prntSt(ResltSt *stat){
    cout <<"Average: " <<stat->avg <<endl
            <<"Median: " <<stat->med <<endl
            <<"Mode: ";
    if(stat->nMode == 0){
        cout <<"No Mode";
    }
    else{
        for(int i = 0; i < stat->nMode; i++){
            cout <<stat->mode[i] <<" ";
        }
    }
    
    cout <<endl <<"Number of modes: " <<stat->nMode <<endl
            <<"Max Frequency: " <<stat->mxFrq <<endl;
}

void problem4(){
    int usrIn, size;
    bool inVal;
    cls();
    cout<<"In problem # 4"<<endl<<endl;
    
    do{
        inVal = true;
        
        cout <<"Enter data numbers: ";
        cin >> usrIn;
        int temp = usrIn;
        
        
        if(usrIn > 0){
            //Repeat until all digits have been counted
            for(size = 0; temp > 0; size++){
                //Divide and count each digit
                temp /= 10;
            }
        }
        
        //If the size is greater than 5
        if(size != 4){
            //Prompt invalid input
            cout <<"Invalid input! Data must be four digits"
                    <<endl <<endl;
            //Flag invalid input
            inVal = false;
        }
        
    }while(!inVal);
    
    //Encryption
    int eData = encrpt(usrIn, inVal);
    
    cout <<"Encrypted data: " <<eData <<endl;
    if(!inVal){
        cout <<"Encryption error detected!" <<endl;
    }
    cout <<"=============================" <<endl
            <<"Enter any number to quit: ";
    cin >> usrIn;
}
int encrpt(int data, bool&inVal){
    //Variables for each digit
    int dig1, dig2, dig3, dig4;
    //Encrypted data
    int eData;
    
    //Assign each digit to respective places
    dig1 = (data/1000);
    dig2 = (data/100) - (dig1*10);
    dig3 = (data/10) - ((dig1*100)+(dig2*10));
    dig4 = data - ((dig1*1000)+(dig2*100)+(dig3*10));
    
    //Add five to each digit
    dig1+=5;
    dig2+=5;
    dig3+=5;
    dig4+=5;
    
    //Mod each digit by eight to retain base
    dig1%=8;
    dig2%=8;
    dig3%=8;
    dig4%=8;    
    
    //Swap digits
    //Assign temporary variables
    int temp1 = dig1;
    int temp2 = dig3;
    //Swap first and second digits
    dig1 = dig2;
    dig2 = temp1;
    //Swap third and fourth digits
    dig3 = dig4;
    dig4 = temp2;
    
    if(dig1 > 7 || dig2 > 7 || dig3 > 7 || dig4 >7){
        inVal = false;
    }
    
    //Reassign new digits to encrypted data variable
    eData = (dig1*1000)+(dig2*100)+(dig3*10)+(dig4);
    
    //Return encrypted data
    return eData;
}
int decrpt(int eData, bool&inVal){
    //Variables for each digit
    int dig1, dig2, dig3, dig4;
    //Encrypted data
    int data;
    
    //Assign each digit to respective places
    dig1 = (eData/1000);
    dig2 = (eData/100) - (dig1*10);
    dig3 = (eData/10) - ((dig1*100)+(dig2*10));
    dig4 = eData - ((dig1*1000)+(dig2*100)+(dig3*10));
    
    
    
    //Swap digits
    //Assign temporary variables
    int temp1 = dig1;
    int temp2 = dig3;
    //Swap first and second digits
    dig1 = dig2;
    dig2 = temp1;
    //Swap third and fourth digits
    dig3 = dig4;
    dig4 = temp2;
    
    if(dig1 > 7 || dig2 > 7 || dig3 > 7 || dig4 >7){
        inVal = false;
    }
    
    //Reassign new digits to encrypted data variable
    data = (dig1*1000)+(dig2*100)+(dig3*10)+(dig4);
    
    //Return encrypted data
    return data;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void cls(){
    for(int i = 0; i < 20; i++){
        cout <<endl;
    }
}