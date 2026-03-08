#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>
#include "student.h"

double med(const std::vector<int>& nd, int egz);
double avg(const std::vector<int>& nd, int egz);
std::string GenerateName(const std::string& vardas, const std::vector<std::string>& saknys);

bool compareByName(const Student &a, const Student &b);
bool compareBySurname(const Student &a, const Student &b);
bool compareByMed(const Student &a, const Student &b);
bool compareByAvg(const Student &a, const Student &b);

#endif