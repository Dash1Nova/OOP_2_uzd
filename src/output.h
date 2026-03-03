#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <string>
#include "student.h"

void printResults(const std::vector<Student>& Students, bool toFile = false, const std::string& filename = "rezultatai.txt");
void outputToFileSorting(std::vector<Student>& Students);
void handleOutput(std::vector<Student>& Students);

#endif