//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *file) {
    int number_type;
    try {
        while (max_len > len && (storage[len] = Number::StaticIn(file)) != nullptr) {
            len++;
        }
        // исключаем переполнение
        if (max_len <= len && Number::StaticIn(file) != nullptr) {
            fprintf(file, "Слишком много элементов, оставшиеся элементы не будут считаны");
        }
    } catch (std::exception Ex) { }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        // check EOF (and in StaticInRnd() method) - same for In()
        if ((storage[len] = Number::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file,"%d: ", i);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Перемещение всех чисел с вещественным представлением больше среднего в конец конейнера
double Container::SortLargerElements() {
    double average = 0.0;
    for (int i = 0; i < this->len; i++) {
        average += storage[i]->RealRepresentation();
    }
    average = average / this->len;

    Number *new_container[max_len];
    auto index = 0;
    // Adding elements with real representation less than average.
    for (int i = 0; i < (this->len); i++) {
        if (storage[i]->RealRepresentation() <= average) {
            new_container[index] = this->storage[i];
            ++index;
        }
    }

    for (int i = 0; i < (this->len); i++) {
        if (storage[i]->RealRepresentation() > average) {
            new_container[index] = storage[i];
            ++index;
        }
    }

    for (int i = 0; i < len; i++) {
        storage[i] = new_container[i];
    }
    return average;
}


