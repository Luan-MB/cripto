#include "Criptografia.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

Criptografia::Criptografia()
    : groupA{'O', '9', 'U', 'P', '0', 'V', '$', 'Y', 'J', '4', '!'},
        groupB{'X', '?', '7', 'G', 'M', '2', 'E', ':', 'S', 'Z', 'C'},
        groupC{'A', 'D', '@', 'L', 'W', '8', 'B', '6', ',', '5', 'F'},
        groupD{'Q', 'R', '1', 'K', 'N', '\'', 'T', 'H', '.', 'I', '3'},
        groupSize{11}
{}

void Criptografia::imprimirGrupos() {
    std::cout << "groupA: ";
    for (char c: this->groupA)
        std::cout << c << ' ';
    std::cout << std::endl;
    std::cout << "groupB: ";
    for (char c: this->groupB)
        std::cout << c << ' ';
    std::cout << std::endl;
    std::cout << "groupC: ";
    for (char c: this->groupC)
        std::cout << c << ' ';
    std::cout << std::endl;
    std::cout << "groupD: ";
    for (char c: this->groupD)
        std::cout << c << ' ';
    std::cout << std::endl;
}

std::string Criptografia::encrypt(const std::string& message) {

    std::string encrypted_message;
    unsigned int char_idx{0}, rot;
    bool next_char{true};

    for (char c: message) {
        
        std::vector<char>::iterator it;
        int index;
        
        rot = char_idx % this->groupSize;
        if (rot == 0) {
            if (next_char) {
                rot = 1;
                next_char = !next_char;
            } else {
                rot = this->groupSize - 1;
                next_char = !next_char;
            }
        }

        if ((it = std::find(this->groupA.begin(), this->groupA.end(), c)) != this->groupA.end())
            encrypted_message += this->groupA[(std::distance(this->groupA.begin(), it) + rot) % this->groupSize];
        else if ((it = std::find(this->groupB.begin(), this->groupB.end(), c)) != this->groupB.end()) {
             if ((index = (std::distance(this->groupB.begin(), it) - rot)) < 0)
                encrypted_message += this->groupB[this->groupSize + index];
            else
                encrypted_message += this->groupB[index];
        }
        else if ((it = std::find(this->groupC.begin(), this->groupC.end(), c)) != this->groupC.end())
            encrypted_message += this->groupC[(std::distance(this->groupC.begin(), it) + rot) % this->groupSize];
        else if ((it = std::find(this->groupD.begin(), this->groupD.end(), c)) != this->groupD.end()) {
            if ((index = (std::distance(this->groupD.begin(), it) - rot)) < 0)
                encrypted_message += this->groupD[this->groupSize + index];
            else
                encrypted_message += this->groupD[index];
        }
        else
            encrypted_message += c;

        char_idx++;
    }

    return encrypted_message;

}                            

std::string Criptografia::decrypt(const std::string& message) {

    std::string decrypted_message;
    unsigned int char_idx{0}, rot;
    bool next_char{true};

    for (char c: message) {
        
       std::vector<char>::iterator it;
        int index;
        
        rot = char_idx % this->groupSize;
        if (rot == 0) {
            if (next_char) {
                rot = 1;
                next_char = !next_char;
            } else {
                rot = this->groupSize - 1;
                next_char = !next_char;
            }
        }

        if ((it = std::find(this->groupA.begin(), this->groupA.end(), c)) != this->groupA.end()) {
            if ((index = (std::distance(this->groupA.begin(), it) - rot)) < 0)
                decrypted_message += this->groupA[this->groupSize + index];
            else
                decrypted_message += this->groupA[index];
        }
        else if ((it = std::find(this->groupB.begin(), this->groupB.end(), c)) != this->groupB.end())
            decrypted_message += this->groupB[(std::distance(this->groupB.begin(), it) + rot) % this->groupSize];
        else if ((it = std::find(this->groupC.begin(), this->groupC.end(), c)) != this->groupC.end()) {
            if ((index = (std::distance(this->groupC.begin(), it) - rot)) < 0)
                decrypted_message += this->groupC[this->groupSize + index];
            else
                decrypted_message += this->groupC[index];
        }   
        else if ((it = std::find(this->groupD.begin(), this->groupD.end(), c)) != this->groupD.end())
            decrypted_message += this->groupD[(std::distance(this->groupD.begin(), it) + rot) % this->groupSize];
        else
            decrypted_message += c;

        char_idx++;
    }

    return decrypted_message;

}                   