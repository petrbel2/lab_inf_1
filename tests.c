#include "tests.h"

void test_real() {
    printf("%s", "Created 2 linear forms(real numbers), size 4, filled with 1\n");
    linear_form f_1 = create_linear_form(get_real_field, 4);
    linear_form f_2 = create_linear_form(get_real_field, 4);
    addition(f_1, f_2);
    printf("%s", "Form addition\n");
    calculate(f_1);
    free(f_1.data);
    free(f_2.data);
}

void test_complex() {
    printf("%s", "Created 2 linear forms(complex numbers), size 4, filled with 2 + 2i and 1 + 1i\n");
    linear_form f_3 = create_linear_form(get_complex_field, 4);
    linear_form f_4 = create_linear_form(get_complex_field, 4);
    subtraction(f_3, f_4);
    printf("%s", "Form subtraction\n");
    calculate(f_3);
    print_form(f_4);
    free(f_3.data);
    free(f_4.data);
}

void test_errors() {
    printf("%s", "Created 2 linear forms(real numbers), sizes 4 and 3, filled with 1\n");
    linear_form f_1 = create_linear_form(get_real_field, 4);
    linear_form f_2 = create_linear_form(get_real_field, 3);
    printf("%s", "Trying to sum the forms\n");
    addition(f_1, f_2);
    printf("%s", "Created linear form(complex numbers), size 4, filled with 1 + i\n");
    linear_form f_3 = create_linear_form(get_complex_field, 4);
    printf("%s", "Trying to sum the forms(real and complex)\n");
    addition(f_3, f_2);
    free(f_1.data);
    free(f_2.data);
    free(f_3.data);
}