#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include "student.h"

int showMeniu();
void manualInput(std::vector<Student>& Students);
void generateGrades(std::vector<Student>& Students);
void generateNamesGrades(std::vector<Student>& Students);
void scanFile(std::vector<Student>& Students);
bool generateFile();

#endif