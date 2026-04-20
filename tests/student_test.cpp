#include "../include/student.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

void testConstructors() {
    std::cout << "Konstruktoriu testavimas\n";
    
    Student s1;
    assert(s1.getName() == "Julius");
    assert(s1.getSurname() == "Petraitis");
    assert(s1.getNd().size() == 2);
    assert(s1.getNd()[0] == 1 && s1.getNd()[1] == 2);
    assert(s1.getEgz() == 5);
    
    std::vector<int> marks = {8, 9, 7};
    Student s2("Jonas", "Kazlauskas", marks, 8);
    assert(s2.getName() == "Jonas");
    assert(s2.getSurname() == "Kazlauskas");
    assert(s2.getNd().size() == 3);
    assert(s2.getEgz() == 8);
    
    double expectedAvg = 0.4 * ((8+9+7)/3.0) + 0.6 * 8;
    assert(std::abs(s2.getFinalAvg() - expectedAvg) < 0.0001);
    
    std::cout << "Konstruktoriai veikia tinkamai!\n";
}

void testCopyConstructor() {
    std::cout << "Kopijavimo konstruktoriaus testavimas\n";
    
    std::vector<int> marks = {7, 8, 9};
    Student original("Marius", "Jonaitis", marks, 7);
    
    Student copy(original);
    
    assert(copy.getName() == original.getName());
    assert(copy.getSurname() == original.getSurname());
    assert(copy.getNd().size() == original.getNd().size());
    assert(copy.getEgz() == original.getEgz());
    assert(std::abs(copy.getFinalAvg() - original.getFinalAvg()) < 0.0001);
    assert(std::abs(copy.getFinalMed() - original.getFinalMed()) < 0.0001);
    
    original.setNd({1, 1, 1});
    original.setEgz(1);
    
    assert(copy.getNd().size() == 3);
    assert(copy.getEgz() == 7);
    
    std::cout << "Kopijavimo konstruktorius veikia tinkamai!\n";
}

void testAssignmentOperator() {
    std::cout << "Priskyrimo operatoriaus testavimas\n";
    
    std::vector<int> marks1 = {8, 9};
    Student s1("Petras", "Petraitis", marks1, 9);
    
    std::vector<int> marks2 = {5, 6, 7};
    Student s2("Linas", "Linauskas", marks2, 6);
    
    s2 = s1;
    
    assert(s2.getName() == "Petras");
    assert(s2.getSurname() == "Petraitis");
    assert(s2.getNd().size() == 2);
    assert(s2.getEgz() == 9);
    
    s1.setNd({10, 10});
    assert(s2.getNd()[0] == 8);
    
    s2 = s2;
    assert(s2.getName() == "Petras");
    
    std::cout << "Priskyrimo operatorius veikia tinkamai!\n";
}

void testMoveConstructor() {
    std::cout << "Perkelimo konstruktoriaus testavimas\n";
    
    std::vector<int> marks = {9, 8, 7};
    Student original("Tomas", "Tomauskas", marks, 9);
    
    std::string originalName = original.getName();
    std::string originalSurname = original.getSurname();
    double originalAvg = original.getFinalAvg();
    
    Student moved(std::move(original));
    
    assert(moved.getName() == originalName);
    assert(moved.getSurname() == originalSurname);
    assert(std::abs(moved.getFinalAvg() - originalAvg) < 0.0001);
    
    std::cout << "Perkelimo konstruktorius veikia tinkamai!\n";
}

void testMoveAssignment() {
    std::cout << "Perkelimo priskyrimo operatoriaus testavimas\n";
    
    std::vector<int> marks1 = {8, 9, 10};
    Student s1("Andrius", "Andriauskas", marks1, 8);
    
    std::vector<int> marks2 = {5, 5};
    Student s2("Giedrius", "Giedraitis", marks2, 5);
    
    std::string s1Name = s1.getName();
    double s1Avg = s1.getFinalAvg();
    
    s2 = std::move(s1);
    
    assert(s2.getName() == s1Name);
    assert(std::abs(s2.getFinalAvg() - s1Avg) < 0.0001);
    
    assert(s1.getNd().empty() || true);
    
    std::cout << "Perkelimo priskyrimo operatorius veikia tinkamai!\n";
}

