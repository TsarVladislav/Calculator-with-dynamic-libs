/* операция деления двух чисел */
#include "operations.h"

int mdiv(int a, int b)
{
    if (b == 0){
        printf("ЕГГОГ ДЕЛЕНИЕ НА НОЛЬ\n");
        return 0;
    }
    return a / b;
}
