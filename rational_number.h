#ifndef __rational_number__
#define __rational_number__

//------------------------------------------------------------------------------
// rational_number.h - содержит описание рационального числа и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

#include "random.h"
#include "number.h"
#include <stdio.h>

// рациональное число
class Rational_number: public Number {
public:
    virtual ~Rational_number() {}
    // Ввод параметров рационального числа из файла
    virtual void In(FILE *file);
    // Случайный ввод параметров рационального числа
    virtual void InRnd();
    // Вывод параметров рационального числа в форматируемый поток
    virtual void Out(FILE *file);
    // Вычисление вещественного представления рационального числа
    virtual double RealRepresentation();
private:
    int numerator, denominator; // числитель, знаменатель
};

#endif //__rational_number__
