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
 * File:   EfectorFinal.cpp
 * Author: Gino Avanzini
 * 
 * Created on September 29, 2018, 9:28 PM
 */

#include <unistd.h>
#include <queue>
#include <iostream>
#include <string>
#include "EfectorFinal.h"

EfectorFinal::EfectorFinal() {
    
    //Carga de velocidad por defecto
    this->SetVelocidad(2);
}


EfectorFinal::~EfectorFinal() {
}


int EfectorFinal::GetVelocidad() const {
    return velocidad;
}
void EfectorFinal::SetVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

std::string EfectorFinal::GetEstado() const{
    if(this->estado == 0){
        return "INACTIVO";
    } else {
        return "ACTIVO";
    }
}
void EfectorFinal::SetEstado(int estado){
    this->estado = estado;
}
void EfectorFinal::SetActivo(){
    this->SetEstado(1);
}
void EfectorFinal::SetInactivo(){
    this->SetEstado(0);
}


void EfectorFinal::Iniciar(std::queue<int> operaciones, std::queue<int> ciclos){

    int i, ciclo, actual;
    std::string op_actual;
    
    while(!operaciones.empty()){
        
        ciclo = ciclos.front();
        actual = operaciones.front();
    
        for (i = 0; i < ciclo; i++){
            
            this->SetActivo();
            std::cout << "Estado: " << this->GetEstado() << std::endl;
        
            switch(actual){
                case(PARADA):
                    
                    op_actual = "PARADA";
                    break;

                case(PINTAR):
                    this->pintar();
                    op_actual = "PINTAR";
                    break;

                case(SOSTENER):
                    this->sostener();
                    op_actual = "SOSTENER";
                    break;

                case(SOLTAR):
                    this->soltar();
                    op_actual = "SOLTAR";
                    break;

                case(ROTAR):
                    this->rotar();
                    op_actual = "ROTAR";
                    break;

                case(CAMBIARV):
                    op_actual = "CAMBIAR_VEL";
                    operaciones.pop();        
                    this->cambiar_velocidad(operaciones.front());
                    break;
                    
                default:
                    std::cout << "Hubo un problema, se recomienta reiniciar";
                    break;
            }
            
            std::cout << "Acción: " << op_actual << std::endl
                    << "Ciclo " << i + 1 << " de " << ciclo << std::endl
                    << "Velocidad: " << this->GetVelocidad() << std::endl;

            this->SetInactivo();
            std::cout << "Estado: " << this->GetEstado() << "\n" << std::endl;

        }

        operaciones.pop();
        ciclos.pop();
        
        std::cout << "\n" << std::endl;
                
    }
    
}

void EfectorFinal::pintar(){
    usleep(500000);
}

void EfectorFinal::sostener(){
    usleep(500000);
}

void EfectorFinal::soltar(){
    usleep(500000);
}

void EfectorFinal::rotar(){
    usleep(500000);
}

void EfectorFinal::cambiar_velocidad(int velocidad){
    this->SetVelocidad(velocidad);
    usleep(500000);
}
