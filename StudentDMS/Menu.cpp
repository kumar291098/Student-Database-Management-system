#include "Menu.h"
#include "Database.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <thread>

void runMenu() {
    Database db;
    db.connect();

    int choice;
    do {
        std::cout << "Student Database Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. View Students\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Delete Student\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name, roll_no, password;
            int age;
            std::string grade;

            std::cout << "Enter name: ";
            std::getline(std::cin, name);

            std::cout << "Enter roll number: ";
            std::getline(std::cin, roll_no);

            std::cout << "Enter age: ";
            std::cin >> age;
            std::cin.ignore();

            std::cout << "Enter grade: ";
            std::getline(std::cin, grade);

            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            std::string encryptedPassword = encryptPassword(password);
            std::thread addStudentThread(&Database::addStudent, &db, name, roll_no, age, grade, encryptedPassword);
            addStudentThread.join();
            break;
        }
        case 2: {
            std::thread viewStudentsThread(&Database::viewStudents, &db);
            viewStudentsThread.join();
            break;
        }
        case 3: {
            int id;
            std::string name, roll_no, password;
            int age;
            std::string grade;

            std::cout << "Enter student ID to update: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Enter new name: ";
            std::getline(std::cin, name);

            std::cout << "Enter new roll number: ";
            std::getline(std::cin, roll_no);

            std::cout << "Enter new age: ";
            std::cin >> age;
            std::cin.ignore();

            std::cout << "Enter new grade: ";
            std::getline(std::cin, grade);

            std::cout << "Enter new password: ";
            std::getline(std::cin, password);

            std::string encryptedPassword = encryptPassword(password);
            std::thread updateStudentThread(&Database::updateStudent, &db, id, name, roll_no, age, grade, encryptedPassword);
            updateStudentThread.join();
            break;
        }
        case 4: {
            int id;
            std::cout << "Enter student ID to delete: ";
            std::cin >> id;
            std::thread deleteStudentThread(&Database::deleteStudent, &db, id);
            deleteStudentThread.join();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}