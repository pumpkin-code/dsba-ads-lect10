#ifndef PERSON_H_
#define PERSON_H_



#include <string>
#include <iostream>
#include <vector>


// type definitions
typedef unsigned int UInt;


class Person {
public:
    Person()
    {
        std::cout << "Person's Default Constructor\n";
    }

    explicit Person(const std::string& name)
        : _name(name)
    {
        std::cout << "Person's Init Constructor\n";
    }

    ~Person()
    {
        std::cout << "Person's Destructor\n";
    }

public:

    virtual double calcSalary() const;

public:

    // setters/getters
    const std::string& getName() const { return _name; }
    void setName(const std::string& name) { _name = name; }

protected: // private:
//private:
    std::string _name;

}; // class Person


class Student : public Person {
public:
    Student()
        //: Person () // implicitly calls the default constructor of the base class  //("Marco")
    {
        //std::cout << "Student's Default Constructor\n";
    }

    Student(const std::string& name, UInt grId)
        : _groupId(grId)
        , Person(name)
        //, _name()
    {
        std::cout << "Student's Init Constructor. ";
        std::cout << "The base part name is: " << _name << '\n'; //getName();//_name;
    }

    ~Student()
    {
        std::cout << "Student's Destructor\n";
    }

public:
    std::string makeNameGroup() const;
    void addGrade(int grade);

public:
    virtual double calcSalary() const override;

public:
    // setters/getters
    UInt getGroupId() const { return _groupId; }
    void setGroupId(UInt grId) { _groupId = grId;}

protected:

    std::vector<int> _grades;   // collection

private:
    UInt _groupId;
};


class Professor : public Person {
public:
    Professor()
        //: Person () // implicitly calls the default constructor of the base class  //("Marco")
    {
        std::cout << "Professor's Default Constructor\n";
    }

    Professor(const std::string& name, UInt qPeriod)
        : _qualPeriod(qPeriod)
        , Person(name)
        //, _name()
    {
        std::cout << "Professor's Init Constructor. ";
        std::cout << "The base part name is: " << _name << "\n"; //getName();//_name;
    }
    ~Professor()
    {
        std::cout << "Student's Destructor\n";
    }

public:
    virtual double calcSalary() const override;
    UInt getQualPeriod() const { return _qualPeriod; }

private:
    UInt _qualPeriod;
}; // class Professor



#endif // PERSON_H_
