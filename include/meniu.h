#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include <list>
#include <deque>
#include "student.h"

int showMeniu();
template <typename Container>
void manualInput(Container& Students);
template <typename Container>
void generateGrades(Container& Students);
template <typename Container>
void generateNamesGrades(Container& Students);
template <typename Container>
void scanFile(Container& Students);
bool generateFile();
void sortingStudents();

#endif