#ifndef PERSON_H_
#define PERSON_H_


#include <string>
#include <iostream>

class Person {
public:
    Person()
    {
        std::cout << "Person's Default Constructor\n";
    }

    /*explicit*/ Person(const std::string& name)
        : _name(name)
    {
        std::cout << "Person's Init Constructor\n";
    }

public:
    // setters/getters
    const std::string& getName() const { return _name; }
    void setName(const std::string& name) { _name = name;}

protected:
    std::string _name;

}; // class Person


/// Student inherits Person
class Student : public Person {
public:
    // type definitions
    typedef unsigned int Uint;
public:
    Student()
        : _groupId(0)
    {
        std::cout << "Student's Default Constructor\n";
    }

    Student(const std::string& name, Uint grId)
        : Person(name)  // TODO: try to comment this out
        , _groupId(grId)
    {
        std::cout << "Student's Init Constructor\n";
    }

public:
    // setters/getters
    Uint getGroupId() const { return _groupId; }
    void setGroupId(Uint grId) { _groupId = grId;}

    std::string makeNameGroup() const;

protected:
    Uint _groupId;

}; // class Student



#endif // PERSON_H_
