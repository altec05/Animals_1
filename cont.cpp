
#include "cont.h"

void read(std::ifstream &ifs, cont &q) {
    while(!ifs.eof()) { // Пока есть что считывать
        animal *A = readA(ifs); // Функция возвращает считанные данные
        if(A==NULL) {
            clear(q);
            std::cout << "Error reading file structure.\n";
            return;
        }
        node *N = new node;
        N->data = A;
        add(N, q); // Сохраняем в контейнер
    }
}

void add(node *A, cont&q) {
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

void init(cont &q) {
    q.first = NULL;
    q.size = 0;
}

void clear(cont &q) {
    node *A = q.first;
    for(int i = 0; i < q.size; i++) {
        node *deleting = A;
        A = A->next;
        delete deleting->data;
        delete deleting;
    }
    q.size = 0;
}

void out(std::ofstream &ofs, cont &q) {
    node *A = q.first;
    for(int i = 1; i <= q.size; i++) {
        ofs << i << ". ";
        outA(ofs, A->data);
        A = A->next;
    }
}

void sort(cont &q) {
    node *A = q.first;
    std::cout << "Sorting in progress..." << std::endl;
    for (int i = 0; i < q.size - 1; i++) {
        node *B = A->next;
        for (int j = 0; j < q.size - 1 - i; j++) {
            std::cout << A->data->name << " vs " << B->data->name << std::endl;
            if (comparator(A->data, B->data)) {
                // Меняем местами элементы при необходимости
                animal *data = A->data;
                A->data = B->data;
                B->data = data;
            }
            B = B->next;
        }
        A = A->next;
    }
    std::cout << "Done!" << std::endl;
}

void specificOut(std::ofstream &ofs, cont &q, enumAnimal type) {
    node *A = q.first;
    int index = 1;
    ofs << "Ignoring type: " << type << std::endl;
    for(int i = 0; i < q.size; i++) {
        if(A->data->TYPE == type) {
            A = A->next;
            continue;
        }
        ofs << index << ". ";
        outA(ofs, A->data);
        A = A->next;
        index++;
    }
}

void multi(cont &c, std::ofstream &ofstr) {
    ofstr << "_multimethod_" << std::endl;
    node *A = c.first;
    for (int i = 0; i < c.size - 1; i++) {
        node *B = c.first->next;
        for (int j = 0; j < c.size - 1 - i; j++) {
            switch(A->data->TYPE) {
                case FISH:
                    switch(B->data->TYPE) {
                        case FISH:
                            ofstr << "Fish and fish" << std::endl;
                            break;
                        case BIRD:
                            ofstr << "Fish and bird" << std::endl;
                            break;
                        case COMMON_ANIMAL:
                            ofstr << "Fish and common_animal" << std::endl;
                            break;
                    }
                    break;
                case BIRD:
                    switch(B->data->TYPE) {
                        case FISH:
                            ofstr << "Bird and fish" << std::endl;
                            break;
                        case BIRD:
                            ofstr << "Bird and bird" << std::endl;
                            break;
                        case COMMON_ANIMAL:
                            ofstr << "Bird and common_animal" << std::endl;
                            break;
                    }
                    break;
                case COMMON_ANIMAL:
                    switch(B->data->TYPE) {
                        case FISH:
                            ofstr << "Common_animal and fish" << std::endl;
                            break;
                        case BIRD:
                            ofstr << "Common_animal and bird" << std::endl;
                            break;
                        case COMMON_ANIMAL:
                            ofstr << "Common_animal and common_animal" << std::endl;
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
