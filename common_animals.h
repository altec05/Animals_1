
#ifndef COMMON_ANIMALS_H
#define COMMON_ANIMALS_H

#include <iostream>
#include <fstream>
#include "animal.h"

enum type {
    predator, herbivorous, insectivorous
};

struct commonAnimal {
    enumAnimal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
    type living_place;
};

bool readCM(std::ifstream& ifs, common_animal *f);
void outCM(std::ofstream& ofs, common_animal *f);

#endif //COMMON_ANIMALS_H
