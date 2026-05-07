#include "real.h"

void create_r(void* data) {
    float* massiv = (float*)data;
    massiv[0] = 1.0;
}

void addit_r(void* elem1, void* elem2) {
    float* data1 = (float*)elem1;
    float* data2 = (float*)elem2;
    data1[0] = data1[0] + data2[0];
}

void subtr_r(void* elem1, void* elem2) {
    float* data1 = (float*)elem1;
    float* data2 = (float*)elem2;
    data1[0] = data1[0] - data2[0];
}

void calc_r(void* answer, void* elem, float coef) {
    float* data1 = (float*)elem;
    ((float*)answer)[0] += data1[0] * coef;
}

void multip_r(void* form, float multiplier) {
    float* data = (float*)form;
    data[0] = data[0] * multiplier;
}

void print_r(void* form) {
    float* data = (float*)form;
    printf("%f", data[0]);
    printf("%s", "   ");
}