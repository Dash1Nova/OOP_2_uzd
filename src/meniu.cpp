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

int showMeniu() {
    return inputInt(
        "1 - ivesti viska ranka.\n"
        "2 - generuoti tik pazymius.\n"
        "3 - generuoti studentu vardus, pavardes ir pazymius.\n"
        "4 - baigti darba.\n"
        "5 - nuskaityti is failo.\n"
        "6 - generuoti failus.\n"
        "7 - rusiuoti studentus i du atskirus failus.\n"
        "Pasirinkite (1-7): ",
        1, 7);
}

void manualInput(std::vector<Student>& Students) {
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

void generateGrades(std::vector<Student>& Students) {
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

void generateNamesGrades(std::vector<Student>& Students) {
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

void scanFile(std::vector<Student>& Students) {
    std::string filename;
    std::cout << "Iveskite failo pavadinima: ";
    system("powershell ls *.txt");
    std::cin >> filename;
    Students.clear();

    auto start = std::chrono::high_resolution_clock::now();
        
    try {
        if (readFile(filename, Students)) {
            std::cout << "Failas sekmingai nuskaitytas!\n";
            handleOutput(Students);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Klaida atidarant faila: " << e.what() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Vykdymo laikas: " << duration.count() << " ms\n";
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

void sortingStudents() {
    std::string filename;
    std::cout << "Koki faila rusiuoti i vargsiukus ir kietakius: \n";
    system("powershell ls data/*.txt");
    std::cin >> filename;
    std::ifstream in(filename);
    if (!in.is_open()) return;

    std::vector<Student> vargsiukai, kietiakai;
    std::string line;
    std::getline(in, line);

    Student temp;
    int score;
    while (in >> temp.name >> temp.surname) {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            in >> score;
            sum += score;
        }
        in >> temp.egz;
        temp.finalAvg = avg(temp.nd, temp.egz);

        if (temp.finalAvg < 5.0) vargsiukai.push_back(temp);
        else kietiakai.push_back(temp);
    }
    in.close();

    auto saveToFile = [](const std::vector<Student>& students, std::string filename) {
        std::ofstream out(filename);
        for (const auto& s : students) {
            out << s.name << " " << s.surname << " " << s.finalAvg << "\n";
        }
    };

    saveToFile(vargsiukai, "vargsiukai" + filename);
    saveToFile(kietiakai, "kietiakai" + filename);
}