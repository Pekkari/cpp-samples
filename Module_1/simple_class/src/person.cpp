#include "person.hpp"

// define your Person class' functions here

std::string Person::GetName() const {
    return this->name_;
}

int Person::GetAge(int year) const {
    return year - this->birthyear_;
}

