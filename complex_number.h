#ifndef __Complex_number__
#define __Complex_number__

//------------------------------------------------------------------------------
// complex_number.h - содержит описание комплексного числа
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "random.h"
#include "number.h"
#include <stdio.h>
//------------------------------------------------------------------------------
// комплексное число
class Complex_number: public Number {
public:
    virtual ~Complex_number() {}
    // Ввод параметров комплексного числа из файла
    virtual void In(FILE *file);
    // Случайный ввод параметров комплексного числа
    virtual void InRnd();
    // Вывод параметров комплексного числа в форматируемый файл
    virtual void Out(FILE *file);
    // Вычисление вещественного представления комплексного числа
    virtual double RealRepresentation();
private:
    int real_part;
    int imaginary_part;
};

#endif //__Complex_number__
