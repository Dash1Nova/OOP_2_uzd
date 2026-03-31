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
    Student() = delete;
    Student(const std::string& name, const std::string& surname, const std::vector<int>& nd, int egz);

        ~Student();

        const std::string& getName() const;
        const std::string& getSurname() const;
        const std::vector<int>& getNd() const;
        int getEgz() const;

        double getFinalAvg() const;
        double getFinalMed() const;

        void setNd(const std::vector<int>& nd);
        void setEgz(int egz);

        void addNd(int mark);
    };

#endif