#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>
#include <iostream>

class Student : public Person {
private:
    std::vector<int> nd_;
    int egz_;

    double finalAvg_;
    double finalMed_;

    void calculate();

public:
    Student(const std::string name = "Julius", const std::string surname = "Petraitis", const std::vector<int> nd = {1, 2}, int egz = 5);

    ~Student();

    Student(const Student& other);
    Student& operator=(const Student& other);

    Student(Student&& other) noexcept;
    Student& operator=(Student&& other) noexcept;

    int getEgz() const;
    const std::vector<int>& getNd() const;

    double getFinalAvg() const;
    double getFinalMed() const;

    void setNd(const std::vector<int>& nd);
    void setEgz(int egz);
    void addNd(int mark);

    void print() const override;

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);
};

#endif