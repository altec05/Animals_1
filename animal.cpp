
#include "animal.h"
#include "fish.h"
#include "bird.h"
#include "common_animals.h"

animal *readA(std::ifstream &ifs) {
    int type, _age;
    ifs >> type;
    if(type < 0 || type > 2) {
        return NULL;
    }
    if(ifs.fail()) return false;
    animal* Read = NULL;
    std::string _name;
    Read = NULL;
    switch (type) {
        case enumAnimal::FISH:
            Read = (animal*)new fish;
            break;
        case enumAnimal::BIRD:
            Read = (animal*)new bird;
            break;
        case enumAnimal::COMMON_ANIMAL:
            Read = (animal*)new common_animal;
            break;
    }
    // Считываем возраст
    if(!ifs.eof())
        ifs >> _age;
    else return nullptr;
    if(_age < 0) return nullptr;
    if(ifs.fail()) return false;
    // Считываем имя
    if(!ifs.eof())
        ifs >> _name;
    else return nullptr;
    if(ifs.fail()) return false;
    Read->name = _name;
    Read->age = _age;
    switch (type) {
        case enumAnimal::FISH:
            // Считываем рыбу
            if(!readF(ifs, (fish *) Read))
                return nullptr;
            Read->TYPE = enumAnimal::FISH;
            break;
        case enumAnimal::BIRD:
            // Считываем птицу
            if(!readB(ifs, (bird *) Read))
                return nullptr;
            Read->TYPE = enumAnimal::BIRD;
            break;
        case enumAnimal::COMMON_ANIMAL:
            // Считываем птицу
            if(!readCM(ifs, (common_animal *) Read))
                return nullptr;
            Read->TYPE = enumAnimal::COMMON_ANIMAL;
            break;
    }

    return Read;
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
            outCM(ofs, (common_animal *) A);
            break;
    }
}

int name_length(animal*an) {
    return an->name.length();
}

bool comparator(animal *f, animal *s) {
    return name_length(f) < name_length(s);
}
