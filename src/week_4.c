//
// Created by Timur Kramar on 08/03/2022.
//

#include <printf.h>

int main(void){
    char a;
    short int b = 256;
    int c;
    long d;
    long long e;
    float f;
    double g;
    long double h;
    short int *p = &b;

    printf("char: %lu\n", sizeof(a));
    printf("short int: %lu\n", sizeof(b));
    printf("int: %lu\n", sizeof(c));
    printf("long: %lu\n", sizeof(d));
    printf("long long: %lu\n", sizeof(e));
    printf("float: %lu\n", sizeof(f));
    printf("double: %lu\n", sizeof(g));
    printf("long double: %lu\n", sizeof(h));
    printf("pointer: %lu\n", sizeof(p));

    a = *p;
    printf("a = %d", a);
}