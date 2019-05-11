#include "/home/mateus/ban/math/programs/utils/definitions.h"

Natural generate_primes(Natural qtty_primes, Natural * pt_primes)
{
    setlocale(LC_NUMERIC, "");

    Natural i, j, k, primes[qtty_primes];

    for(j=2, i=0; i<qtty_primes ; j++){ // generate numbers to be checked if they are prime or not
        for(k=2; k<j; k++){ // k will try to divide j
            if(j%k == 0)
                break; 
        }
        if(j==k)
            pt_primes[i++]=j;
    }
    return 0;
}

Natural lowest_common_multiple(Natural const *numbers_){
    Natural numbers[1000]={};
    int i, j=0;

    // Copy the value to another array, because we need to change its values.
    i=-1;
    do {
        i++;
        numbers[i]=numbers_[i];
    }while(numbers_[i] != 0 );

    Natural lcm=1, divisor;
    for(int i=0; numbers[i] != 0; i++){
        lcm*=numbers[i];
        divisor = numbers[i];
        for(j=i; numbers[j] != 0; j++){
//            printf("i=%d, j=%d\n",i, j); // uncomment for debug
            if(numbers[j]%divisor == 0)
                numbers[j] /= divisor;
        }
    }
    return lcm;
}

// Return the number of fibonacci numbers generated correctly, i. e., that it didnt 'overflow'.
// See https://stackoverflow.com/questions/16056758/c-c-unsigned-integer-overflow
int generate_fibonacci(Natural const F_1, Natural const F_2, Natural *arr, int const max){
    int qtty_correct; // Quantity of fibonacci numbers generated that does not 'overflow'.
    int i;
    arr[0]=F_1;
    arr[1]=F_2;

    for(i=1; i<max; i++){
        if( arr[i] > ULLONG_MAX - arr[i-1]){ // test 'overflow'
            break;
        }else
            arr[i+1]=(Natural)arr[i]+arr[i-1];
    }
    if( arr[i] > ULLONG_MAX - arr[i-1] ){
        qtty_correct = i-1;
    }else{
        qtty_correct = i;
    }

    return qtty_correct;
}

