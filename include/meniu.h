#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include <list>
#include <deque>
#include <string>
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

template <typename Container>
void sortingStudents(Container& Students, bool benchmarkMode = false, const std::string& filename = "");

template <typename Container>
void handleOutput(Container&);

template <typename Container>
bool readFile(const std::string&, Container&);

#endif