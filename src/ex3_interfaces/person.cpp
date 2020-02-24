
#include "person.h"
#include <sstream>


//==============================================================================
// class Person
//==============================================================================

double Person::calcSalary() const
{
    return 1000;
}

//==============================================================================
// class Student
//==============================================================================

std::string Student::makeNameGroup() const
{
    std::stringstream ss;
    ss << "Name: " << _name << ", Group ID: " << _groupId;

    return ss.str();
}

void Student::addGrade(int grade)
{
    _grades.push_back(grade);
}

double Student::calcSalary() const
{
    for(int curMark : _grades)
        if(curMark < 6)
            return 0;

    // some complex logic which calculates the individual scholarship
    //return Person::calcSalary() + _grades.size() * 500;
    return _grades.size() * 500;
}

//==============================================================================
// class Professor
//==============================================================================

double Professor::calcSalary() const
{
    return Person::calcSalary() + _qualPeriod * 1000;
}


std::string Professor::getStrRepresentation() const
{
    std::stringstream ss;
    ss << "Professor " << getName() << ", qualified with "
       << _qualPeriod << " years";

    return ss.str();
}
