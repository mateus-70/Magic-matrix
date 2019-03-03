#include <stdio.h>
#include <stdlib.h>

int main()
{

    register long long unsigned i;
    register double f=0;
    for(i=1; f < 15;){
        f+=1.0/i++;
        printf("%20llu\n",i);
    }
    printf("A soma é: %f", f);


    return 0;
}
