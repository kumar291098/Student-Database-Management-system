#ifndef DATABASE_H
#define DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <string>
#include <thread>

class Database {
public:
    Database();
    ~Database();
    void connect();
    void addStudent(const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password);
    void viewStudents();
    void updateStudent(int id, const std::string& name, const std::string& roll_no, int age, const std::string& grade, const std::string& password);
    void deleteStudent(int id);

private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    std::thread::id threadId;
};

#endif // DATABASE_H