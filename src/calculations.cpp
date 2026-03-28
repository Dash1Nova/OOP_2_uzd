#include "calculations.h"
#include <algorithm>
#include <random>


std::string GenerateName(const std::string &vardas, const std::vector<std::string> &saknys) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, saknys.size() - 1);

    std::string saknis = saknys.at(dist(gen));

    if (vardas.substr(vardas.size() - 2) == "as")
        return saknis + "enis";

    if (vardas.back() == 'a')
        return saknis + "aite";

    return saknis + "is";
}

bool compareByName(const Student &a, const Student &b) {
    if (a.getName().length() != b.getName().length()) {
        return a.getName().length() < b.getName().length();
    }
    return a.getName() < b.getName();
}

bool compareBySurname(const Student &a, const Student &b) {
    if (a.getSurname().length() != b.getSurname().length()) {
        return a.getSurname().length() < b.getSurname().length();
    }
    return a.getSurname() < b.getSurname();
}

bool compareByMed(const Student &a, const Student &b) {
    return a.getFinalMed() < b.getFinalMed();
}

bool compareByAvg(const Student &a, const Student &b) {
    return a.getFinalAvg() < b.getFinalAvg();
}