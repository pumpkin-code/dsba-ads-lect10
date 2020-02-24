/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       18.02.2020
 *
 *  →
 */

#include <iostream>

#include "person.h"
#include "cassert"

void demo1()
{
    Person pers("Alex");
    Student stu("Maria", 1821);

    double persSal = pers.calcSalary();         // 1000
    double stuSal = stu.calcSalary();           // 0

    Student stu2("Marco", 1811);
    stu2.addGrade(10);
    stu2.addGrade(10);
    stu2.addGrade(10);

    stuSal = stu2.calcSalary();                 // 1500

    // some magic
    Person* persPtr = &pers;
    persSal = persPtr->calcSalary();            // 1000

    persPtr = &stu;
    persSal = persPtr->calcSalary();            // 0

    persPtr = &stu2;
    persSal = persPtr->calcSalary();            // 1500
}

// persons' lifespan
void demo2()
{
    {
        Person john;
        Student doe;
    }
}

typedef std::vector<Person*> PeopleVector;

PeopleVector createSample()
{
    PeopleVector team;

    team.push_back(new Student("Alex", 123));
    Student* anna = new Student("Anna", 134);
    anna->addGrade(5);
    team.push_back(anna);

    Professor* prof = new Professor("Dr. Smith", 20);
    team.push_back(prof);

    Student* st1 = new Student("Maria", 180);
    team.push_back(st1);
    st1->addGrade(10);

    return team;
}

void deletePeopleVector(PeopleVector& team)
{
    // DONE: clear memory
    for(Person* pers : team)
        delete pers;
    team.clear();
}

// virtual polimorphism
void demo3()
{
    std::vector<Person*> team = createSample();

    double total = 0;

    for(const Person* pers : team)
    {
        double curSalary = pers->calcSalary();
        total += curSalary;
    }

    // clear memory
    deletePeopleVector(team);
}

void demo4()
{
    Person john("John Doe");
    Person* pJohn = &john;
    // Student* p2John = &john;     // compilation error
    // Professor* p3john = &john;   // compilation error

    Student* p2John = dynamic_cast<Student*>(&john);
    assert(p2John == nullptr);

    try {
        Student& rJohn = dynamic_cast<Student&>(john);
    }
    catch(std::bad_cast& e)
    {
        std::cerr << e.what();
    }

    Student mary("Mary Smith", 1912);
    Person* pMary = &mary;
    Student* p2Mary = dynamic_cast<Student*>(pMary);
    assert(p2Mary != nullptr);
    Professor* p3Mary = dynamic_cast<Professor*>(pMary);
    assert(p3Mary == nullptr);

}

// dynamic cast
void demo5()
{

    std::vector<Person*> team = createSample();
    team.push_back(new Person("John Doe"));

    std::cout << "\n\nPeople are:\n\n";
    for(const Person* pers : team)
    {
        std::cout << pers->getName() << ": ";

        // then we check person-specific traits

        // if it's a student
        if(const Student* stu = dynamic_cast<const Student*>(pers))
        {
            std::cout << "is a student! Their group is " << stu->getGroupId();
        }
        // if it's a professor
        else if(const Professor* prof = dynamic_cast<const Professor*>(pers))
        {
            std::cout << "is a professor! Their qualification is "
                      << prof->getQualPeriod();
        }
        else
        {
            std::cout << "is an unknown person!";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    // clear memory
    deletePeopleVector(team);
}



int main()
{
    demo1();
    //demo2();
    demo3();
    demo4();
    demo5();

    std::cout << "\n";

    return 0;
}
