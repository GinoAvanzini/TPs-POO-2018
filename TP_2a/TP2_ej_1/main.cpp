
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
 * Created on September 24, 2018, 3:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include "Clase_del_Objeto.h"

using namespace std;

int main(int argc, char** argv) {
    
    Clase_del_Objeto *objeto;
    
    objeto = new Clase_del_Objeto();
    
    auto start = chrono::high_resolution_clock::now();
    
    int seleccion;
    
    cout << "Ingrese que operacion desea realizar:\n" <<
            "\t0 para TERMINAR la ejecución" << endl <<
            "\t1 para AVANZAR" << endl <<
            "\t2 para GIRO DERECHA" << endl <<
            "\t3 para GIRO ATRÁS" << endl <<
            "\t4 para GIRO IZQUIERDA" << endl <<
            "\t5 para MOVER ARRIBA" << endl <<
            "\t6 para MOVER ABAJO" << endl;
            
    int cont = 0;
    
    do{
       
        cont++;
        cin >> seleccion;
       
        switch (seleccion){
            
            case NINGUNA:
                break;

            case AVANZAR:
                objeto->avanzar();
                break;

            case GIRO_DERECHA:

                objeto->doblar(GIRO_DERECHA);
                break;

            case GIRO_ATRAS:
                objeto->doblar(GIRO_ATRAS);
                break;

            case GIRO_IZQUIERDA:
                objeto->doblar(GIRO_IZQUIERDA);
                break;

            case ARRIBA:
                objeto->cambiar_nivel(ARRIBA);
                break;

            case ABAJO:
                objeto->cambiar_nivel(ABAJO);
                break;

            default:
                break;
       }
    } while (seleccion != 0);
    
    auto finish = chrono::high_resolution_clock::now();
    objeto->agregarHistorial("DETENCION");
    
    for(int i = 0; i < cont; i++){
        cout << objeto->getHistorial(i) << endl;
    }
    
    cout << "\nLa distancia recorrida fue de: " << objeto->getDistancia() 
            << " unidades" << endl;
    
    chrono::duration<double> elapsed = finish - start;
    
    cout << "El tiempo que el objeto estuvo en movimiento fue de: "
            << elapsed.count() << "s" << endl;
    
    return 0;
}
