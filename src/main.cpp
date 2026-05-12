#include "meniu.h"
#include "output.h"
#include "inputValid.h"
#include "vector.h"
#include <vector>
#include <ctime>
#include <list>
#include <deque>

int main() {
    int meniu = inputInt(
    "Koki konteineri naudoti:\n"
    "1 - vector\n"
    "2 - list\n"
    "3 - deque\n"
    "4 - Vector (custom)\n", 1, 4);

        if (meniu == 1) {
            std::vector<Student> Students;
            while (true) {
            int choice = showMeniu();
            
            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;
            }
        } else if (meniu == 2) {
        std::list<Student> Students;
        while (true) {
            int choice = showMeniu();

            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;
            }
        } else if (meniu == 3) {
        std::deque<Student> Students;
        while (true) {
            int choice = showMeniu();
            
            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);  
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) sortingStudents(Students);
            else if (choice == 7) break;
            }
        } else if (meniu == 4) {
        Vector<Student> Students;

        while (true) {
            int choice = showMeniu();

            if (choice == 1) manualInput(Students), handleOutput(Students);
            else if (choice == 2) generateGrades(Students), handleOutput(Students);
            else if (choice == 3) generateNamesGrades(Students), handleOutput(Students);
            else if (choice == 4) scanFile(Students);
            else if (choice == 5) generateFile();
            else if (choice == 6) {
                std::cout << "studentai_100000.txt:\n";
                sortingStudents(Students, true, "studentai_100000.txt");
                std::cout << "----------------------------\n";
                std::cout << "studentai_1000000.txt:\n";
                sortingStudents(Students, true, "studentai_1000000.txt");
                std::cout << "----------------------------\n";
                std::cout << "studentai_10000000.txt:\n";
                sortingStudents(Students, true, "studentai_10000000.txt");
            }
            else if (choice == 7) break;
            }
        }
    return 0;
}