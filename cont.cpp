
#include "cont.h"

void Read(std::ifstream &ifs, cont &q) {
    while(!ifs.eof()) { // Пока есть что считывать
        animal *A = ReadA(ifs); // Функция возвращает считанные данные
        if(A==NULL) {
            Clear(q);
            std::cout << "Error reading file structure.\n";
            return;
        }
        node *N = new node;
        N->data = A;
        Add(N, q); // Сохраняем в контейнер
    }
}

void Add(node *A, cont&q) {
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
    node *A = q.first;
    for(int i = 0; i < q.size; i++) {
        node *deleting = A;
        A = A->next;
        delete deleting->data;
        delete deleting;
    }
    q.size = 0;
}

void Out(std::ofstream &ofs, cont &q) {
    node *A = q.first;
    for(int i = 1; i <= q.size; i++) {
        ofs << i << ". ";
        OutA(ofs, A->data);
        A = A->next;
    }
}

void Sort(cont &q) {
    node *A = q.first;
    std::cout << "Sorting in progress..." << std::endl;
    for(int i = 0; i < q.size-1; i++) {
        node *B = A->next;
        for(int j = 0; j < q.size-1-i; j++) {
            std::cout << A->data->name << " vs "<< B->data->name << std::endl;
            if(Comparator(A->data, B->data)) {
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
