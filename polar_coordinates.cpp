
#include "polar_coordinates.h"
#include "random.h"
//------------------------------------------------------------------------------
// Ввод параметров полярных координат из файла
void Polar_coordinates::In(FILE *file) {
    fscanf(file, "%d %d", &length, &radians);
}

// Случайный ввод параметров полярных координат
void Polar_coordinates::InRnd() {
    int rnd1 = rand() * 0.00001;
    int rnd2 = rand() * 0.00001;
    length = Random(-20,20).Get() + rnd1;
    radians = Random::Get20() + rnd2;
}

//------------------------------------------------------------------------------
// Вывод параметров полярных координат в форматируемый поток
void Polar_coordinates::Out(FILE *file) {
    fprintf(file, "It is a polar coordinates number: Length = %d, Radians = %d.\n", length, radians);
    fprintf(file, "Real representation = %f\n", RealRepresentation());
}

//------------------------------------------------------------------------------
// Вычисление вещественного представления полярных координат
double Polar_coordinates::RealRepresentation() {
    return length;
}
