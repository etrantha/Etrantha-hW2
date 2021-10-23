

#include <iostream>
#include<string>
#include<cstdlib>
#include <array>
#include "CheckBook.h"

using namespace std;




int main() {
    std::cout << "Hello, World!" << std::endl;
    CheckBook cb1(1000), cb2(956), cb3(500);
    Check c1;
    for(int i=0;i<cb1.getCheckBookSize();i++) {
        cb1.writeCheck(c1);
    }
    for(int j=0;j<cb1.getCheckBookSize();j++){

        cb2.writeCheck(c1);
    }
    cb1.displayChecks();
    cout<<"============="<<endl;
    cb2.displayChecks();
    cb3.checkTest();


    return 0;
}








