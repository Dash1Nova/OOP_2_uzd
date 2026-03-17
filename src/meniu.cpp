#include "meniu.h"
#include "inputValid.h"
#include "calculations.h"
#include "output.h"
#include "fileHandling.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

int showMeniu() {
    return inputInt(
        "1 - ivesti viska ranka.\n"
        "2 - generuoti tik pazymius.\n"
        "3 - generuoti studentu vardus, pavardes ir pazymius.\n"
        "4 - nuskaityti is failo.\n"
        "5 - generuoti failus.\n"
        "6 - rusiuoti studentus i du atskirus failus.\n"
        "7 - baigti darba.\n"
        "Pasirinkite (1-7): ",
        1, 7);
}

template <typename Container>
void manualInput(Container& Students) {
    while (true) {
        Student s;
        std::string name = inputWord(
            "Iveskite studento varda arba zodi STOP, jei norite baigti: \n"
        );
        if (name == "STOP") break;
        s.name = name;
        s.surname = inputWord("Iveskite studento pavarde: \n");
        std::cout << "Iveskite namu darbu pazymius arba 0, jei norite baigti ivesti): \n";
        while (true) {
            int mark = inputInt("Namu darbo pazymys: \n", 0, 10);
            if (mark == 0) break;
            s.nd.push_back(mark);
        }
        s.egz = inputInt("Iveskite egzamino ivertinima: \n", 1, 10);

        s.finalAvg = avg(s.nd, s.egz);
        s.finalMed = med(s.nd, s.egz);

        Students.push_back(s);
    }
}

template <typename Container>
void generateGrades(Container& Students) {
    int n = inputInt("Kiek namu darbu generuoti kiekvienam studentui: \n", 1);
    while (true) {
        Student s;
        s.name = inputWord("Iveskite studento varda arba zodi 'STOP', jei norite baigti:\n");
        if (s.name == "STOP" || s.name == "stop") break;
        s.surname = inputWord("Iveskite studento pavarde: \n");
        
        s.nd.clear();
        for (int i = 0; i < n; i++) {
            int exs = (rand() % 10) + 1;
            s.nd.push_back(exs);
        }
        s.egz = (rand() % 10) + 1;

        s.finalAvg = avg(s.nd, s.egz);
        s.finalMed = med(s.nd, s.egz);

        Students.push_back(s);
    }
}

template <typename Container>
void generateNamesGrades(Container& Students) {
    int numb = inputInt("Kiek studentu generuoti: \n", 1);
    int n = inputInt("Kiek namu darbu generuoti: \n", 1);
    
    std::vector<std::string> Names = {"Jonas", "Domantas", "Martynas", "Edvinas", "Evelina", "Karolina", "Gabija", "Livija"};
    std::vector<std::string> Surnames = {"1Pavard", "2Pavard", "3Pavard", "4Pavard", "5Pavard"};
        
    for (int i = 0; i < numb; i++){
        Student s;
        s.name = Names.at(rand() % Names.size());
        s.surname = GenerateName(s.name, Surnames);
            
        s.nd.clear();
        for (int i = 0; i < n; i++) {
        int exs = (rand() % 10) + 1;
        s.nd.push_back(exs);
        }
        s.egz = (rand() % 10) + 1;

        s.finalAvg = avg(s.nd, s.egz);
        s.finalMed = med(s.nd, s.egz);

        Students.push_back(s);
        }
}

