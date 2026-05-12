#include <stdio.h>
#include <stdlib.h>
#include "linear_form.h"
#include "field.h"

void addition(linear_form form1, linear_form form2) {
    if (form1.fieldinfo != form2.fieldinfo) {
        printf("%s", "No cross-type addition\n");
    }
    else {
        if (form1.size != form2.size) {
        printf("%s", "Different lengths - addition not possible\n");
    }
    else {
        for (int i = 0; i < form1.size; i++) {
            form1.fieldinfo->addit((char*)form1.data + i * form1.fieldinfo->type_size, (char*)form2.data + i * form1.fieldinfo->type_size);
            }
        }
    }
}

void subtraction(linear_form form1, linear_form form2) {
    if (form1.fieldinfo != form2.fieldinfo) {
        printf("%s", "No cross-type subtraction\n");
    }
    else {
    if (form1.size != form2.size) {
        printf("%s", "Different lengths - subtraction not possible");
    }
    else {
        for (int i = 0; i < form1.size; i++) {
            form1.fieldinfo->subtr((char*)form1.data + i * form1.fieldinfo->type_size, (char*)form2.data + i * form1.fieldinfo->type_size);
            }
        }
    }
}

void multiplication(linear_form form1, float multiplier) {
    for (int i = 0; i < form1.size; i++) {
        form1.fieldinfo->multip((char*)form1.data + i * form1.fieldinfo->type_size, multiplier);
        }
}

void print_form(linear_form form) {
    for (int i = 0; i < form.size; i++) {
        form.fieldinfo->print((char*)form.data + i * form.fieldinfo->type_size);
    }
}

linear_form create_linear_form(FieldInfo* (*of_field)(), int size) {
    FieldInfo* field = of_field();
    void* data = malloc(size * field->type_size);
    for (int i = 0; i < size; i++) {
        field->create((char*)data + i * field->type_size);
    }
    linear_form form = {field, data, size};
    return form;
}

void* calculate(linear_form base) {
    void* answer = malloc(base.size * base.fieldinfo->type_size);
    int flag = 0;
    float coef = 1;
    for (int i = 0; i < base.size; i++) {
        base.fieldinfo->calc(answer, (char*)base.data + i * base.fieldinfo->type_size, coef, &flag);
        coef += 1;
    }
    printf("%s", "Linear form calculation: ");
    base.fieldinfo->print(answer);
    printf("%s", "\n");
    return answer;
}

void set_linear_form(linear_form base) {
    for (int i = 0; i < base.size; i++) {
        base.fieldinfo->fill((char*)base.data + i * base.fieldinfo->type_size);
    }
}