#include <stdlib.h>
#include <stdio.h>

int main(void){

    const int a = 100;
    
    int *ptr = (int *)&a;
    *ptr = 200;
    printf("%d\n",a);
    return 0;
}