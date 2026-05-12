#include <stdlib.h>
#include "types.h"
#include "field.h"

static FieldInfo real_field = {sizeof(float), create_r, print_r, calc_r, addit_r, subtr_r, multip_r, fill_r};
static FieldInfo complex_field = {sizeof(float) * 2, create_c, print_c, calc_c, addit_c, subtr_c, multip_c, fill_c};

FieldInfo* get_real_field() {
    return &real_field;
}

FieldInfo* get_complex_field() {
    return &complex_field;
}