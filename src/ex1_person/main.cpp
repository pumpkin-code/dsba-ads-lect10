/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       18.02.2020
 *
 *  →
 */

//#include <iostream>
#include "person.h"

using namespace std;

void demo1()
{


    // explicit and implicit constructors
    Person p1;                              // default
    Person p2(string("John Doe"));          // init
    Person p3 = string("John Doe");         // implicit conversion
    //Person p4 = "John Doe";               // not possible any time

    string nm = p2.getName();

    int a = 0;
}


void demo2()
{
    Student s1;

    Student s2("Alex", 1811);
    string nm = s2.getName();
    Student::Uint gr = s2.getGroupId();

    // имя + группа
    string nmGrp = s2.makeNameGroup();

    int a = 0;
}


void demo3()
{
    Person pers("John Doe");
    Student stu("Alex", 1811);

    // pointer
    Person* persPtr = &pers;
    string nm = persPtr->getName();

    persPtr = &stu;     // implicit upcast conversion
    nm = persPtr->getName();
    // persPtr->getGroupId(); class Person has no member named getGroupId()
    // persPtr->makeNameGroup(); has no member

    // reference
    Person& persRes = pers;
    nm = persRes.getName();

    // persRes = stu; // ← assignment operation, not as intended to rebind
    Person& persRes2 = stu;
    nm = persRes2.getName();
}


int main()
{
    demo1();
    demo2();
    demo3();

    return 0;
}
