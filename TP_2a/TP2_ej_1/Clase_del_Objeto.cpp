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
 * File:   Clase_del_Objeto.cpp
 * Author: Gino Avanzini
 * 
 * Created on September 24, 2018, 3:24 PM
 */


#include "Clase_del_Objeto.h"

using namespace std;

// Constructor
// Posición inicial en el origen
Clase_del_Objeto::Clase_del_Objeto() {
    
    this->coord_x = 0;
    this->coord_y = 0;   
    this->coord_z = 0;
    
    this->distancia = 0;
    
    this->direccion.push_back(1);
    this->direccion.push_back(0);
          
}

//El objeto arranca en una posición dada por el usuario
//Sobrecarga del constructor
Clase_del_Objeto::Clase_del_Objeto(int x, int y, int z) {
    
    this->coord_x = x;
    this->coord_y = y;   
    this->coord_z = z;
    
    this->distancia = 0;
    
    this->direccion.reserve(2);
    
    this->direccion[0] = 1;
    this->direccion[1] = 0;
    
}


//Destructor
Clase_del_Objeto::~Clase_del_Objeto() {
}


int Clase_del_Objeto::getCoord_x() const {
    return coord_x;
}
void Clase_del_Objeto::setCoord_x(int coord_x) {
    this->coord_x = coord_x;
}


int Clase_del_Objeto::getCoord_y() const {
    return coord_y;
}
void Clase_del_Objeto::setCoord_y(int coord_y) {
    this->coord_y = coord_y;
}


int Clase_del_Objeto::getCoord_z() const {
    return coord_z;
}
void Clase_del_Objeto::setCoord_z(int coord_z) {
    this->coord_z = coord_z;
}


int Clase_del_Objeto::getDistancia() const {
        return distancia;
}
void Clase_del_Objeto::aumentarDistancia(){
    this->distancia += 1;
}


void Clase_del_Objeto::doblar(int hacia){
    
    if (hacia == GIRO_IZQUIERDA){
        
        int aux_x = this->direccion[0];
        int aux_y = this->direccion[1];
        
        this->direccion[0] = -aux_y; 
        this->direccion[1] = aux_x;
        
        this->agregarHistorial("GIRO_IZQ");
        
    } else if (hacia == GIRO_DERECHA){

        int aux_x = this->direccion[0];
        int aux_y = this->direccion[1];

        this->direccion[0] = aux_y; 
        this->direccion[1] = -aux_x;   
        
        this->agregarHistorial("GIRO_DER");
        
    } else if (hacia == GIRO_ATRAS){
        this->direccion[0] *= -1;
        this->direccion[1] *= -1;
        this->agregarHistorial("GIRO_ATRAS");
    }
}


void Clase_del_Objeto::avanzar(){
    
    this->coord_x += this->direccion[0];
    this->coord_y += this->direccion[1];
    
    this->aumentarDistancia();
    
    this->agregarHistorial("AVANZAR");
    
}

void Clase_del_Objeto::cambiar_nivel(int hacia){
    
    if (hacia == ARRIBA){
        
        this->setCoord_z(this->getCoord_z() + 1);
        this->agregarHistorial("ARRIBA");
        
    } else if (hacia == ABAJO){
        
        this->setCoord_z(this->getCoord_z() + 1);
        this->agregarHistorial("ABAJO");
    
    }
    
    this->aumentarDistancia();
    
}


void Clase_del_Objeto::agregarHistorial(std::string movimiento){
    this->historial.push_back(movimiento);
}

std::string Clase_del_Objeto::getHistorial(int movimiento){
    
    return this->historial[movimiento];
    
}





