#include "student.h"
#include <algorithm>

Student::Student() : egz_(0), finalAvg_(0), finalMed_(0) {}

Student::Student(const std::string& name, const std::string& surname, const std::vector<int>& nd, int egz)
    : name_(name), surname_(surname), nd_(nd), egz_(egz) {
    calculate();
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
        median = (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
    else
        median = temp[temp.size()/2];

    finalMed_ = 0.4 * median + 0.6 * egz_;
}