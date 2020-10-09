#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int i, n;
    char ns[10];
    printf("Enter a number: ");
    fgets(ns, 10, stdin);
    n = atoi(ns);

    for(i=0; i<=n; i++){
        int fn = 12*(i+1)*(1+i)*(1+i) + 12*(1+i);
        printf("f(%4d) = %10d, mod 24 = %2d\n", i, fn, fn % 24);
    }

    return 0;
}
