
#include "animal.h"
#include "fish.h"
#include "bird.h"


animal *ReadA(std::ifstream &ifs) {
    int type, _age;
    ifs >> type;
    if(type < 0 || type > 1) {
        return NULL;
    }
    animal* Read = NULL;
    std::string _name;
    Read = NULL;
    switch (type) {
        case enum_animal::FISH:
            Read = (animal*)new fish;
            break;
        case enum_animal::BIRD:
            Read = (animal*)new bird;
            break;
    }
    // Считываем возраст
    if(!ifs.eof())
        ifs >> _age;
    // Считываем имя
    if(!ifs.eof())
        ifs >> _name;
    else return NULL;
    Read->name = _name;
    Read->age = _age;
    switch (type) {
        case enum_animal::FISH:
            // Считываем рыбу
            ReadF(ifs, (fish*)Read);
            Read->TYPE = enum_animal::FISH;
            break;
        case enum_animal::BIRD:
            // Считываем птицу
            ReadB(ifs, (bird*)Read);
            Read->TYPE = enum_animal::BIRD;
            break;
    }

    return Read;
}

void OutA(std::ofstream &ofs, animal *A) {
    ofs << "NAME: " << A->name << std::endl;
    ofs << "AGE: " << A->age << std::endl;
    ofs << "ANIMAL: ";
    switch (A->TYPE) {
        case enum_animal::FISH:
            ofs << "FISH\n";
            OutF(ofs, (fish*)A);
            break;
        case enum_animal::BIRD:
            ofs << "BIRD\n";
            OutB(ofs, (bird*)A);
            break;
    }
}
