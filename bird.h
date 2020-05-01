
#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <fstream>
#include "animal.h"

struct bird {
    animal *next; // Последующий элемент
    animal *prev; // Предыдущий  элемент
    enum_animal TYPE; // Тип животного
    std::string name; // Имя животного
    bool is_migratory; // Перелетная ли птица
};

void ReadB(std::ifstream& ifs, bird *b);
void OutB(std::ofstream& ofs, bird *b);

#endif //BIRD_H
