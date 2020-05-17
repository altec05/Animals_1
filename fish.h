
#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <fstream>
#include "animal.h"

enum location {
    river, sea, ocean, lake, other
};

struct fish {
    enumAnimal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
    location living_place; // Локация
};
bool readF(std::ifstream& ifs, fish *f);
void outF(std::ofstream& ofs, fish *f);

#endif //FISH_H
