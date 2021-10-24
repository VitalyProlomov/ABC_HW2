#ifndef __Rabdom__
#define __Rabdom__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// Random.h - содержит генератор случайных чисел
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // системные часы в качестве инициализатора

    }
    // Генерация случайного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }
    static int Get20() {
        return rand() % 40 - 20;
    }

private:
    int first;
    int last;
};

#endif //__Rabdom__
