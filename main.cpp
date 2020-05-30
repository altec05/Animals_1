#include "cont.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 3) { // Проверка на корректность аргументов программы
        cout << "incorrect command line! " << endl;
        return 1;
    }
    ifstream ifst(argv[1]);
    // Контейнер с животными
    cont Zoo;
    Init(Zoo);
    // Считывание
    Read(ifst, Zoo);
    ofstream ofst(argv[2]);
    // Вывод
    Out(ofst, Zoo);
    Multi(Zoo, ofst);
    // Очистка контейнера
    Clear(Zoo);
    return 0;
}