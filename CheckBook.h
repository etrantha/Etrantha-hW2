/**************************************************************************
 * * Author: Eric Trantham
 * ** Program: hw2, q1
 * ** Date Created: Oct 22, 2021
 * ** Date Last Modified : Oct 22, 2021

************************************************************************/

#ifndef ETRANTHA_HW2_Q1_CHECKBOOK_H
#define ETRANTHA_HW2_Q1_CHECKBOOK_H
#include <iostream>

using namespace std;


struct Check{
    int checkNum = 0;
    float amount;
    string memo;
    bool operator<(const Check &c1);
    friend ostream & operator<<(ostream &var, Check c);
};



    class CheckBook{
    public:
        CheckBook():balance(0), numOfChecks(0), checkBookSize(4){}
        CheckBook(float amount):balance(amount), numOfChecks(0), checkBookSize(2){}
        ~CheckBook(){delete [] chkPtr;}
        CheckBook(const CheckBook &obj);
        CheckBook & operator=(CheckBook &rhs);
        //Check & operator[](int index){return chkPtr[index];}
        void deposit(float amount);
        bool writeCheck(Check c_amount);
        void setBalance(float blnce){balance = blnce;}
        void setlastDeposit(int lstDpsit){lastDeposit =lstDpsit;}
        void setNumOfChecks(int nmOChecks){numOfChecks = nmOChecks;}
        void setcheckBookSize(int chkBKSZ){checkBookSize = chkBKSZ;}
        int getLastDeposit()const{return lastDeposit;}
        int getBalance()const{return balance;}
        void checkTest();
        int getNumofChecks()const{return numOfChecks;}
        int getCheckBookSize()const{return checkBookSize;}
        void displayChecks();



    private:
        float balance;
        int lastDeposit, numOfChecks, checkBookSize;
        Check *chkPtr = new Check[checkBookSize];


    };



#endif //ETRANTHA_HW2_Q1_CHECKBOOK_H
