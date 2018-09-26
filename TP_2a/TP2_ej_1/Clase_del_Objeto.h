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
 * File:   Clase_del_Objeto.h
 * Author: Gino Avanzini
 *
 * Created on September 24, 2018, 3:24 PM
 */

#ifndef CLASE_DEL_OBJETO_H
#define CLASE_DEL_OBJETO_H

#include <vector>
#include <string>


enum direccion{
        NINGUNA, AVANZAR, GIRO_DERECHA, GIRO_ATRAS, GIRO_IZQUIERDA, ARRIBA, ABAJO
};


class Clase_del_Objeto {

public:
    
    Clase_del_Objeto();
    
    Clase_del_Objeto(int x, int y, int z);
    
    void cambiar_nivel(int hacia);
    void doblar(int hacia);
    void avanzar();
    
    int getCoord_x() const;
    void setCoord_x(int coord_x);

    int getCoord_y() const;
    void setCoord_y(int coord_y);

    int getCoord_z() const;
    void setCoord_z(int coord_z);

    int getDistancia() const;    
    void aumentarDistancia();
    
    void agregarHistorial(std::string movimiento);
    
    std::string getHistorial(int movimiento);

    virtual ~Clase_del_Objeto();
    
    
private:
    
    int coord_x;
    int coord_y;
    int coord_z;
    int distancia;
    
    std::vector<int> direccion;

    std::vector<std::string> historial;
    
};

#endif /* CLASE_DEL_OBJETO_H */

