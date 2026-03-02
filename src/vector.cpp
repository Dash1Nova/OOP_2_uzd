#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cassert>

struct Student {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
    double finalAvg, finalMed;
};

double med(const std::vector<int> &nd, int egz) {
    std::vector<int> temp = nd;
    if (nd.empty()) return 0.6 * egz;
    std::sort(temp.begin(), temp.end());
    double median;
    if (temp.size() % 2 == 1) {
        median = temp.at(temp.size()/2);
    } else {
        median = (temp.at(temp.size()/2 - 1) + temp.at(temp.size()/2))/2.0;
    }
    return 0.4*median + 0.6*egz;
}

double avg(const std::vector<int> &nd, int egz) {
    if (nd.empty()) return 0.6*egz;
    int sum = 0;
        for (int mark : nd) {
            sum += mark;
        }
    return 0.4*(double(sum)/nd.size()) + 0.6*egz;
}

std::string GenerateName(const std::string &vardas, const std::vector<std::string> &saknys) {
    assert(!vardas.empty());
    assert(!saknys.empty());
    std::string saknis = saknys.at(rand() % saknys.size());

    if (vardas.substr(vardas.size() - 2) == "as")
        return saknis + "enis";

    if (vardas.back() == 'a')
        return saknis + "aite";

    return saknis + "is";
}

bool createFile (const std::vector<Student> &Students, int n) {
    std::ofstream kursiokai("kursiokai.txt");
    if (!kursiokai.is_open()) {
    throw std::runtime_error("Nepavyko sukurti failo kursiokai.txt");
    }
    kursiokai << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 0; i < n; i++) {
        kursiokai << std::setw(6) << ("ND" + std::to_string(i+1));
    }
    kursiokai << std::setw(9) << "Egzaminas\n";

    for (const auto &stud: Students) {
        kursiokai << std::left << std::setw(15) << stud.name << std::setw(15) << stud.surname;
        for (const auto &grade: stud.nd) {
            kursiokai << std::setw(6) << grade;
        }
        kursiokai << stud.egz << "\n";
    }
    kursiokai.close();
    return true;
}

bool readFile(const std::string &filename, std::vector<Student> &Students) {
    if (filename.empty()) {
        throw std::runtime_error("Failo pavadinimas negali buti tuscias.");
    }
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
        Student s;
        iss >> s.name >> s.surname;
        int mark;
        while (iss >> mark) {
            assert(mark >= 1 && mark <= 10);
            s.nd.push_back(mark);
        }

        if (s.nd.size() < 2) {
            throw std::runtime_error("Per mazai pazymiu faile.");
        }

        if (s.nd.size() >= 2) {
        s.egz = s.nd.back();
        s.nd.pop_back();

        assert(s.egz >= 1 && s.egz <= 10);

        s.finalAvg = avg(s.nd, s.egz);
        s.finalMed = med(s.nd, s.egz);
        
        Students.push_back(s);
        }
    }
    stud_file.close();
    return true;
}

bool compareByName(const Student &a, const Student &b) {
    if (a.name.length() != b.name.length()) {
        return a.name.length() < b.name.length();
    }
    return a.name < b.name;
}

bool compareBySurname(const Student &a, const Student &b) {
    if (a.surname.length() != b.surname.length()) {
        return a.surname.length() < b.surname.length();
    }
    return a.surname < b.surname;
}

bool compareByMed(const Student &a, const Student &b) {
    return a.finalMed < b.finalMed;
}

bool compareByAvg(const Student &a, const Student &b) {
    return a.finalAvg < b.finalAvg;
}

void printResults(const std::vector<Student> &Students, bool toFile = false, const std::string &filename = "rezultatai.txt") {
    if (Students.empty()) {
        throw std::runtime_error("Studentu sarasas tuscias.");
    }
    std::ofstream file;
    if (toFile) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Nepavyko sukurti failo: " + filename);
        }
    }
    
    std::ostream &out = toFile ? file : std::cout;
    
    out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(17) << "Galutinis (Med.)\n";
    out << "-----------------------------------------------------------------------\n";
    for (const auto& s : Students) {
        out << std::left << std::setw(15) << s.name << std::setw(15) << s.surname << std::setw(20) << std::fixed << std::setprecision(2) << s.finalAvg << std::setw(17) << std::fixed << std::setprecision(2) << s.finalMed << "\n";
    }

    if (toFile) {
        file.close();
    }
}

void outputToFileSorting(std::vector<Student>& Students) {
    int sorting;
    std::cout << "Pasirinkite pagal ka rusiuoti duomenis:\n";
    std::cout << "1 - rusiuoti pagal varda.\n";
    std::cout << "2 - rusiuoti pagal pavarde.\n";
    std::cout << "3 - rusiuoti pagal galutini ivertinima (Vid.).\n";
    std::cout << "4 - rusiuoti pagal galutini ivertinima (Med.).\n";
    std::cin >> sorting;
    while (std::cin.fail() || sorting < 1 || sorting > 4) {
    std::cout << "Klaidinga ivestis. Iveskite 1-4:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> sorting;
    }

    if (sorting == 1)
        std::sort(Students.begin(), Students.end(), compareByName);
    else if (sorting == 2)
        std::sort(Students.begin(), Students.end(), compareBySurname);
    else if (sorting == 3)
        std::sort(Students.begin(), Students.end(), compareByAvg);
    else if (sorting == 4)
        std::sort(Students.begin(), Students.end(), compareByMed);
}

