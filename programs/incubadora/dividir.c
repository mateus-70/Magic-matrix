#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main()
{
    // Variaveis
    char s_divisor[100], s_dividend[100];
    int i_divisor, i_dividend;

    // Corpo

    printf("Dividend: ");
    fgets(s_dividend, 100, stdin);
    
    printf("Divisor: ");
    fgets(s_divisor, 100, stdin);

    i_divisor=atoi(s_divisor);
    i_dividend=atoi(s_dividend);

    printf("%06d \\ %05d.\n\n", i_dividend, i_divisor);

    p0=lenght(s_dividend)+1;
    for(p=0; p<length(s_dividend); )
    {

        if(atoi(part_div)/dividend == 0)
        {
            printf("%*d", p+1, )
        }
        else
        {

        }
        p++;
    }


    return 0;
}
