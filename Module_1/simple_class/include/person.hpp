#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

#include <string>

// define your Person class here

class Person {
    std::string name_;
    int birthyear_;
public:
    Person(std::string name, int birthyear)
        :name_(name), birthyear_(birthyear) { }
    std::string GetName() const;
    int GetAge(int year) const;
};

#endif
