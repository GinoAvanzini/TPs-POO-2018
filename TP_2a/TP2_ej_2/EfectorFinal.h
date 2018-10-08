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
 * File:   EfectorFinal.h
 * Author: Gino Avanzini
 *
 * Created on September 29, 2018, 9:28 PM
 */

#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

enum state {
    INACTIVO, ACTIVO
};

enum operaciones {
    PARADA, PINTAR, SOSTENER, SOLTAR, ROTAR, CAMBIARV    
};

class EfectorFinal {
    
public:
    EfectorFinal();
    virtual ~EfectorFinal();

    int GetVelocidad() const;
    void SetVelocidad(int velocidad);
    std::string GetEstado() const;
    void SetActivo();
    void SetInactivo();
    
    
    void Iniciar(std::queue<int> operaciones, std::queue<int> ciclos);
    void pintar();
    void sostener();
    void soltar();
    void rotar();
    void cambiar_velocidad(int velocidad);
    

private:
    
    void SetEstado(int estado);
    
    int velocidad;
    int estado;
    
};

#endif /* EFECTORFINAL_H */

