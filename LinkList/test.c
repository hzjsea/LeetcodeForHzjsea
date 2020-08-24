#include<stdio.h>
#include<stdlib.h>



int  main() {
    int number = 2;
    printf("%p\n",&number);
    printf("%d\n",*&number);
    print("%p",(&number));
    return 0;

}