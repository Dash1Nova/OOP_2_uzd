#include "output.h"
#include "inputValid.h"
#include "calculations.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

template <typename Container>
void printResults(const Container &Students, bool toFile, const std::string &filename) {
    if (Students.empty()) {
        throw std::runtime_error("Studentu sarasas tuscias.");
    }
    std::ofstream file;
    if (toFile) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Nepavyko sukurti failo " + filename);
        }
    }
    
    std::ostream &out = toFile ? file : std::cout;
    
    out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(17) << "Galutinis (Med.)\n";
    out << "-----------------------------------------------------------------------\n";
    for (const auto& s : Students) {
        out << std::left << std::setw(15) << s.name << std::setw(15) << s.surname << std::setw(20) << std::fixed << std::setprecision(2) << s.finalAvg << std::setw(17) << std::fixed << std::setprecision(2) << s.finalMed << "\n";
    }
    if (!out) {
        throw std::runtime_error("Klaida rasant rezultatus.");
    }

    if (toFile) {
        file.close();
    }

}

template <typename Container>
void outputToFileSorting(Container& Students) {
    int sorting = inputInt(
    "Pasirinkite pagal ka rusiuoti duomenis:\n"
    "1 - rusiuoti pagal varda.\n"
    "2 - rusiuoti pagal pavarde.\n"
    "3 - rusiuoti pagal galutini ivertinima (Vid.).\n"
    "4 - rusiuoti pagal galutini ivertinima (Med.).\n",
    1, 4);

    switch (sorting) {
        case 1: std::sort(Students.begin(), Students.end(), compareByName); break;
        case 2: std::sort(Students.begin(), Students.end(), compareBySurname); break;
        case 3: std::sort(Students.begin(), Students.end(), compareByAvg); break;
        case 4: std::sort(Students.begin(), Students.end(), compareByMed); break;
    }
}

template <typename Container>
void handleOutput(Container& Students) {
    outputToFileSorting(Students);
    int outputChoice = inputInt(
    "Kur isvesti rezultatus:\n"
    "1 - ekrane\n"
    "2 - i faila\n",
    1, 2);
    printResults(Students, outputChoice == 2, "rezultatai.txt");
}