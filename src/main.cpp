#include "meniu.h"
#include "output.h"
#include <vector>
#include <ctime>

int main() {
    std::vector<Student> Students;
    srand(time(NULL));
    
    while (true) {
    int choice = showMeniu();
        
    if (choice == 1) {
        manualInput(Students);
        handleOutput(Students);
    }
    else if (choice == 2) {
        generateGrades(Students);
        handleOutput(Students);
    }
    else if (choice == 3) {
        generateNamesGrades(Students);
        handleOutput(Students);
    }    
    else if (choice == 4) {
        scanFile(Students);
    }
    else if (choice == 5) {
        generateFile();
    }
    else if (choice == 6) {
        sortingStudents();
    }
    else if (choice == 7) break;
    }
    return 0;
}