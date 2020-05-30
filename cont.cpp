
#include "cont.h"

void Read(std::ifstream &ifs, cont &q) {
    while(!ifs.eof()) { // Пока есть что считывать
        animal *A = ReadA(ifs); // Функция возвращает считанные данные
        if(A==NULL) return;
        Add(A, q); // Сохраняем в контейнер
    }
}

void Add(animal *A, cont&q) {
    q.size++;
    if(q.first == nullptr) { // Если контейнер пуст
        q.first = A;
        A->prev = A->next = A;
    } else {
        // Связываем A с предыдущим
        (q.first->prev)->next = A;
        A->prev = (q.first->prev);
        // Связываем A с последующим
        q.first->prev = A;
        A->next = q.first;
    }
}

void Init(cont &cont) {
    cont.first = NULL;
    cont.size = 0;
}

void Clear(cont &q) {
    animal *A = q.first;
    for(int i = 0; i < q.size; i++) {
        animal *deleting = A;
        A = A->next;
        delete deleting;
    }
    q.size = 0;
}

void Out(std::ofstream &ofs, cont &q) {
    animal *A = q.first;
    for(int i = 1; i <= q.size; i++) {
        ofs << i << ". ";
        OutA(ofs, A);
        A = A->next;
    }
}


void Multi(cont &c, std::ofstream &ofstr) {
    ofstr << "_multimethod_" << std::endl;
    node *A = c.first;
    for (int i = 0; i < c.size - 1; i++) {
        node *B = c.first->next;
        for (int j = 0; j < c.size - 1 - i; j++) {
            switch (A->data->TYPE) {
                case FISH:
                    switch (B->data->TYPE) {
                        case FISH:
                            ofstr << "Fish and fish" << std::endl;
                            break;
                        case BIRD:
                            ofstr << "Fish and bird" << std::endl;
                            break;
                    }
                    break;
                case BIRD:
                    switch (B->data->TYPE) {
                        case FISH:
                            ofstr << "Bird and fish" << std::endl;
                            break;
                        case BIRD:
                            ofstr << "Bird and bird" << std::endl;
                            break;
                    }
                    break;
            }
            outA(ofstr, A->data);
            outA(ofstr, B->data);
            ofstr << std::endl;
        }
    }
}