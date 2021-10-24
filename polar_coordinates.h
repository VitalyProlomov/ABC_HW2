#pragma once
#ifndef __polar_coordinates__
#define __polar_coordinates__

//------------------------------------------------------------------------------
// polar_coordinates.h - содержит описание полярных координат и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

# include "random.h"
#include "number.h"
#include <stdio.h>
// полярные координаты
class Polar_coordinates : public Number {
private:
    int radians;
    int length; // угол в радианах, модуль расстояния от начала коорд-т
public:
// Ввод параметров полярных координат из файла
    void In(FILE *file);

// Случайный ввод параметров полярных координат
    void InRnd();

// Вывод параметров полярных координат в файл
    void Out(FILE *file);

// Вычисление вещественного представления полярных координат
    double RealRepresentation();
};
#endif //__polar_coordinates__
