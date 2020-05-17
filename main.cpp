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
    Init(Zoo);
    // Считывание
    Read(ifst, Zoo);
    // Вывод + вывод сортированного
    Out(ofst, Zoo);
    Sort(Zoo);
    ofst << "Sorted\n";
    Out(ofst, Zoo);
    Specific_Out(ofst, Zoo, enum_animal::FISH);
    Specific_Out(ofst, Zoo, enum_animal::BIRD);
    // Очистка контейнера
    Clear(Zoo);
    return 0;
}