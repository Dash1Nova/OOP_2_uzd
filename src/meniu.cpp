#include "meniu.h"
#include "inputValid.h"
#include "calculations.h"
#include "output.h"
#include "fileHandling.h"
#include <iostream>
#include <chrono>

int showMeniu() {
    return inputInt(
        "1 - ivesti viska ranka.\n"
        "2 - generuoti tik pazymius.\n"
        "3 - generuoti studentu vardus, pavardes ir pazymius.\n"
        "4 - baigti darba.\n"
        "5 - nuskaityti is failo.\n"
        "Pasirinkite (1-5): ",
        1, 5);
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