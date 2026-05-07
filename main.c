#include "tests.c"

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int choice;
    int size = 3;
    float multiplier;
    printf("Tests\n");
    test_real();
    test_complex();
    test_errors();
    linear_form formA = create_linear_form(get_real_field, size);
    linear_form formB = create_linear_form(get_real_field, size);
    printf(" [1] calculate form A\n");
    printf(" [2] Addition form A += form B\n");
    printf(" [3] Subtract form A -= form B\n");
    printf(" [4] Multiply form A\n");
    printf(" [5] print form A\n");
    printf(" [6] print form B\n");
    printf(" [7] Subtract form B -= form A\n");
    printf(" [8] calculate form B\n");
    printf(" [9] Addition form B += form A\n");
    printf(" [10] multiply form B\n");
    printf(" [0] Exit\n");
    printf("----------------------------\n");
    while (1) {
        
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введено не число.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                calculate(formA);
                break;
            case 2:
                addition(formA, formB);
                break;
            case 3:
                subtraction(formA, formB);
                break;
            case 4:
                printf("Multiplier: ");
                if (scanf("%f", &multiplier) == 1) {
                    multiplication(formA, multiplier);
                } else {
                    printf("Ошибка: некорректное число.\n");
                }
                clear_input_buffer();
                break;
            case 5:
                print_form(formA);
                break;
            case 6:
                print_form(formB);
                break;
            case 7:
                subtraction(formB, formA);
                break;
            case 8:
                calculate(formB);
                break;
            case 9:
                addition(formB, formA);
                break;
            case 10:
                printf("Multiplier ");
                if (scanf("%f", &multiplier) == 1) {
                    multiplication(formA, multiplier);
                } else {
                    printf("Ошибка: некорректное число.\n");
                }
                clear_input_buffer();
                break;
            default:
                printf("Wrong number.\n");
                break;
            case 0:
                printf("Leaving\n");
                free(formA.data);
                free(formB.data);
                return 0;
        }
    }
}
