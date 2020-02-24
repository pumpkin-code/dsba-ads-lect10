
#include "person.h"

#include <sstream>

std::string Student::makeNameGroup() const
{
    std::stringstream ss;
    ss << "Name: " << _name << ", Group ID: " << _groupId;
    return ss.str();
    // ASK: что будет, если _name — приватный? — изменить и посмотреть
}
