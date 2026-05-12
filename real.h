#ifndef REAL_H
#define REAL_H

#include <stdio.h>
#include <stdlib.h>

//функции для работы с действительными числами. Описания работы этих функций(для произвольного типа) записаны в field.h
void create_r(void* data);

void addit_r(void* form1, void* form2);

void subtr_r(void* form1, void* form2);

void calc_r(void* answer, void* elem, float coef, int* flag);

void multip_r(void* form, float multiplier);

void print_r(void* form);

void fill_r(void* form);

#endif