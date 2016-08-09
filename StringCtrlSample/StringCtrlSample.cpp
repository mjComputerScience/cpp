//
//  main.cpp
//  StringCtrlSample
//
//  Created by YooTae-Ook on 2016. 7. 29..
//  Copyright © 2016년 YooTae-Ook. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"

CMyString TestFunc(void){
    CMyString strTest("TestFunc() return");
    cout << strTest <<endl;
    
    return strTest;
}

int main(int argc, const char * argv[]) {
    TestFunc();

    return 0;
}
