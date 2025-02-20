#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password);
    std::string getName() const;
    std::string getRollNo() const;
    int getAge() const;
    std::string getGrade() const;
    std::string getPassword() const;

private:
    std::string name;
    std::string roll_no;
    int age;
    std::string grade;
    std::string password;
};

#endif // STUDENT_H