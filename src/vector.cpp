#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

struct Student {
    std::string name, surname;
    int egz;
    std::vector<int> nd;
};

void Output(const std::vector<Student>& Students) {
    int output;
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
            for (int mark : stud.nd) {
                sum += mark;
            }
            double avg = (double)sum/stud.nd.size();
            final_mark = 0.4*avg + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        } else {
            std::vector<int> temp = stud.nd;
            std::sort(temp.begin(), temp.end());
            double median;
            if (temp.size() % 2 == 1) {
                median = temp.at(temp.size()/2);
            } else {
                median = (temp.at(temp.size()/2 - 1) + temp.at(temp.size()/2))/2.0;
            }
            final_mark = 0.4*median + 0.6*stud.egz;
            std::cout << stud.name << "\t" << stud.surname << "\t" << std::fixed << std::setprecision(2) << final_mark << "\n";
        }
    }

}

std::string generateRandomString(int length) {
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::string result = "";

    for (int i = 0; i < length; i++) {
        char c = letters[rand() % letters.size()];
        result += c;
    }

    return result;
}

int main()
{
    Student s;
    int mark;
    std::vector<Student> Students;
    
    int choice;
    srand(time(NULL));

    while (true) {
        std::cout << "Iveskite skaiciu: \n";
        std::cout << "1 - iveskti viska ranka.\n";
        std::cout << "2 - generuoti tik pazymius.\n";
        std::cout << "3 - generuoti studentu vardus, pavardes ir pazymius.\n";
        std::cout << "4 - baigti darba.\n";
        std::cin >> choice;
        while (std::cin.fail() || choice < 1 || choice > 4) {
        std::cout << "Klaidinga ivestis. Iveskite skaiciu 1-4:\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
        }
        
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
                
                Students.push_back(s);
            }
            Output(Students);
            break;
        }
        
        else if (choice == 2) {
        int n;
        std::cout << "Iveskite studento varda arba zodi 'STOP', jei norite baigti ivesti: \n";
        std::cin >> s.name;
            if (s.name == "STOP") break;
        std::cout << "Iveskite studento pavarde: \n";
        std::cin >> s.surname;
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
            Students.push_back(s);
            Output(Students);
            break;
        }
        
        else if (choice == 3) {
            int numb, n;
            std::cout << "Kiek studentu generuoti: " << std::endl;
            std::cin >> numb;
            for (int i = 0; i < numb; i++){
            s.name = generateRandomString(8);
            s.surname = generateRandomString(10);
            
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
            Students.push_back(s);
            }
            Output(Students);
            break;
        }
        
        else if (choice == 4) break;
    }
    

    return 0;
}