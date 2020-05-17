
#include "bird.h"

bool readB(std::ifstream &ifs, bird*b) {
    std::string _s;
    if(!ifs.is_open()) return false;
    ifs >> _s;
    if(_s == "true") b->is_migratory = 1;
    else b->is_migratory = 0;
    char ch;
    ifs.get(ch);
    return true;
}

void outB(std::ofstream &ofs, bird *b) {
    ofs << "Is migratory: " << (b->is_migratory ? "true" : "false") << std::endl;
}