#include "tests.h"

void test_real() {
    linear_form f_1 = create_linear_form(get_real_field, 4);
    linear_form f_2 = create_linear_form(get_real_field, 4);
    int checker = 1;
    addition(f_1, f_2);
    for (int i = 0; i < 4; i++) {
        if (((float*)f_1.data)[i] != 2.0) {
            checker = 0;
        }
    }
    if (checker == 0) {
        printf("%s", "Addition failture\n");
    }
    else {
        printf("%s", "Addition test successfull\n");
    }
    void* result = (float*)calculate(f_1);
    if (((float*)result)[0] != 20.0) {
        printf("%s", "Form calculation failture\n");
    }
    else {
        printf("%s", "Calculation test successfull\n");
    }
    free(result);
    free(f_1.data);
    free(f_2.data);
}

void test_complex() {
    linear_form f_3 = create_linear_form(get_complex_field, 4);
    linear_form f_4 = create_linear_form(get_complex_field, 4);
    int checker = 1;
    multiplication(f_3, 2.0);
    for (int i = 0; i < 8; i++) {
        if (((float*)f_3.data)[i] != 2.0) {
            checker = 0;
        }
    }
    if (checker == 0) {
        printf("%s", "Multiplication failture\n");
    }
    else {
        printf("%s", "Multiplication test successfull\n");
    }
    checker = 1;
    subtraction(f_3, f_4);
    for (int i = 0; i < 8; i++) {
        if (((float*)f_3.data)[i] != 1.0) {
            checker = 0;
        }
    }
    if (checker == 0) {
        printf("%s", "Substraction failture\n");
    }
    else {
        printf("%s", "Subtraction test successfull\n");
    }
    print_form(f_4);
    free(f_3.data);
    free(f_4.data);
}

void test_errors() {
    printf("%s", "Testing errors\n");
    linear_form f_1 = create_linear_form(get_real_field, 4);
    linear_form f_2 = create_linear_form(get_real_field, 3);
    addition(f_1, f_2);
    linear_form f_3 = create_linear_form(get_complex_field, 4);
    addition(f_3, f_2);
    free(f_1.data);
    free(f_2.data);
    free(f_3.data);
}