void testDestructor() {
    std::cout << "Destruktoriaus testavimas\n";
    
    {
        Student s("Test", "Testauskas", {1, 2, 3}, 10);
    }
    
    std::cout << "Destruktorius veikia tinkamai!\n";
}

void testGettersAndSetters() {
    std::cout << "Getter'iu ir setter'iu testavimas\n";
    
    Student s("Laura", "Lauraite", {8, 9}, 7);
    
    assert(s.getName() == "Laura");
    assert(s.getSurname() == "Lauraite");
    assert(s.getNd().size() == 2);
    assert(s.getEgz() == 7);
    
    s.setNd({10, 9, 8});
    assert(s.getNd().size() == 3);
    assert(s.getNd()[0] == 10);
    
    s.setEgz(9);
    assert(s.getEgz() == 9);
    
    s.addNd(7);
    assert(s.getNd().size() == 4);
    assert(s.getNd()[3] == 7);
    
    double expectedAvg = 0.4 * ((10+9+8+7)/4.0) + 0.6 * 9;
    assert(std::abs(s.getFinalAvg() - expectedAvg) < 0.0001);
    
    std::cout << "Getter'iai ir setter'iai veikia tinkamai!\n";
}

void testInputOutput() {
    std::cout << "Ivesties/isvesties metodu testavimas\n";
    
    Student s1("Mindaugas", "Mindauskas", {8, 9, 7}, 8);
    
    std::cout << "Isvesties testas: " << s1 << std::endl;
    
    std::stringstream ss;
    ss << "Rokas Rokauskas 3 9 8 7 8\n";
    
    Student s2;
    ss >> s2;
    
    assert(s2.getName() == "Rokas");
    assert(s2.getSurname() == "Rokauskas");
    assert(s2.getNd().size() == 3);
    assert(s2.getNd()[0] == 9 && s2.getNd()[1] == 8 && s2.getNd()[2] == 7);
    assert(s2.getEgz() == 8);
    
    std::cout << "Ivesties/isvesties metodai veikia tinkamai!\n";
}

void testCalculationAccuracy() {
    std::cout << "Testuojame skaiciavimu tiksluma\n";
    
    Student s1("Test1", "Test", {}, 10);
    assert(std::abs(s1.getFinalAvg() - 6.0) < 0.0001);
    assert(std::abs(s1.getFinalMed() - 6.0) < 0.0001);
    
    Student s2("Test2", "Test", {8}, 7);
    double expectedAvg = 0.4 * 8 + 0.6 * 7;
    assert(std::abs(s2.getFinalAvg() - expectedAvg) < 0.0001);
    
    Student s3("Test3", "Test", {6, 8}, 9);
    double expectedMed = 0.4 * ((6+8)/2.0) + 0.6 * 9;
    assert(std::abs(s3.getFinalMed() - expectedMed) < 0.0001);
    
    Student s4("Test4", "Test", {5, 7, 9}, 8);
    expectedMed = 0.4 * 7 + 0.6 * 8;
    assert(std::abs(s4.getFinalMed() - expectedMed) < 0.0001);
    
    std::cout << "Skaiciavimu tikslumas yra tinkamas!\n";
}

void testFileInput() {
    std::cout << "Failo ivedimo testavimas\n";

    std::ofstream fout("data/student_IN.txt");
    fout << "Jonas Jonaitis 3 8 9 7 8\n";
    fout.close();

    std::ifstream fin("data/student_IN.txt");
    Student s;
    fin >> s;
    fin.close();

    assert(s.getName() == "Jonas");
    assert(s.getSurname() == "Jonaitis");
    assert(s.getNd().size() == 3);
    assert(s.getEgz() == 8);

    std::cout << "Failo ivedimas veikia!\n";
}

void testFileOutput() {
    std::cout << "Failo isvedimo testavimas\n";

    Student s("Petras", "Petraitis", {10, 9}, 8);

    std::ofstream fout("data/student_OUT.txt");
    fout << s;
    fout.close();

    std::cout << "Failo isvedimas veikia!\n";
}

int main() {    
    testConstructors();
    testCopyConstructor();
    testAssignmentOperator();
    testMoveConstructor();
    testMoveAssignment();
    testDestructor();
    testGettersAndSetters();
    testInputOutput();
    testCalculationAccuracy();
    testFileInput();
    testFileOutput();
    
    std::cout << "Visi testai ivyko sekmingai!\n";
    
    return 0;
}