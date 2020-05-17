#include "cont.h"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 3) { // Проверка на корректность аргументов программы
        cout << "incorrect command line! " << endl;
        return 1;
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    // Проверка на отсутствие файла
    if(!ifst.is_open() || !ofst.is_open()) {
        cout << "File can't be opened." << endl;
    }
    // Контейнер с животными
    cont Zoo;
    init(Zoo);
    // Считывание
    read(ifst, Zoo);
    // Вывод + вывод сортированного
    out(ofst, Zoo);
    sort(Zoo);
    ofst << "Sorted\n";
    out(ofst, Zoo);
    specificOut(ofst, Zoo, enumAnimal::FISH);
    specificOut(ofst, Zoo, enumAnimal::BIRD);
    // Очистка контейнера
    clear(Zoo);
    return 0;
}