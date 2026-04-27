#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name_;
    std::string surname_;

public:
    Person(const std::string& name = "", const std::string& surname = "")
        : name_(name), surname_(surname) {}

    virtual ~Person() = default;

    Person(const Person& other);
    Person& operator=(const Person& other);

    Person(Person&& other) noexcept;
    Person& operator=(Person&& other) noexcept;

    virtual void print() const = 0;

    const std::string& getName() const { return name_; }
    const std::string& getSurname() const { return surname_; }
};

#endif