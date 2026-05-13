#ifndef LINEARFORM_H
#define LINEARFORM_H

#include "field.h"

typedef struct linear_form {
    FieldInfo* fieldinfo;
    void* data;
    int size;
} linear_form;
//вычисление линейной формы, возвращает ссылку на результат
void* calculate(linear_form base);

//сложение линейных формрезультат перезаписывает первую форму)
void addition(linear_form form1, linear_form form2);

//вычитание линейных форм(результат перезаписывает первую форму)
void subtraction(linear_form form1, linear_form form2);

//умножение линейной формы на скаляррезультат перезаписывает форму)
void multiplication(linear_form form1, float multiplier);

//вывод линейной формы
void print_form(linear_form form);

//создание линейной формы(заполненной 1)
linear_form create_linear_form(FieldInfo* (*of_field)(), int size);

//заполнение линейной формы произвольными значениями(перезаписывает форму)
void set_linear_form(linear_form base);

#endif
