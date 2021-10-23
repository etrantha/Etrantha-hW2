//
// Created by Eric Trantham on 10/22/21.
//

#include "CheckBook.h"
#include <iostream>

using namespace std;


bool Check::operator<(const Check &c1){if (amount<c1.amount)return true; return false;
}

ostream & operator<<(ostream &var, Check c)
{
    var<<c.checkNum<<c.amount<<c.memo;
    return var;
}

CheckBook::CheckBook(const CheckBook &obj) {
    balance = obj.balance;
    numOfChecks = obj.numOfChecks;
    checkBookSize = obj.checkBookSize;
    chkPtr = new Check;
    for(int i=0;i<numOfChecks;i++)
        chkPtr[i] = obj.chkPtr[i];
}

CheckBook &CheckBook::operator=(CheckBook &obj) {
    if(this==&obj)
        return *this;
    delete [] chkPtr;
    balance = obj.balance;
    numOfChecks = obj.numOfChecks;
    checkBookSize = obj.checkBookSize;

    chkPtr = new Check[checkBookSize];

    for(int i=0; i<numOfChecks; i++)
        chkPtr[i] = obj.chkPtr[i];

    return *this;

}

void CheckBook::deposit(float amount) {
    balance += amount;
}

bool CheckBook::writeCheck(Check c_amount) {
    {

        if(c_amount.amount <= balance && numOfChecks<checkBookSize)
        {
            string memo;
            srand(time(NULL));
            string memoArr[10] = {"wedding", "car", "rent", "Netflix", "Internet", "Gas", "Electrcity", "haitcut", "tickets", "computers"};
            int randIndex = rand() % 10;
            c_amount.memo = memoArr[randIndex];
            cout << "What is the check amount? "<<endl;
            cin >> c_amount.amount;
            //chkPtr = new Check[checkBookSize];
            chkPtr[numOfChecks].amount = c_amount.amount;
            chkPtr[numOfChecks].memo = c_amount.memo;
            if(chkPtr[numOfChecks - 1].checkNum>numOfChecks)
            {chkPtr[numOfChecks - 1].checkNum = 0;}
            chkPtr[numOfChecks].checkNum = chkPtr[numOfChecks-1].checkNum + 1;
            //chkPtr->amount = c_amount.amount;
            //chkPtr->memo = c_amount.memo;
            //chkPtr->checkNum++;
            balance-=c_amount.amount;
            cout << numOfChecks << "  " << checkBookSize<<" "<< chkPtr[numOfChecks].checkNum<<"Balance: "<<balance<< endl;
            numOfChecks++;
            if(numOfChecks==checkBookSize/2) {
               Check *temp = new Check[checkBookSize*2];
               for(int i=0;i<checkBookSize;i++){
                   temp[i] = chkPtr[i];
               }
               delete [] chkPtr;
               chkPtr = temp;
               checkBookSize *= 2;
               cout << "Am I doubling"<<checkBookSize<<endl;
            }

            return true;
        }else{
            return false;
        }
    }
}

void CheckBook::displayChecks()
{
    for(int i=numOfChecks-1; i>=0; i--)
    {
        cout<<chkPtr[i].memo<<" "<<chkPtr[i].checkNum<<" "<<chkPtr[i].amount<<endl;
    }


}

void CheckBook::checkTest() {
    if(balance == 0){
        cout << "checkbook empty" <<endl;
        this->displayChecks();
    return;}
    Check c3;
    while(balance > 0)
    {
        this->writeCheck(c3);

    }
    cout << "checkbook empty balance:" <<balance<<endl;
    this->displayChecks();

    return;

}
