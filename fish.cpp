
#include "fish.h"

bool ReadF(std::ifstream &ifs, fish*f) {
    int int_location;
    if(!ifs.is_open()) return false;
    ifs >> int_location;
    if(ifs.fail()) return false;
    f->living_place = (location)int_location;
    return true;
}

void OutF(std::ofstream &ofs, fish *f) {
    ofs << "Location: ";
    switch (f->living_place) {
        case location::lake:
            ofs << "Lake\n";
            return;
        case location::ocean:
            ofs << "Ocean\n";
            return;
        case location::river:
            ofs << "River\n";
            return;
        case location::sea:
            ofs << "Sea\n";
            return;
        default:
            ofs << "Other\n";
            return;
    }
}

