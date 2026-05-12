#ifndef FIELD_H
#define FIELD_H

#include <stddef.h>

typedef struct FieldInfo {
    size_t type_size;
    //создание и запись значения произвольного типа
    void (*create)(void*);
    //вывод значения произвольного типа
    void (*print)(void*);
    //умножение значения произвольного типа на коэффициент(результат прибавляется ко второму переданному значению(того же типа))
    void (*calc) (void*, void*, float);
    //сложение двух значений одного произвольного типа(результат перезаписывает первое значение)
    void (*addit) (void*, void*);
    //вычитание  значений одного произвольного типа(результат перезаписывает первое значение)
    void (*subtr) (void*, void*);
    //умножение значения произвольного типа на коэффициент(результат перезаписывает изначальное значение)
    void (*multip) (void*, float);
} FieldInfo;

FieldInfo* get_real_field();

FieldInfo* get_complex_field();

#endif