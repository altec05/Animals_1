
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>
#include "string"


// Перечисляемый тип - тип животного
enum enumAnimal {
    FISH,
    BIRD,
    COMMON_ANIMAL
};

// Животные
struct animal {
    enumAnimal TYPE; // Тип животного
    std::string name; // Имя животного
    int age; // Возраст
};

int name_length(animal*an);
animal* readA(std::ifstream&ifs);
void outA(std::ofstream& ofs, animal*A);
bool comparator(animal*f, animal*s);

#endif //ANIMAL_H
