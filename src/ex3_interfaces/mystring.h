/*! \file       mystring.h
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       18.02.2020
 *
 *  Contains declaration of some custom string datatype.
 */


#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <string>

#include "stringable.h"

class MyString :
        public std::string
        , public IStringable
{
    // all the interface of std::string
public:
    MyString(const char* str)
        : std::string(str)
    {
    }
public:
    // IStringable interface implementations
    virtual std::string getStrRepresentation() const override;
};

#endif // MYSTRING_H_
