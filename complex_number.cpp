//------------------------------------------------------------------------------
// complex_number.cpp - содержит функции обработки комплексного числа
//------------------------------------------------------------------------------
#include <math.h>
#include "complex_number.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
void Complex_number::In(FILE *file) {
    fscanf(file,"%d", &real_part);
    fscanf(file,"%d", &imaginary_part);
}

// Случайный ввод параметров комплексного числа
void Complex_number::InRnd() {
    real_part = Random::Get20();
    imaginary_part = Random::Get20();
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
void Complex_number::Out(FILE *file) {
    fprintf(file, "It is Complex_number: real_part = ");
    fprintf(file,"%d, imaginary_part = %d\n", real_part, imaginary_part);
    fprintf(file,"RealRepresentation = %f\n",RealRepresentation());
}

//------------------------------------------------------------------------------
// Вычисление вещественного представления комплексного числа
double Complex_number::RealRepresentation() {
    return double(sqrt(real_part*real_part + imaginary_part*imaginary_part));
}
