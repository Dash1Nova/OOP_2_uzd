#include <iostream>

struct Student {
    std::string name, surname;
    int n, nd, egz, sum;
    float final_mark, avg;
};

int main()
{
    Student s;
    std::cout << "Iveskite studento varda: " << std::endl;
    std::cin >> s.name;
    std::cout << "Iveskite studento pavarde: " << std::endl;
    std::cin >> s.surname;
    std::cout << "Iveskite namu darbu skaiciu: " << std::endl;
    std::cin >> s.n;
    s.sum = 0;
    for (int i = 0; i < s.n; i++) {
        std::cout << "Iveskite " << i + 1 << " darbo ivertinima: " << std::endl;
        std::cin >> s.nd;
        s.sum += s.nd;
    }
    s.avg = s.sum/s.n;
    std::cout << "Iveskite egzamino ivertinima: " << std::endl;
    std::cin >> s.egz;
    s.final_mark = 0.4*s.avg + 0.6*s.egz;
    std::cout << " " << std::endl;
    std::cout << "Vardas\tPavarde\tGalutinis (Vid.)" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << s.name << "\t" << s.surname << "\t" << s.final_mark << std::endl;
    return 0;
}