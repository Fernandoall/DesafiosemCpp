#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Data {
public:
    int dia;
    int mes;
    int ano;

    Data() {} // Construtor padrão

    Data(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }
};

