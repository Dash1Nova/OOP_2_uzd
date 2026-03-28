#include "output.h"
#include "inputValid.h"
#include "calculations.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <deque>

template <typename Container, typename Compare>
void sortContainer(Container& c, Compare comp) {
    std::sort(c.begin(), c.end(), comp);
}

template <typename Compare>
void sortContainer(std::list<Student>& c, Compare comp) {
    c.sort(comp);
}

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
        out << std::left << std::setw(15) << s.getName() << std::setw(15) << s.getSurname() << std::setw(20) << std::fixed << std::setprecision(2) << s.getFinalAvg() << std::setw(17) << std::fixed << std::setprecision(2) << s.getFinalMed() << "\n";
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
        case 1: sortContainer(Students, compareByName); break;
        case 2: sortContainer(Students, compareBySurname); break;
        case 3: sortContainer(Students, compareByAvg); break;
        case 4: sortContainer(Students, compareByMed); break;
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

template void printResults<std::vector<Student>>(const std::vector<Student>&, bool, const std::string&);
template void printResults<std::list<Student>>(const std::list<Student>&, bool, const std::string&);
template void printResults<std::deque<Student>>(const std::deque<Student>&, bool, const std::string&);

template void outputToFileSorting<std::vector<Student>>(std::vector<Student>&);
template void outputToFileSorting<std::list<Student>>(std::list<Student>&);
template void outputToFileSorting<std::deque<Student>>(std::deque<Student>&);

template void handleOutput<std::vector<Student>>(std::vector<Student>&);
template void handleOutput<std::list<Student>>(std::list<Student>&);
template void handleOutput<std::deque<Student>>(std::deque<Student>&);