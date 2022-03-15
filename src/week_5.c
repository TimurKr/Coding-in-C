//
// Created by Timur Kramar on 15/03/2022.
//

#include <printf.h>

void vypis_pole(int *p, int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", p[i]);
    }
    printf("\n");
}

void otoc_pole(int *p, int n){
    int aux;
    for (int i = 0; i < n/2; i++){
        aux = p[i];
        p[i] = p[n-i-1];
        p[n-i-1] = aux;
    }
}

int main(void){
    int a[5];
    int n = 5;
    vypis_pole(a,n);
    otoc_pole(a,n);
    vypis_pole(a,n);
}