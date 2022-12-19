#include "Criptografia.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {

    Criptografia cifra;
    
    bool encode = true;
    int c;

    while ((c = getopt (argc, argv, "d")) != -1)
        switch (c) {
            case 'd':
                encode = false;
                break;
        }

    std::string original_message;
    std::string processed_message;
    std::string word;

    unsigned int size{0};

    if (encode) {
        while (std::cin >> word) {

            std::string formatted_word;

            for (char c: word) {
                formatted_word += toupper(c);
            }

            size += formatted_word.length();

            original_message += (formatted_word + ' ');
            if ((size % 10) == 0)
                size--;
            processed_message += cifra.encrypt(formatted_word, size % 10);
            processed_message += ' ';
        }
    }
    else {
        while (std::cin >> word) {

        std::string formatted_word;

        for (char c: word) {
            formatted_word += toupper(c);
        }

        size += formatted_word.length();

        original_message += (formatted_word + ' ');
        if ((size % 10) == 0)
            size--;
        processed_message += cifra.decrypt(formatted_word, size % 10);
        processed_message += ' ';
        }
    }
    std::cout << original_message << std::endl;
    std::cout << processed_message << std::endl;
    return 0;
}