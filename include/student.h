#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name_;
    std::string surname_;
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

        const std::string& getName() const;
        const std::string& getSurname() const;
        const std::vector<int>& getNd() const;
        int getEgz() const;

        double getFinalAvg() const;
        double getFinalMed() const;

        void setNd(const std::vector<int>& nd);
        void setEgz(int egz);
        void addNd(int mark);

        friend std::ostream& operator<<(std::ostream& os, const Student& s);
        friend std::istream& operator>>(std::istream& is, Student& s);
    };

#endif