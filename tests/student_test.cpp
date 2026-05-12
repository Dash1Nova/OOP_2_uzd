#include <gtest/gtest.h>
#include "../include/student.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>

TEST(StudentTest, Constructors) {
    Student s1;

    EXPECT_EQ(s1.getName(), "Julius");
    EXPECT_EQ(s1.getSurname(), "Petraitis");
    EXPECT_EQ(s1.getNd().size(), 2);
    EXPECT_EQ(s1.getNd()[0], 1);
    EXPECT_EQ(s1.getNd()[1], 2);
    EXPECT_EQ(s1.getEgz(), 5);

    std::vector<int> marks = {8, 9, 7};
    Student s2("Jonas", "Kazlauskas", marks, 8);

    EXPECT_EQ(s2.getName(), "Jonas");
    EXPECT_EQ(s2.getSurname(), "Kazlauskas");
    EXPECT_EQ(s2.getNd().size(), 3);
    EXPECT_EQ(s2.getEgz(), 8);

    double expectedAvg = 0.4 * ((8+9+7)/3.0) + 0.6 * 8;
    EXPECT_NEAR(s2.getFinalAvg(), expectedAvg, 0.0001);
}

TEST(StudentTest, CopyConstructor) {
    std::vector<int> marks = {7, 8, 9};
    Student original("Marius", "Jonaitis", marks, 7);

    Student copy(original);

    EXPECT_EQ(copy.getName(), original.getName());
    EXPECT_EQ(copy.getSurname(), original.getSurname());
    EXPECT_EQ(copy.getNd().size(), original.getNd().size());
    EXPECT_EQ(copy.getEgz(), original.getEgz());

    EXPECT_NEAR(copy.getFinalAvg(), original.getFinalAvg(), 0.0001);
    EXPECT_NEAR(copy.getFinalMed(), original.getFinalMed(), 0.0001);

    original.setNd({1,1,1});
    original.setEgz(1);

    EXPECT_EQ(copy.getEgz(), 7);
}

TEST(StudentTest, AssignmentOperator) {
    Student s1("Petras", "Petraitis", {8,9}, 9);
    Student s2("Linas", "Linauskas", {5,6,7}, 6);

    s2 = s1;

    EXPECT_EQ(s2.getName(), "Petras");
    EXPECT_EQ(s2.getSurname(), "Petraitis");
    EXPECT_EQ(s2.getNd().size(), 2);
    EXPECT_EQ(s2.getEgz(), 9);

    s1.setNd({10,10});
    EXPECT_EQ(s2.getNd()[0], 8);

    s2 = s2;
    EXPECT_EQ(s2.getName(), "Petras");
}

TEST(StudentTest, MoveConstructor) {
    std::vector<int> marks = {9,8,7};
    Student original("Tomas", "Tomauskas", marks, 9);

    std::string name = original.getName();
    double avg = original.getFinalAvg();

    Student moved(std::move(original));

    EXPECT_EQ(moved.getName(), name);
    EXPECT_NEAR(moved.getFinalAvg(), avg, 0.0001);

    EXPECT_TRUE(original.getName().empty());
    EXPECT_TRUE(original.getSurname().empty());
    EXPECT_TRUE(original.getNd().empty());
    EXPECT_EQ(original.getEgz(), 0);
}

TEST(StudentTest, MoveAssignment) {
    Student s1("Andrius", "Andriauskas", {8,9,10}, 8);
    Student s2("Giedrius", "Giedrauskas", {5,5}, 5);

    std::string name = s1.getName();
    double avg = s1.getFinalAvg();

    s2 = std::move(s1);

    EXPECT_EQ(s2.getName(), name);
    EXPECT_NEAR(s2.getFinalAvg(), avg, 0.0001);

    EXPECT_TRUE(s1.getName().empty());
    EXPECT_TRUE(s1.getNd().empty());
}

TEST(StudentTest, DestructorDoesNotCrash) {
    EXPECT_NO_THROW({
        Student s("Test", "Testauskas", {1, 2, 3}, 10);
    });
}

TEST(StudentTest, GettersSetters) {
    Student s("Laura", "Lauraite", {8,9}, 7);

    EXPECT_EQ(s.getName(), "Laura");
    EXPECT_EQ(s.getNd().size(), 2);

    s.setNd({10,9,8});
    EXPECT_EQ(s.getNd()[0], 10);

    s.setEgz(9);
    EXPECT_EQ(s.getEgz(), 9);

    s.addNd(7);
    EXPECT_EQ(s.getNd().size(), 4);
}

TEST(StudentTest, InputOutput) {
    std::stringstream ss;
    ss << "Rokas Rokauskas 3 9 8 7 8";

    Student s;
    ss >> s;

    EXPECT_EQ(s.getName(), "Rokas");
    EXPECT_EQ(s.getSurname(), "Rokauskas");
    EXPECT_EQ(s.getNd().size(), 3);
    EXPECT_EQ(s.getEgz(), 8);
}

TEST(StudentTest, Calculations) {
    Student s1("Test1", "Test", {}, 10);
    EXPECT_NEAR(s1.getFinalAvg(), 6.0, 0.0001);

    Student s2("Test2", "Test", {8}, 7);
    double avg = 0.4 * 8 + 0.6 * 7;
    EXPECT_NEAR(s2.getFinalAvg(), avg, 0.0001);
}

TEST(StudentTest, FileInput) {
    std::ofstream fout("data/test_in.txt");
    fout << "Jonas Jonaitis 3 8 9 7 8";
    fout.close();

    std::ifstream fin("data/test_in.txt");

    Student s;
    fin >> s;

    EXPECT_EQ(s.getName(), "Jonas");
    EXPECT_EQ(s.getSurname(), "Jonaitis");
}

TEST(StudentTest, FileOutput) {
    Student s("Petras", "Petraitis", {10, 9}, 8);

    std::ofstream fout("data/test_output.txt");
    ASSERT_TRUE(fout.is_open());

    fout << s;
    fout.close();

    std::ifstream fin("data/test_output.txt");
    ASSERT_TRUE(fin.is_open());

    std::string content;
    std::getline(fin, content);

    EXPECT_FALSE(content.empty());
}

TEST(StudentTest, Polymorphism) {
    Student s("Jonas", "Jonaitis", {8,9}, 10);
    Person* p = &s;

    EXPECT_NO_THROW(p->print());
}

TEST(numberTest, equality) {
    int a=5;
    EXPECT_EQ(a, 5);
}