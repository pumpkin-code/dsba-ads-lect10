/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       18.02.2020
 *
 *  →
 */

#include <iostream>
#include <vector>

#include "person.h"
#include "mystring.h"
#include "safe_array.hpp"

using namespace std;


void demo1()
{
    std::cout << " IStringable test\n\n";

    Person john("John Doe");
    Person* pJohn = &john;
    //IStringable* psJohn = &john;    // error: doesn't implement interface

    Student mary("Mary Smith", 1921);
    Person* pMary = &mary;
    Student* p2Mary = &mary;
    //IStringable* psMary = &mary;    // error: doesn't implement interface

    Professor bradley("Dr. Bradley", 41);
    Person* pBradley = &bradley;
    Professor* p2Bradley = &bradley;
    IStringable* psBradley = &bradley;
    std:string s = psBradley->getStrRepresentation();
    std::cout << "Bradley's description: " << s << "\n";
}


// deletion with a ptr
void demo2()
{
    std::cout << "\n\n Dynamic creation\n\n";

    // dynamic creation
    Professor* snape = new Professor("Severus Snape", 15);
    IStringable* psSnape = snape;
    std:string s = psSnape->getStrRepresentation();
    std::cout << "Snape's description: " << s << "\n";

    // delete psSnape;  // ← prohibited!

    delete snape;
}


// custom string
void demo3()
{
    std::cout << "\n\n Custom string\n\n";

    MyString str("My string");
    IStringable* ps = &str;
    std::cout << "Custom string: " << ps->getStrRepresentation();
}


// safearray
void demo4()
{
    std::cout << "\n\n SafeArray\n\n";
    SafeArray<double> arr{1.2, 2.3, 3.4, -1.01};
    IStringable* ps = &arr;
    std::cout << "Array string representation: " << ps->getStrRepresentation();
}


int main()
{
    demo1();
    demo2();
    demo3();
    demo4();
    return 0;
}
