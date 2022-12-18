#include "Criptografia.hpp"
#include <string>
#include <iostream>

int main() {

    Criptografia cifra;

    cifra.imprimirGrupos();

    std::string original_message;
    std::string encrypted_message;
    std::string palavra;
    unsigned int size{0};

    while(std::cin >> palavra) {

        std::string palavra_formatada;

        for (char c: palavra) {
            palavra_formatada += toupper(c);
        }

        size += palavra_formatada.length();

        original_message += (palavra_formatada + ' ');
        if ((size % 10) == 0)
            size--;
        encrypted_message += cifra.decrypt(palavra_formatada, size % 10);
        encrypted_message += ' ';
    }

    std::cout << original_message << std::endl;
    std::cout << encrypted_message << std::endl;
    return 0;
}