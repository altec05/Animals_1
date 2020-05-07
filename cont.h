
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

void Clear(cont&q);
void Init(cont&q);
void Add(node*A, cont&q);
void Read(std::ifstream& ifs, cont&q);
void Out(std::ofstream& ofs, cont&q);
void Sort(cont&q);

#endif //CONT_H
