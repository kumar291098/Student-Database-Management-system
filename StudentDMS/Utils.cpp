#include "Utils.h"
#include <cctype>
#include <algorithm>

std::string encryptPassword(const std::string& password) {
    std::string encrypted;
    int shift = 3; // You can choose any shift value

    for (char c : password) {
        if (isalpha(c)) {
            char offset = islower(c) ? 'a' : 'A';
            encrypted += (c - offset + shift) % 26 + offset;
        }
        else {
            encrypted += c;
        }
    }

    return encrypted;
}