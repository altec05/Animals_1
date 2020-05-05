
#include "common_animals.h"

void ReadCM(std::ifstream &ifs, common_animal*cm) {
    int int_location;
    ifs >> int_location;
    cm->living_place = (type)int_location;
}

void OutCM(std::ofstream &ofs, common_animal *cm) {
    ofs << "Type: ";
    switch (cm->living_place) {
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

