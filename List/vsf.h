#ifndef VSF_H
#define VSF_H

#include "stdlib.h"
#include "string"
#include "iostream"

using namespace std;

using namespace std;

struct VSF {
    int id;
};

void ImprimirElementoEncadeada(VSF dado) {
    std::cout << "Dado: " << dado.id << std::endl;
}

void ImprimirElementoDupla(VSF dado) {
    std::cout << "Dado: " << dado.id << std::endl;
}

void ImprimirElementoEstatica(VSF dado) {
    std::cout << "Dado: " << dado.id << std::endl;
}

#endif // VSF_H
