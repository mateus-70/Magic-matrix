#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LINE_LEN 50
int main(void){
    char cn[2];
    fgets(cn, 2, stdin);
    int n=atoi(cn);
    printf("n=%d.\n",n);
    char arr[n][LINE_LEN+2]; // for 50+\n\0
    for(int i=0; i<=n; i++){
        fgets(arr[i], LINE_LEN, stdin);
    }

     /*
    for(int k=0; k<n; k++){
        for(int p=0; p<LINE_LEN+1; p++){
            putchar(arr[k][p]);
            if(arr[k][p]=='\n') break;
        }
    }
    */
    
    for(int i=0; i<n; i++){
        int getNext=1;
        for(int j=0; j<LINE_LEN; j++){
            if(arr[i][j] == '\n'){
                putchar('\n');
                break;
            }else{
                if( arr[i][j] == ' ')
                    getNext=1;
                else
                    if(getNext && arr[i][j] != ' '){
                        putchar(arr[i][j]);
                        getNext=0;
                }
            }
        }
    }
    

}
