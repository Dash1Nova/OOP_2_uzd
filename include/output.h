#ifndef OUTPUT_H
#define OUTPUT_H

#include <vector>
#include <list>
#include <deque>
#include <string>
#include "student.h"

template <typename Container>
void printResults(const Container& Students, bool toFile = false, const std::string& filename = "rezultatai.txt");
template <typename Container>
void outputToFileSorting(Container& Students);
template <typename Container>
void handleOutput(Container& Students);

#endif