
#include "animal.h"
#include "fish.h"
#include "bird.h"
#include "common_animals.h"

animal *readA(std::ifstream &ifs) {
    int type, age;
    ifs >> type;
    if(type < 0 || type > 2) {
        return NULL;
    }
    if(ifs.fail()) return false;
    animal* read = NULL;
    std::string name;
    Read = NULL;
    switch (type) {
        case enumAnimal::FISH:
            read = (animal*)new fish;
            break;
        case enumAnimal::BIRD:
            read = (animal*)new bird;
            break;
        case enumAnimal::COMMON_ANIMAL:
            read = (animal*)new commonAnimal;
            break;
    }
    // Считываем возраст
    if(!ifs.eof())
        ifs >> age;
    else return nullptr;
    if(_age < 0) return nullptr;
    if(ifs.fail()) return false;
    // Считываем имя
    if(!ifs.eof())
        ifs >> _name;
    else return nullptr;
    if(ifs.fail()) return false;
    read->name = name;
    read->age = age;
    switch (type) {
        case enumAnimal::FISH:
            // Считываем рыбу
            if(!readF(ifs, (fish *) read))
                return nullptr;
            read->TYPE = enumAnimal::FISH;
            break;
        case enumAnimal::BIRD:
            // Считываем птицу
            if(!readB(ifs, (bird *) read))
                return nullptr;
            read->TYPE = enumAnimal::BIRD;
            break;
        case enumAnimal::COMMON_ANIMAL:
            // Считываем птицу
            if(!readCM(ifs, (commonAnimal *) read))
                return nullptr;
            read->TYPE = enumAnimal::COMMON_ANIMAL;
            break;
    }

    return read;
}

void outA(std::ofstream &ofs, animal *A) {
    ofs << "NAME: " << A->name << std::endl;
    ofs << "NAME LENGTH: " << name_length(A) << std::endl;
    ofs << "AGE: " << A->age << std::endl;
    ofs << "ANIMAL: ";
    switch (A->TYPE) {
        case enumAnimal::FISH:
            ofs << "FISH\n";
            outF(ofs, (fish *) A);
            break;
        case enumAnimal::BIRD:
            ofs << "BIRD\n";
            outB(ofs, (bird *) A);
            break;
        case enumAnimal::COMMON_ANIMAL:
            ofs << "COMMON ANIMAL\n";
            outCM(ofs, (commonAnimal *) A);
            break;
    }
}

int name_length(animal*an) {
    return an->name.length();
}

bool comparator(animal *f, animal *s) {
    return name_length(f) < name_length(s);
}
