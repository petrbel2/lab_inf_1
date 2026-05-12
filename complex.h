#ifndef COMPLEX_H
#define COMPLEX_H

//функции для работы с комплексными числами. Описания работы этих функций(для произвольного типа) записаны в field.h
void create_c(void* data);

void addit_c(void* elem1, void* elem2);

void subtr_c(void* form1, void* form2);

void calc_c(void* answer, void* elem, float coef);

void multip_c(void* form, float multiplier);

void print_c(void* form);

void fill_c(void* form);

#endif