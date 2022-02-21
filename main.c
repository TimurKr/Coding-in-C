#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Github "peter.kantor.sarkoci@gmail.com"

#define n 7

void remove_duplicates(int len, unsigned int a[len]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] == a[j]) a[i] = 0;
        }
    }
}

int prienik(int len, unsigned int a[len], unsigned int b[len], unsigned int c[len]){
    int k = 0;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            if (a[i] == b[j]){
                c[k] = a[i];
                int counter = 0;
                for (int l = 0; l < len; l++){
                    if (c[l] == c[k]) counter ++;
                    if (counter == 2) {
                        c[k] = 0;
                        k--;
                        break;
                    }
                }
                k++;
            }
        }
    }
    return k;
}

int zjednotenie(int len, unsigned int a[len], unsigned int b[len], unsigned int c[2*len]) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        c[k] = a[i];
        int counter = 0;
        for (int l = 0; l < 2*len; l++) {
            if (c[l] == c[k]) counter++;
            if (counter == 2) {
                c[k] = 0;
                k--;
                break;
            }
        }
        k++;
    }
    for (int i = 0; i < len; i++) {
        c[k] = b[i];
        int counter = 0;
        for (int l = 0; l < c[k]; l++) {
            if (c[l] == c[k]) counter++;
            if (counter == 2) {
                c[k] = 0;
                k--;
                break;
            }
        }
        k++;
    }
    return k;
}

void pis_mnozinu(int len, unsigned int mn[len]){
    for (int i = 0; i < len; i++){
        printf("%d\t", mn[i]);
    }
    printf("\n");
}

int main() {
    unsigned int a[n] = {};
    unsigned int b[n] = {};
    unsigned int c[n] = {};
    unsigned int d[2*n] = {};
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        a[i] = 1 + rand() % 10;
        b[i] = 1 + rand() % 10;
    }
    remove_duplicates(n, a);
    remove_duplicates(n, b);
    pis_mnozinu(n, a);
    pis_mnozinu(n, b);
    int dlzka_prienik = prienik(n, a, b, c);
    pis_mnozinu(dlzka_prienik, c);
//    int dlzka_zjednotenie = zjednotenie(n, a, b, d);
//    pis_mnozinu(dlzka_zjednotenie, d);
}
