#include "Database.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <thread>

Database::Database() : driver(nullptr), con(nullptr) {}

Database::~Database() {
    if (con) {
        delete con;
    }
}

void Database::connect() {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "Avnish@123");
        con->setSchema("student_db");
        std::cout << "Connected to the database successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        exit(1);
    }
}

void Database::addStudent(const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password) {
    try {
        sql::PreparedStatement* pstmt;
        std::string insertDataSQL = "INSERT INTO students (name, roll_no, age, grade, password) VALUES (?, ?, ?, ?, ?)";
        pstmt = con->prepareStatement(insertDataSQL);

        pstmt->setString(1, name);
        pstmt->setString(2, roll_no);
        pstmt->setInt(3, age);
        pstmt->setString(4, grade);
        pstmt->setString(5, password);

        pstmt->execute();
        delete pstmt;

        std::cout << "Student added successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void Database::viewStudents() {
    try {
        sql::Statement* stmt;
        stmt = con->createStatement();

        std::string selectDataSQL = "SELECT * FROM students";
        sql::ResultSet* res = stmt->executeQuery(selectDataSQL);

        while (res->next()) {
            std::cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name")
                << ", Roll No: " << res->getString("roll_no") << ", Age: " << res->getInt("age")
                << ", Grade: " << res->getString("grade") << ", Password: " << res->getString("password") << std::endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void Database::updateStudent(int id, const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password) {
    try {
        sql::PreparedStatement* pstmt;
        std::string updateDataSQL = "UPDATE students SET name=?, roll_no=?, age=?, grade=?, password=? WHERE id=?";
        pstmt = con->prepareStatement(updateDataSQL);

        pstmt->setString(1, name);
        pstmt->setString(2, roll_no);
        pstmt->setInt(3, age);
        pstmt->setString(4, grade);
        pstmt->setString(5, password);
        pstmt->setInt(6, id);

        pstmt->execute();
        delete pstmt;

        std::cout << "Student updated successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void Database::deleteStudent(int id) {
    try {
        sql::PreparedStatement* pstmt;
        std::string deleteDataSQL = "DELETE FROM students WHERE id=?";
        pstmt = con->prepareStatement(deleteDataSQL);

        pstmt->setInt(1, id);

        pstmt->execute();
        delete pstmt;

        std::cout << "Student deleted successfully.\n";
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}