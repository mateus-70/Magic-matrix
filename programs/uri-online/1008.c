#include <stdio.h>

int main(void)
{
    int n, h;
    float sal;
    scanf("%d", &n);
    scanf("%d", &h);
    scanf("%f", &sal);

    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2f\n", sal*h);
    return 0;
}
