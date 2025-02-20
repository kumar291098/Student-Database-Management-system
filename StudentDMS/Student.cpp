#include "Student.h"

Student::Student(const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password)
    : name(name), roll_no(roll_no), age(age), grade(grade), password(password) {
}

std::string Student::getName() const {
    return name;
}

std::string Student::getRollNo() const {
    return roll_no;
}

int Student::getAge() const {
    return age;
}

std::string Student::getGrade() const {
    return grade;
}

std::string Student::getPassword() const {
    return password;
}