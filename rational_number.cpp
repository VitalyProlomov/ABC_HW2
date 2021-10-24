//------------------------------------------------------------------------------
// rational_number.cpp - содержит методы рационального числа
//------------------------------------------------------------------------------

#include "rational_number.h"
#include <stdio.h>
//------------------------------------------------------------------------------
// Ввод параметров рационального числа из файла
void Rational_number::In(FILE *file) {
    fscanf(file, "%d,", &numerator);
    fscanf(file, "%d,", &denominator);
}

// Случайный ввод рационального числа прямоугольника
void Rational_number::InRnd() {
    numerator = Random::Get20();
    while (denominator == 0) {
        denominator = Number::rnd20.Get();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров рационального числа в форматируемый поток
void Rational_number::Out(FILE *file) {
    fprintf(file, "It is Rational_number: %d/%d", numerator, denominator);
    fprintf(file, ". RealRepresentation = %f\n",RealRepresentation());
}

//------------------------------------------------------------------------------
// Вычисление вещественного представления рационального числа
double Rational_number::RealRepresentation() {
    return (double)numerator / (double)denominator;

}
