#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

struct Student {
    std::string name, surname;
    int n, egz;
    std::vector<int> nd;
};

int main()
{
    Student s;
    int mark;

    int sum, output;
    double avg, median, final_mark;
    
    std::cout << "Iveskite studento varda: \n";
    std::cin >> s.name;
    std::cout << "Iveskite studento pavarde: \n";
    std::cin >> s.surname;
    std::cout << "Iveskite namu darbu skaiciu: \n";
    std::cin >> s.n;
    while (std::cin.fail() || s.n <= 0) {
        std::cout << "Klaidinga ivestis. Iveskite teigiama skaiciu.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> s.n;
    }

    sum = 0;
    for (int i = 0; i < s.n; i++) {
        std::cout << "Iveskite " << i + 1 << " darbo ivertinima: \n";
        std::cin >> mark;
        while (std::cin.fail() || mark <= 0 || mark > 10) {
            std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> mark;
        }
        s.nd.push_back(mark);
        sum += mark;
    }

    std::cout << "Iveskite egzamino ivertinima: \n";
    std::cin >> s.egz;
    while (std::cin.fail() || s.egz <= 0 || s.egz > 10) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu nuo 1 iki 10 imtinai.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> s.egz;
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
        
        if (output == 0) {
            avg = (double)sum/s.n;
            final_mark = 0.4*avg + 0.6*s.egz;
            std::cout << "Vardas\tPavarde\tGalutinis (Vid.)\n";
            std::cout << "----------------------------------------------------\n";
            std::cout << s.name << "\t" << s.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        } else {
            std::sort(s.nd.begin(), s.nd.end());
            if (s.n % 2 == 1) {
                median = s.nd.at(s.n/2);
            } else {
                median = (s.nd.at(s.n/2 - 1) + s.nd.at(s.n/2))/2.0;
            }
            final_mark = 0.4*median + 0.6*s.egz;
            std::cout << "Vardas\tPavarde\tGalutinis (Med.)\n";
            std::cout << "----------------------------------------------------\n";
            std::cout << s.name << "\t" << s.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
    }

    return 0;
}