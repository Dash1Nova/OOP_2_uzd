#include <iostream>

struct Student {
    std::string name, surname;
    int n, nd, egz, sum;
    float final_mark, avg;
};

int main()
{
    Student s;
    std::cout << "Iveskite studento varda ir pavarde: " << std::endl;
    std::cin >> s.name >> s.surname;
    return 0;
}