//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольного числа
//------------------------------------------------------------------------------

#include "rational_number.h"
#include "complex_number.h"
#include "polar_coordinates.h"

//------------------------------------------------------------------------------
Random Number::rnd20(0, 40);
Random Number::rnd3(1, 3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного числа из файла
Number *Number::StaticIn(FILE *file) {
    int number_type;

    if (fscanf(file, "%d", &number_type) == EOF) {
        return nullptr;
    }
    Number *entered_number = nullptr;
    switch (number_type) {
        case 1:
            entered_number = new Complex_number;
            break;
        case 2:
            entered_number = new Rational_number;
            break;
        case 3:
            entered_number = new Polar_coordinates;
            break;
    }
    entered_number->In(file);
    return entered_number;

}

// Случайный ввод обобщенного числа
Number *Number::StaticInRnd() {
    auto number_type = Number::rnd3.Get();
    Number *generated_number = nullptr;
    switch (number_type) {
        case 1:
            generated_number = new Rational_number;
            break;
        case 2:
            generated_number = new Complex_number;
            break;
        case 3:
            generated_number = new Polar_coordinates;
            break;
    }
    generated_number->InRnd();
    return generated_number;
}
