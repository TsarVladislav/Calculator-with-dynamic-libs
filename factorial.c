/* подсчет факториала числа */
#include "operations.h"
int factorial(int n)
{
    int answer = 1;
    /* факториал отрицательного числа *можно* подсчитать, но сложно */
    if(n < 0){
        printf("Факториал отрицательного числа не считаю");
        return -1;
    }
    while(n > 0){
        answer *= n;
        n--;
    }
    return answer;
}
