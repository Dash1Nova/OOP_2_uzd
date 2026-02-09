#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

struct Student {
    std::string name, surname;
    int n, egz;
    int nd[100];
};

int main()
{
    Student s;
    int mark;
    std::vector<Student> Students;
    
    int output;
    
    while (true) {
    
    s.n = 0;

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
            s.nd[s.n++] = mark;
        }
    
    std::cout << "Iveskite egzamino ivertinima: \n";
    std::cin >> s.egz;
    while (std::cin.fail() || s.egz <= 0 || s.egz > 10) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> s.egz;
    }
    
    Students.push_back(s);
}

std::cout << "Kaip skaiciuoti galutini pazymi: naudojant vidurki - iveskite 0, naudojant mediana - iveskite 1: \n";
std::cin >> output;
while (std::cin.fail() || (output != 0 && output != 1)) {
    std::cout << "Klaidinga ivestis. Iveskite 0 arba 1:\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> output;
}

std::cout << " " << std::endl;
std::cout << "Vardas\tPavarde\tGalutinis\n";
std::cout << "----------------------------------------------\n";

for (auto& stud : Students) {
    double final_mark;
    if (output == 0) {
                int sum = 0;
                for (int i = 0; i < stud.n; i++) {
                sum += stud.nd[i];
                }
                double avg = (double)sum/stud.n;
                final_mark = 0.4*avg + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        } else {
            int temp;
            for (int i = 0; i < stud.n; i++) {
                for (int j = i+1; j < stud.n; j++) {
                    if (stud.nd[i] > stud.nd[j]) {
                        temp = stud.nd[i];
                        stud.nd[i] = stud.nd[j];
                        stud.nd[j] = temp;
                    }
                }
            }
            
            double median;
            if (stud.n % 2 == 1) {
                median = stud.nd[stud.n/2];
            } else {
                median = (stud.nd[stud.n/2 - 1] + stud.nd[stud.n/2])/2.0;
            }
            final_mark = 0.4*median + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        }
}
    return 0;
}