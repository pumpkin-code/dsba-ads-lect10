/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       18.02.2020
 *
 *  Abstract classes example.
 */

#include <iostream>
#include <vector>

#include "person.h"

using namespace std;


void demo1()
{
    std::cout << " Abstract classes test\n\n";
    //Person john("John Doe");  // can't create an abstract class

    Student mary("Mary Smith", 1921);
    mary.addGrade(10);
    Person* pMary = &mary;
    Student* p2Mary = &mary;
    std::cout << "Mary's salary: " << pMary->calcSalary()
              << ", or " << p2Mary->calcSalary() << "\n";

    Professor bradley("Dr. Bradley", 41);
    Person* pBradley = &bradley;
    Professor* p2Bradley = &bradley;
    std::cout << "Bradley's salary: " << pBradley->calcSalary()
              << ", or " << p2Bradley->calcSalary();
}

int main()
{
    demo1();
    std::cout << "\n\n";
    return 0;
}
