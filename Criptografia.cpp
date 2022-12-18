#include "Criptografia.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

Criptografia::Criptografia()
    : groupA{'O', '9', 'U', 'P', '0', 'V', 'Y', 'J', '4', '!'},
        groupB{'X', '?', '7', 'G', 'M', '2', 'E', 'S', 'Z', 'C'},
        groupC{'A', 'D', 'L', 'W', '8', 'B', '6', ',', '5', 'F'},
        groupD{'Q', 'R', '1', 'K', 'N', 'T', 'H', '.', 'I', '3'} 
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

std::string Criptografia::encrypt(const std::string& word, unsigned int rot) {

    std::string encrypted_word;

    for (char c: word) {
        
        std::vector<char>::iterator it;
        int index;

        if ((it = std::find(this->groupA.begin(), this->groupA.end(), c)) != this->groupA.end())
            encrypted_word += this->groupA[(std::distance(this->groupA.begin(), it) + rot) % this->groupA.size()];
        else if ((it = std::find(this->groupB.begin(), this->groupB.end(), c)) != this->groupB.end()) {
             if ((index = (std::distance(this->groupB.begin(), it) - rot)) < 0)
                encrypted_word += this->groupB[this->groupB.size() + index];
            else
                encrypted_word += this->groupB[index];
        }
        else if ((it = std::find(this->groupC.begin(), this->groupC.end(), c)) != this->groupC.end())
            encrypted_word += this->groupC[(std::distance(this->groupC.begin(), it) + rot) % this->groupC.size()];
        else if ((it = std::find(this->groupD.begin(), this->groupD.end(), c)) != this->groupD.end()) {
            if ((index = (std::distance(this->groupD.begin(), it) - rot)) < 0)
                encrypted_word += this->groupD[this->groupD.size() + index];
            else
                encrypted_word += this->groupD[index];
        }
        else
            encrypted_word += c;
            
    }

    return encrypted_word;

}                            

std::string Criptografia::decrypt(const std::string& word, unsigned int rot) {

    std::string decrypted_word;

    for (char c: word) {
        
        std::vector<char>::iterator it;
        int index;

        if ((it = std::find(this->groupA.begin(), this->groupA.end(), c)) != this->groupA.end()) {
            if ((index = (std::distance(this->groupA.begin(), it) - rot)) < 0)
                decrypted_word += this->groupA[this->groupA.size() + index];
            else
                decrypted_word += this->groupA[index];
        }
        else if ((it = std::find(this->groupB.begin(), this->groupB.end(), c)) != this->groupB.end())
            decrypted_word += this->groupB[(std::distance(this->groupB.begin(), it) + rot) % this->groupB.size()];
        else if ((it = std::find(this->groupC.begin(), this->groupC.end(), c)) != this->groupC.end()) {
            if ((index = (std::distance(this->groupC.begin(), it) - rot)) < 0)
                decrypted_word += this->groupC[this->groupC.size() + index];
            else
                decrypted_word += this->groupC[index];
        }   
        else if ((it = std::find(this->groupD.begin(), this->groupD.end(), c)) != this->groupD.end())
            decrypted_word += this->groupD[(std::distance(this->groupD.begin(), it) + rot) % this->groupD.size()];
        else
            decrypted_word += c;
    }

    return decrypted_word;

}                   