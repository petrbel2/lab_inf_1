#include <stdlib.h>
#include "types.h"
#include "field.h"

static FieldInfo real_field = {sizeof(float), create_r, print_r, calc_r, addit_r, subtr_r, multip_r};
static FieldInfo complex_field = {sizeof(float) * 2, create_c, print_c, calc_c, addit_c, subtr_c, multip_c};

FieldInfo* get_real_field() {
    if (&real_field == NULL) {
        FieldInfo real_field = {sizeof(float), create_r, print_r, calc_r, addit_r, subtr_r, multip_r};
    }
    else {
        return &real_field;
    }
}

FieldInfo* get_complex_field() {
    if (&complex_field == NULL) {
        FieldInfo complex_field = {sizeof(float) * 2, create_c, print_c, calc_c, addit_c, subtr_c, multip_c};
    }
    else {
        return &complex_field;
    }
}