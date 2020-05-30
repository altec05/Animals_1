
#ifndef CONT_H
#define CONT_H

#include <iostream>
#include <fstream>
#include "animal.h"

struct node {
    animal* data;
    node* next;
    node* prev;
};

struct cont {
    node* first; // Указатель на первый элемент
    int size; // Размер контейнера
};

void clear(cont&q);
void init(cont&q);
void add(node*A, cont&q);
void read(std::ifstream& ifs, cont&q);
void out(std::ofstream& ofs, cont&q);
void sort(cont&q);
void specificOut(std::ofstream& ofs, cont&q, enumAnimal type);
void multi(cont &c, std::ofstream &ofstr);

#endif //CONT_H
