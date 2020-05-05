
#ifndef COMMON_ANIMALS_H
#define COMMON_ANIMALS_H

#include <iostream>
#include <fstream>
#include "animal.h"

enum type {
    predator, herbivorous, insectivorous
};

struct common_animal {
    animal *next; // Последующий элемент
    animal *prev; // Предыдущий  элемент
    enum_animal TYPE; // Тип животного
    std::string name; // Имя животного
    type living_place;
};

void ReadCM(std::ifstream& ifs, common_animal *f);
void OutCM(std::ofstream& ofs, common_animal *f);

#endif //COMMON_ANIMALS_H
