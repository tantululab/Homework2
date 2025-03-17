#include <iostream>
#include <vector>
#include <numeric>

class Student {
private:
    std::string name;
    std::string surname;
    int albumNumber;
    std::vector<double> grades;

    bool isValidAlbumNumber(int number) {
        return number >= 10000 && number <= 999999;
    }

    bool isValidGrade(double grade) {
        return grade >= 2.0 && grade <= 5.0;
    }

public:
    void setName(std::string n, std::string s) {
        name = n;
        surname = s;
    }

    void setAlbumNumber(int number) {
        if (isValidAlbumNumber(number)) {
            albumNumber = number;
        } else {
            std::cerr << "Invalid album number! It must have 5 to 6 digits.\n";
        }
    }

    void addGrade(double grade) {
        if (isValidGrade(grade)) {
            grades.push_back(grade);
        } else {
            std::cerr << "Invalid grade! Must be between 2.0 and 5.0.\n";
        }
    }

    double calculateMeanGrade() {
        if (grades.empty()) return 0.0;
        return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    }

    bool hasPassed() {
        int count2 = 0;
        for (double grade : grades) {
            if (grade == 2.0) {
                count2++;
                if (count2 > 1) return false;
            }
        }
        return true;
    }

    void displaySummary() {
        std::cout << "Student: " << name << " " << surname << " (Album: " << albumNumber << ")\n";
        std::cout << "Grades: ";
        for (double g : grades) std::cout << g << " ";
        std::cout << "\nMean Grade: " << calculateMeanGrade() << "\n";
        std::cout << "Status: " << (hasPassed() ? "Passed" : "Failed") << "\n";
    }
};

class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i = 0.0) : real(r), imag(i) {}

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    double getReal() { return real; }
    double getImag() { return imag; }

    Complex add(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex add(double realNumber) {
        return Complex(real + realNumber, imag);
    }

    void print() {
        std::cout << real;
        if (imag >= 0) std::cout << "+";
        std::cout << imag << "i\n";
    }
};
