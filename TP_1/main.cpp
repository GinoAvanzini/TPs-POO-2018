

/* 
 * File:   main.cpp
 * Author: Gino Avanzini
 *
 * Created on August 12, 2018, 7:34 PM
 */

/*
 * ------------------------------------------------------------------------
 * IMPORTANTE:
 * ------------------------------------------------------------------------
 * 
 * Para no tener problemas con la compilacion se recomienda setear el estandar
 * del compilador de C++ a (C++11 o C++14). Esto es por la incorporación
 * de la librería <random> en el estándar C++11
 *
 */


#include "header.h"


int main(int argc, char** argv) {
    
    

    int n;
    std::cout << "Ingrese numero de ejercicio" << std::endl;
    std::cin >> n;
    switch(n) {
        case 1:
            ej_1();
            break;
        case 2:
            ej_2();
            break;
        case 3:
            ej_3();
            break;
        case 4:
            ej_4();
            break;
        default:
            break;
    }

    return 0;
}

