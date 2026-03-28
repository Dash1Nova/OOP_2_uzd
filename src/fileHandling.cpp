#include "fileHandling.h"
#include "calculations.h"
#include "inputValid.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>

template <typename Container>
bool createFile (const Container &Students, int n) {
    try {
        std::ofstream kursiokai("kursiokai.txt");

        if (!kursiokai.is_open()) {
            throw std::runtime_error("Nepavyko sukurti failo kursiokai.txt");
        }
        kursiokai << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
        for (int i = 0; i < n; i++) {
            kursiokai << std::setw(6) << ("ND" + std::to_string(i+1));
        }
        kursiokai << std::setw(9) << "Egzaminas\n";

        for (const auto &stud : Students) {
            kursiokai << std::left << std::setw(15) << stud.getName() << std::setw(15) << stud.getSurname();
            for (const auto &grade : stud.getNd()) {
                kursiokai << std::setw(6) << grade;
            }
            kursiokai << stud.getEgz() << "\n";

            if (!kursiokai) {
                throw std::runtime_error("Klaida rasant i kursiokai.txt");
            }
        }
        return true;
    }
    catch (const std::exception &e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return false;
    }
    catch (...) {
        std::cerr << "Nezinoma klaida." << std::endl;
        return false;
    }
}

template <typename Container>
bool readFile(const std::string &filename, Container &Students) {
    try {
        std::ifstream stud_file(filename);
        if (!stud_file.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo: " + filename);
        }
        std::cout << "Failas '" << filename << "' sekmingai atidarytas.\n";

        std::string line;
        std::getline(stud_file, line);

    while (std::getline(stud_file, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);

        std::string name, surname;
        iss >> name >> surname;

        std::vector<int> nd;
        int mark;

        while (iss >> mark) {
            nd.push_back(mark);
        }

        int egz = nd.back();
        nd.pop_back();

        Student s(name, surname, nd, egz);

        Students.push_back(s);
    }

        stud_file.close();
        return true;

    } catch (const std::exception& e) {
        std::cerr << "Failo atidarymo klaida: " << e.what() << std::endl;
        return false;
    }
    catch (...) {
        std::cerr << "Nezinoma klaida." << std::endl;
        return false;
    }
}

template bool createFile<std::vector<Student>>(const std::vector<Student>&, int);
template bool createFile<std::list<Student>>(const std::list<Student>&, int);
template bool createFile<std::deque<Student>>(const std::deque<Student>&, int);

template bool readFile<std::vector<Student>>(const std::string&, std::vector<Student>&);
template bool readFile<std::list<Student>>(const std::string&, std::list<Student>&);
template bool readFile<std::deque<Student>>(const std::string&, std::deque<Student>&);