
#ifndef COMMON_ANIMALS_H
#define COMMON_ANIMALS_H

#include <iostream>
#include <fstream>
#include "animal.h"

enum type {
    predator, herbivorous, insectivorous
};

struct common_animal {
    enum_animal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
    type living_place;
};

bool ReadCM(std::ifstream& ifs, common_animal *f);
void OutCM(std::ofstream& ofs, common_animal *f);

#endif //COMMON_ANIMALS_H
