#include "student.h"
#include <algorithm>
#include <iostream>

Student::Student(const std::string name, const std::string surname, const std::vector<int> nd, int egz) : name_(name), surname_(surname), nd_(nd), egz_(egz) {
    calculate();
}

Student::~Student() { 
    name_.clear();
    surname_.clear();
    nd_.clear();
}

Student::Student(const Student& other) : 
    name_(other.name_), 
    surname_(other.surname_), 
    nd_(other.nd_), 
    egz_(other.egz_), 
    finalAvg_(other.finalAvg_), 
    finalMed_(other.finalMed_) {}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name_ = other.name_;
        surname_ = other.surname_;
        nd_ = other.nd_;
        egz_ = other.egz_;
        finalAvg_ = other.finalAvg_;
        finalMed_ = other.finalMed_;
    }
    return *this;
}

Student::Student(Student&& other) noexcept
    : name_(std::move(other.name_)),
      surname_(std::move(other.surname_)),
      nd_(std::move(other.nd_)),
      egz_(other.egz_),
      finalAvg_(other.finalAvg_),
      finalMed_(other.finalMed_) {}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        name_ = std::move(other.name_);
        surname_ = std::move(other.surname_);
        nd_ = std::move(other.nd_);
        egz_ = other.egz_;
        finalAvg_ = other.finalAvg_;
        finalMed_ = other.finalMed_;

        other.egz_ = 0;
        other.finalAvg_ = 0;
        other.finalMed_ = 0;
    }
    return *this;
}

const std::string& Student::getName() const { return name_; }
const std::string& Student::getSurname() const { return surname_; }
const std::vector<int>& Student::getNd() const { return nd_; }
int Student::getEgz() const { return egz_; }

double Student::getFinalAvg() const { return finalAvg_; }
double Student::getFinalMed() const { return finalMed_; }

void Student::setNd(const std::vector<int>& nd) {
    nd_ = nd;
    calculate();
}

void Student::setEgz(int egz) {
    egz_ = egz;
    calculate();
}

void Student::addNd(int mark) {
    nd_.push_back(mark);
    calculate();
}

void Student::calculate() {
    if (nd_.empty()) {
        finalAvg_ = finalMed_ = 0.6 * egz_;
        return;
    }

    double sum = 0;
    for (int x : nd_) sum += x;
    finalAvg_ = 0.4 * (sum / nd_.size()) + 0.6 * egz_;

    std::vector<int> temp = nd_;
    std::sort(temp.begin(), temp.end());

    double median;
    if (temp.size() % 2 == 0)
        median = (temp.at(temp.size()/2 - 1) + temp.at(temp.size()/2)) / 2.0;
    else
        median = temp.at(temp.size()/2);

    finalMed_ = 0.4 * median + 0.6 * egz_;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.name_ << " " << s.surname_ << " | ND: ";
    for (int x : s.nd_) os << x << " ";
    os << "| Egz: " << s.egz_;
    os << " | Galutinis (Vid): " << s.finalAvg_;
    os << " | Galutinis (Med): " << s.finalMed_;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    s.nd_.clear();

    int n;
    is >> s.name_ >> s.surname_ >> n;

    for (int i = 0; i < n; i++) {
        int x;
        is >> x;
        s.nd_.push_back(x);
    }

    is >> s.egz_;
    s.calculate();

    return is;
}