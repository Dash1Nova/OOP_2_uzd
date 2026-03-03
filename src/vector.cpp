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

char inputLetter(const std::string& message) {
    std::string input;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            if (input.length() != 1)
                throw std::invalid_argument("Turi buti ivesta viena raide.");

            if (!std::isalpha(input[0]))
                throw std::invalid_argument("Leidziamos tik raides.");

            return input[0];
        }
        catch (const std::exception& e) {
            std::cout << "Klaida: " << e.what() << std::endl;
        }
    }
}

std::string inputWord(const std::string& message) {
    std::string text;

    while (true) {
        try {
            std::cout << message;
            std::cin >> text;

            if (text.empty())
                throw std::invalid_argument("Zodis negali buti tuscias.");

            for (char c: text) {
                if (!std::isalpha(c))
                    throw std::invalid_argument("Zodyje gali buti tik raides.");
            }

            return text;
        }
        catch (const std::exception& e) {
            std::cout << "Klaida: " << e.what() << std::endl;
        }
    }
}

int inputInt(const std::string& message, int min = INT_MIN, int max = INT_MAX) {
    std::string input;
    int number;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            size_t pos;
            number = std::stoi(input, &pos);

            if (pos != input.length())
                throw std::invalid_argument("Ivestis nera sveikasis skaicius.");

            if (number < min || number > max)
                throw std::out_of_range("Skaicius nepatenka i leidziamas ribas.");

            return number;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Klaida: reikia ivesti sveikaji skaiciu.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Klaida: ivestas skaicius uz leistinu ribu.\n";
        }
    }
}

double inputR(const std::string& message, double min = INT_MIN, double max = INT_MAX) {
    std::string input;
    double number;

    while (true) {
        try {
            std::cout << message;
            std::cin >> input;

            size_t pos;
            number = std::stod(input, &pos);

            if (pos != input.length())
                throw std::invalid_argument("Ivestis nera realusis skaicius.");

            if (number < min || number > max)
                throw std::out_of_range("Skaicius nepatenka i leidziamas ribas.");

            return number;
        }
        catch (const std::invalid_argument&) {
            std::cout << "Klaida: reikia ivesti realuji skaiciu.\n";
        }
        catch (const std::out_of_range&) {
            std::cout << "Klaida: ivestas skaicius uz leistinu ribu.\n";
        }
    }
}

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
        std::cerr << "createFile klaida: " << e.what() << std::endl;
        return false;
    }
    catch (...) {
        std::cerr << "createFile nezinoma klaida." << std::endl;
        return false;
    }
}

bool readFile(const std::string &filename, std::vector<Student> &Students) {
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

            assert(s.egz >= 1 && s.egz <= 10);

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
        std::cerr << "createFile nezinoma klaida." << std::endl;
        return false;
    }
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
    printResults(Students, outputChoice == 2, "rezultatai.txt");
}

int showMenu() {
    return inputInt(
        "1 - ivesti viska ranka.\n"
        "2 - generuoti tik pazymius.\n"
        "3 - generuoti studentu vardus, pavardes ir pazymius.\n"
        "4 - baigti darba.\n"
        "5 - nuskaityti is failo.\n"
        "Pasirinkite (1-5): ",
        1, 5
    );
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
    int n;
    std::cout << "Kiek namu darbu generuoti kiekvienam studentui: \n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0) {
        std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> n;
    }
    while (true) {
        Student s;
        std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
        std::cin >> s.name;
        if (s.name == "STOP") break;

        std::cout << "Iveskite studento pavarde: \n";
        std::cin >> s.surname;


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


int main() {
    std::vector<Student> Students;
    srand(time(NULL));
    
    while (true) {
    int choice = showMenu();
        
        if (choice == 1) {
            manualInput(Students);
            handleOutput(Students);
            break;
        }
        
        else if (choice == 2) {
            generateGrades(Students);
            handleOutput(Students);
            break;
        }
        
    else if (choice == 3) {
        generateNamesGrades(Students);
        handleOutput(Students);
        break;
    }
        
    else if (choice == 4) break;

    else if (choice == 5) {
    scanFile(Students);
    break;
}
}
    return 0;
}