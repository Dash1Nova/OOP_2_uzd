#include "fileHandling.h"
#include "calculations.h"
#include "inputValid.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

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
            kursiokai << std::left << std::setw(15) << stud.name << std::setw(15) << stud.surname;
            for (const auto &grade : stud.nd) {
                kursiokai << std::setw(6) << grade;
            }
            kursiokai << stud.egz << "\n";

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

            Student s;
            std::istringstream iss(line);

            iss >> s.name >> s.surname;
            int mark;
            while (iss >> mark) {
                s.nd.push_back(mark);
            }

            s.egz = s.nd.back();
            s.nd.pop_back();

            s.finalAvg = avg(s.nd, s.egz);
            s.finalMed = med(s.nd, s.egz);

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