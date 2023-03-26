#include "Criptografia.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

int main(int argc, char **argv) {

    Criptografia cifra;
    
    bool encode = true;
    int c;

    while ((c = getopt (argc, argv, "dD")) != -1)
        switch (c) {
            case 'd':
                encode = false;
                break;
            case 'D':
                encode = false;
                break;
        }

    std::string processed_message;
    std::string word;

    unsigned int size{0};

    while (std::cin >> word) {

            std::string formatted_word;

            for (char c: word) {
                formatted_word += toupper(c);
            }

            processed_message += formatted_word;
    }

    std::cout << processed_message << std::endl;
    if (encode)
        std::cout << cifra.encrypt(processed_message) << std::endl;
    else
        std::cout << cifra.decrypt(processed_message) << std::endl;
    return 0;
}