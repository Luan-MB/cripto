#ifndef CRIPTOGRAFIA_HPP
#define CRIPTOGRAFIA_HPP

#include <vector>
#include <string>

class Criptografia {
    public:
        Criptografia();

        void imprimirGrupos();

        std::string encrypt(const std::string&, unsigned int);
        std::string decrypt(const std::string&, unsigned int);

    private:
        std::vector<char> groupA;
        std::vector<char> groupB;
        std::vector<char> groupC;
        std::vector<char> groupD;
};

#endif
