/*! \file       stringable.h
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       18.02.2020
 *
 *  Contains declaration of IStringable interface.
 */


#ifndef STRINGABLE_H_
#define STRINGABLE_H_

#include <string>


/*
 *  Interface IStringable declares method for obtaining string representation
 *  of object of different types.
 *
 *  According to the rule C.35: "A base class destructor should be either public
 *  and virtual, or protected and nonvirtual". For this interface class, the
 *  destructor if declared as protected, because we don't want someone to manage
 *  lifetime of objects by using pointers of this type.
 *
 *  http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-dtor-virtual
 */
class IStringable {
public:
    //--===Interface part===--

    // Returns a string representation of an object implementing this interface.
    virtual std::string getStrRepresentation() const = 0;

protected:
    ~IStringable() {}
};


#endif // STRINGABLE_H_
