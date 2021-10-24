#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "random.h"

//------------------------------------------------------------------------------
// класс, обобщающая все имеющиеся числа
class Number {
protected:
    static Random rnd20;
    static Random rnd3;
public:
    virtual ~Number() {};
    // Ввод обобщенного числа
    static Number *StaticIn(FILE *file);
    // Ввод обобщенного числа
    virtual void In(FILE *file) = 0;
    // Случайный ввод обобщенного числа
    static Number *StaticInRnd();
    // Виртуальный метод ввода случайного числа
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(FILE *file) = 0;
    // Вычисление периметра обобщенного числа
    virtual double RealRepresentation() = 0;
};


#endif
