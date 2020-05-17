
#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <fstream>
#include "animal.h"

enum location {
    river, sea, ocean, lake, other
};

struct fish {
    enum_animal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
    location living_place; // Локация
};
bool ReadF(std::ifstream& ifs, fish *f);
void OutF(std::ofstream& ofs, fish *f);

#endif //FISH_H
