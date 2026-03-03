#ifndef INPUT_H
#define INPUT_H

#include <string>

char inputLetter(const std::string& message);
std::string inputWord(const std::string& message);
int inputInt(const std::string& message, int min = INT_MIN, int max = INT_MAX);
double inputR(const std::string& message, double min = INT_MIN, double max = INT_MAX);

#endif