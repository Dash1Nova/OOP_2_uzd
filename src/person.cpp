#include "../include/person.h"

Person::Person(const std::string& name, const std::string& surname) : name_(name), surname_(surname) {}

Person::Person(const Person& other) : name_(other.name_), surname_(other.surname_) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name_ = other.name_;
        surname_ = other.surname_;
    }
    return *this;
}

Person::Person(Person&& other) noexcept : name_(std::move(other.name_)), surname_(std::move(other.surname_)) {
    
    other.name_.clear();
    other.surname_.clear();
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        name_ = std::move(other.name_);
        surname_ = std::move(other.surname_);

        other.name_.clear();
        other.surname_.clear();
    }
    return *this;
}