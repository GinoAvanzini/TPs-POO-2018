
/*
 * Copyright (C) 2018 Gino Avanzini
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   main.cpp
 * Author: Gino Avanzini
 *
 * Created on September 29, 2018, 6:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include "EfectorFinal.h"

//using namespace std;

int main(int argc, char** argv) {
    
    //while(1){
    
    std::cout << "Desea Iniciar?\n" << "[y/n]: ";
    char inicio;
    std::cin >> inicio;
    if (inicio == 'n' || inicio == 'N'){
        std::cout << "Programa finalizado";
        return 0;
    }
    
    std::cout << "A continuacion se creará la lista con las operaciones"
            << " a realizar\n" << std::endl;
    std::cout << "Ingrese la cantidad de ciclos que debe realizar "
            << "el efector y luego la actividad respectiva" << std::endl;

    std::cout << "0:PARADA\n" << "1:PINTAR\n" << "2:SOSTENER\n"
            << "3:SOLTAR\n" << "4:ROTAR\n" << "5:CAMBIAR VELOCIDAD\n"
            << std::endl;
    
    int entrada;
    int cantidad;
    std::queue<int> operaciones;
    std::queue<int> ciclos;

    do{
        
        std::cin >> cantidad;
        std::cin >> entrada;
        
        ciclos.push(cantidad);
        operaciones.push(entrada);
        
        if (entrada == 5){
            std::cout << "Ingrese nueva velocidad\n";
            int vel;
            std::cin >> vel;
            operaciones.push(vel);
        }
        
        /*
        switch(entrada){
            case(0):
                operaciones.push("PARADA");
                break;
            case(1):
                operaciones.push("PINTAR");
                break;
            case(2):
                operaciones.push("SOSTENER");
                break;
            case(3):
                operaciones.push("SOLTAR");
                break;
            case(4):
                operaciones.push("ROTAR");
                break;
            case(5):
                operaciones.push("CAMBIARV");
                std::cout << "Ingrese nueva velocidad";
                std::string vel;
                std::cin >> vel;
                operaciones.push(vel);
                break;
                
        }
        */

    } while (entrada != 0);
        
    EfectorFinal * efector;
    
    efector = new EfectorFinal();
    
    efector->Iniciar(operaciones, ciclos);
    
    std::cout << "Ejecución finalizada\n";
    
    //}
    
    return 0;
}

