
#include "common_animals.h"

bool readCM(std::ifstream &ifs, common_animal*f) {
    int int_location;
    if(!ifs.is_open()) return false;
    ifs >> int_location;
    if(ifs.fail()) return false;
    f->living_place = (type)int_location;
    return true;
}

void outCM(std::ofstream &ofs, common_animal *f) {
    ofs << "Type: ";
    switch (f->living_place) {
        case type::predator:
            ofs << "Predator\n";
            return;
        case type::herbivorous:
            ofs << "Herbivorous\n";
            return;
        case type::insectivorous:
            ofs << "Insectivorous\n";
            return;
        default:
            ofs << "Other\n";
            return;
    }
}

