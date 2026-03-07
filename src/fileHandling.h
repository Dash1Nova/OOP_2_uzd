#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <vector>
#include <string>
#include "student.h"

bool createFile(const std::vector<Student>& Students, int n);
bool readFile(const std::string& filename, std::vector<Student>& Students);
bool generateFile(const std::string &filename);

#endif