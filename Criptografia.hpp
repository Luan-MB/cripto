#ifndef CRIPTOGRAFIA_HPP
#define CRIPTOGRAFIA_HPP

#include <vector>
#include <string>

class Criptografia {
    public:
        Criptografia();

        void imprimirGrupos();

        std::string encrypt(const std::string&);
        std::string decrypt(const std::string&);

    private:
        std::vector<char> groupA;
        std::vector<char> groupB;
        std::vector<char> groupC;
        std::vector<char> groupD;
        unsigned int groupSize;
};

#endif
