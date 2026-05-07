#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

void create_c(void* data) {
    float* massiv = (float*)data;
    massiv[0] = 1.0;
    massiv[1] = 1.0;
}

void calc_c(void* answer, void* elem, float coef) {
    float* data1 = (float*)elem;
    ((float*)answer)[0] += data1[0] * coef;
    ((float*)answer)[1] += data1[1] * coef;
}

void addit_c(void* elem1, void* elem2) {
    float* data1 = (float*)elem1;
    float* data2 = (float*)elem2;
    data1[0] += data2[0];
    data1[1] += data2[1];
}

void subtr_c(void* elem1, void* elem2) {
    float* data1 = (float*)elem1;
    float* data2 = (float*)elem2;
    data1[0] -= data2[0];
    data1[1] -= data2[1];
}

void multip_c(void* form, float multiplier) {
    float* data = (float*)form;
    data[0] = data[0] * multiplier;
    data[1] = data[1] * multiplier;
}

void print_c(void* form) {
    float* data = (float*)form;
    printf("%f", data[0]);
    printf("%s", " + ");
    printf("%f", data[1]);
    printf("%s", "i\n");
}