void handleOutput(std::vector<Student>& Students) {
    outputToFileSorting(Students);

    int outputChoice;
    std::cout << "Kur isvesti rezultatus:\n";
    std::cout << "1 - ekrane\n";
    std::cout << "2 - i faila\n";
    std::cin >> outputChoice;

    while (std::cin.fail() || (outputChoice != 1 && outputChoice != 2)) {
        std::cout << "Klaidinga ivestis. Iveskite 1 arba 2:\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> outputChoice;
    }

    if (outputChoice == 2) {
        createFile(Students, Students.at(0).nd.size());
        printResults(Students, true, "rezultatai.txt");
    } else {
        printResults(Students, false);
    }
}

int showMenu() {
    int choice;
    std::cout << "1 - iveskti viska ranka.\n";
    std::cout << "2 - generuoti tik pazymius.\n";
    std::cout << "3 - generuoti studentu vardus, pavardes ir pazymius.\n";
    std::cout << "4 - baigti darba.\n";
    std::cout << "5 - nuskaityti is failo.\n";
    std::cout << "Pasirinkite: \n";
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 5) {
    std::cout << "Klaidinga ivestis. Iveskite skaiciu 1-5:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> choice;
    }
    
    return choice;
}

int main() {
    try {
    Student s;
    int mark;
    std::vector<Student> Students;
    srand(time(NULL));
    
    while (true) {
    int choice = showMenu();
        
        if (choice == 1) {
            while (true) {
                s.nd.clear();
                
                std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
                std::cin >> s.name;
                if (s.name == "STOP") break;
                
                std::cout << "Iveskite studento pavarde: \n";
                std::cin >> s.surname;
                
                std::cout << "Iveskite studento namu darbo ivertinima arba parasykite '0', jei norite baigti ivesti: \n";
                
                while (true) {
                    std::cin >> mark;
                    while (std::cin.fail() || mark < 0 || mark > 10) {
                        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> mark;
                    }
                    if (mark == 0) break;
                    s.nd.push_back(mark);
                }
                
                std::cout << "Iveskite egzamino ivertinima: \n";
                std::cin >> s.egz;
                while (std::cin.fail() || s.egz <= 0 || s.egz > 10) {
                    std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> s.egz;
                }
                
                s.finalAvg = avg(s.nd, s.egz);
                s.finalMed = med(s.nd, s.egz);

                Students.push_back(s);
            }
            handleOutput(Students);
            Students.clear();
            break;
        }
        
        else if (choice == 2) {
    while (true) {
        std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
        std::cin >> s.name;
        if (s.name == "STOP") break;

        std::cout << "Iveskite studento pavarde: \n";
        std::cin >> s.surname;

        int n;
        std::cout << "Kiek namu darbu generuoti: \n";
        std::cin >> n;
        while (std::cin.fail() || n <= 0) {
            std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> n;
        }

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
    handleOutput(Students);
    Students.clear();
    break;
}
        
        else if (choice == 3) {
            int numb, n;
            std::cout << "Kiek studentu generuoti: \n";
            std::cin >> numb;
            std::cout << "Kiek namu darbu generuoti: \n";
            std::cin >> n;
        while (std::cin.fail() || n <= 0) {
            std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> n;
        }
            for (int i = 0; i < numb; i++){
            std::vector<std::string> Names = {"Jonas", "Domantas", "Martynas", "Edvinas", "Evelina", "Karolina", "Gabija", "Livija"};
            std::vector<std::string> Surnames = {"1Pavard", "2Pavard", "3Pavard", "4Pavard", "5Pavard"};

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
            handleOutput(Students);
            Students.clear();
            break;
        }
        
        else if (choice == 4) break;

        else if (choice == 5) {
        std::string filename;
        std::cout << "Iveskite failo pavadinima: ";
        system("powershell ls *.txt");
        std::cin >> filename;
        Students.clear();

        auto start = std::chrono::high_resolution_clock::now();
        
        if (readFile(filename, Students)) {
        std::cout << "Failas sekmingai nuskaitytas!\n";
        outputToFileSorting(Students);
        int outputChoice;
            std::cout << "Kur isvesti rezultatus:\n";
            std::cout << "1 - ekrane\n";
            std::cout << "2 - i faila\n";
            std::cin >> outputChoice;
            
            if (outputChoice == 2) {
                printResults(Students, true, "rezultatai.txt");
            } else {
                printResults(Students, false);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
        std::cout << "Vykdymo laikas: " << duration.count() << " ms\n";
        Students.clear();
    }
    }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range klaida: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime klaida: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Standartine klaida: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Nežinoma klaida." << std::endl;
        return 1;
    }
    return 0;
}