template <typename Container>
void scanFile(Container& Students) {
    std::string filename;
    std::cout << "Iveskite failo pavadinima: ";
    system("powershell ls *.txt");
    std::cin >> filename;
    Students.clear();
        
    try {
        if (readFile(filename, Students)) {
            std::cout << "Failas sekmingai nuskaitytas!\n";
            handleOutput(Students);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Klaida atidarant faila: " << e.what() << std::endl;
    }
}

bool generateFile() {
    try {
    int ndCount = 5;
    int fnumb;
    long long records;
    
    fnumb = inputInt("Kiek failu generuoti: \n", 1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> grade(1, 10);

        for (int f = 0; f < fnumb; f++) {

            records = inputInt("Kokio dydzio faila generuoti? Iveskite irasu skaiciu:\n", 1);
            std::string filename = "data/studentai_" + std::to_string(records) + ".txt";

            std::ofstream file(filename);

            if (!file.is_open()) {
                throw std::runtime_error("Nepavyko sukurti failo.");
            }

            file << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";

            for (int i = 0; i < ndCount; i++) {
                file << std::setw(6) << ("ND" + std::to_string(i + 1));
            }

            file << std::setw(9) << "Egzaminas.\n";

            for (long long i = 1; i <= records; ++i) {
                file << std::left << std::setw(15) << ("Vardas" + std::to_string(i)) << std::setw(15) << ("Pavarde" + std::to_string(i));

                for (int j = 0; j < ndCount; j++) {
                    file << std::setw(6) << grade(gen);
                }

                file << std::setw(10) << grade(gen) << "\n";
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
void sortingStudents(Container& students) {
    std::string filename;
    std::cout << "Koki faila rusiuoti i vargsiukus ir kietakius: \n";
    system("powershell ls data/*.txt");
    std::cin >> filename;

    std::ifstream in("data/" + filename);
    if (!in.is_open()) return;

    students.clear();
    std::string line;
    std::getline(in, line);

    auto readStart = std::chrono::high_resolution_clock::now();

    Student temp;
    int score;
    while (in >> temp.name >> temp.surname) {
        temp.nd.clear();
        for (int i = 0; i < 5; i++) {
            in >> score;
            temp.nd.push_back(score);
        }
        in >> temp.egz;

        temp.finalAvg = avg(temp.nd, temp.egz);
        students.push_back(temp);
    }
    in.close();

    auto readEnd = std::chrono::high_resolution_clock::now();
    double readTime = std::chrono::duration<double>(readEnd - readStart).count();
    std::cout << "Failo skaitymas uztruko: " << readTime << " s\n";
    std::cout << "Is viso studentu: " << students.size() << "\n";

    int choiceOutput = inputInt("Rusiuoti pagal:\n"
        "1 - Varda\n"
        "2 - Pavarde\n"
        "3 - Galutini bala\n", 1, 3);

    auto sortStart = std::chrono::high_resolution_clock::now();

    if constexpr (std::is_same_v<Container, std::list<Student>>) {
        if (choiceOutput == 1) students.sort(compareByName);
        else if (choiceOutput == 2) students.sort(compareBySurname);
        else students.sort(compareByAvg);
    } else {
        if (choiceOutput == 1) std::sort(students.begin(), students.end(), compareByName);
        else if (choiceOutput == 2) std::sort(students.begin(), students.end(), compareBySurname);
        else std::sort(students.begin(), students.end(), compareByAvg);
    }

    auto sortEnd = std::chrono::high_resolution_clock::now();
    double sortTime = std::chrono::duration<double>(sortEnd - sortStart).count();
    std::cout << "Bendras studentu rusiavimas uztruko: " << sortTime << " s\n";

    auto splitStart = std::chrono::high_resolution_clock::now();

    /*Container vargsiukai, kietiakai;
    for (const auto& s : students) {
        if (s.finalAvg < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }*/

    
    Container vargsiukai;
    for (auto it = students.begin(); it != students.end(); ) {
        if (it->finalAvg < 5.0) {
            vargsiukai.push_back(*it);
            it = students.erase(it);
        }
        else {
            ++it;
        }
    }
    

    /*
    auto it = std::partition(students.begin(), students.end(),
    [](const Student& s) { return s.finalAvg >= 5.0; });

    Container vargsiukai(it, students.end());
    students.erase(it, students.end());
    */

    auto splitEnd = std::chrono::high_resolution_clock::now();
    double splitTime = std::chrono::duration<double>(splitEnd - splitStart).count();
    std::cout << "Studentu skirstymas i dvi grupes uztruko: " << splitTime << " s\n";
    
    auto saveToFile = [](const auto& students, const std::string& filename) {
        std::ofstream out(filename);
        if (!out.is_open()) {
            std::cout << "Nepavyko atidaryti failo.\n";
            return;
        }
        
        out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(17) << "Galutinis (Vid.)\n";
        out << "--------------------------------------------------------\n";
        for (const auto& s : students) {
            out << std::left << std::setw(15) << s.name << std::setw(15) << s.surname << std::setw(17) << std::fixed << std::setprecision(2) << s.finalAvg << "\n";
        }
    };

    saveToFile(vargsiukai, "data/vargsiukai.txt");
    saveToFile(kietiakai, "data/kietiakai.txt");

    std::cout << "Bendras vykdymo laikas: " << readTime + sortTime + splitTime << " s\n";
}

template void manualInput<std::vector<Student>>(std::vector<Student>&);
template void manualInput<std::list<Student>>(std::list<Student>&);
template void manualInput<std::deque<Student>>(std::deque<Student>&);

template void generateGrades<std::vector<Student>>(std::vector<Student>&);
template void generateGrades<std::list<Student>>(std::list<Student>&);
template void generateGrades<std::deque<Student>>(std::deque<Student>&);

template void generateNamesGrades<std::vector<Student>>(std::vector<Student>&);
template void generateNamesGrades<std::list<Student>>(std::list<Student>&);
template void generateNamesGrades<std::deque<Student>>(std::deque<Student>&);

template void scanFile<std::vector<Student>>(std::vector<Student>&);
template void scanFile<std::list<Student>>(std::list<Student>&);
template void scanFile<std::deque<Student>>(std::deque<Student>&);

template void sortingStudents<std::vector<Student>>(std::vector<Student>&);
template void sortingStudents<std::list<Student>>(std::list<Student>&);
template void sortingStudents<std::deque<Student>>(std::deque<Student>&);