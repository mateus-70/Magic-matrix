#include "definitions.h"

int generate_primes(unsigned long long int qtty_primes, unsigned long long int * pt_primes)
{
    setlocale(LC_NUMERIC, "");

    int i, j, k, primes[qtty_primes];

    for(j=2, i=0; i<qtty_primes ; j++){ // generate numbers to be checked if they are prime or not
        for(k=2; k<j; k++){ // k will try to divide j
            if(j%k == 0)
                break; 
        }
        if(j==k)
            pt_primes[i++]=j;
    }

//    int r=0;
//    while(r<qtty_primes)
//        printf("Prime %d = %d.\n",r, pt_primes[r++]);

    return 0;
}
