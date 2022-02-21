#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Github "peter.kantor.sarkoci@gmail.com"

#define n 7

void pis_mnozinu(unsigned int len, unsigned int mn[len]){
    for (int i = 0; i < len; i++){
        printf("%d\t", mn[i]);
    }
    printf("\n");
}

unsigned int remove_duplicates(unsigned int len, unsigned int a[len]){
    // replace duplicates with 0
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] == a[j]) {
                a[j] = 0;
            }
        }
    }

    // move 0s to the back
    for (int i = 0; i < len; i++){
        if (a[i] == 0){
            for (int j = len-1; j > i; j--){
                if (a[j] != 0){
                    a[i] = a[j];
                    a[j] = 0;
                    break;
                }
            }
        }
    }
    unsigned int l = 0;
    for (int i = 0; a[i]!=0 && i < len; i++){
        l += 1;
    }
    return l;
}


unsigned int prienik(unsigned int a_len, unsigned int b_len, unsigned int a[a_len], unsigned int b[b_len],
            unsigned int c[n]){
    unsigned int k = 0;
    for (int i = 0; i < a_len; i++){
        for (int j = 0; j < b_len; j++){
            if (a[i] == b[j]) {
                c[k] = a[i];
                k++;
            }
        }
    }
    return k;
}


unsigned int zjednotenie(unsigned int a_len, unsigned int b_len, unsigned int a[a_len], unsigned int b[b_len],
                unsigned int d[a_len + b_len]) {
    for (unsigned int k = 0; k < a_len + b_len; k++) {
        if (k < a_len) d[k] = a[k];
        else d[k] = b[k - a_len];
    }
    unsigned int d_len = remove_duplicates(a_len + b_len, d);
    return d_len;
}


int main() {
    // init. lists
    unsigned int a[n] = {};
    unsigned int b[n] = {};

    // generate lists
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        a[i] = 1 + rand() % 10;
        b[i] = 1 + rand() % 10;
    }

    printf("Listy:\n");
    pis_mnozinu(n, a);
    pis_mnozinu(n, b);
    printf("\n");

    // cleanup lists
    unsigned int a_len = remove_duplicates(n, a);
    unsigned int b_len = remove_duplicates(n, b);

    printf("Množiny:\n");
    pis_mnozinu(a_len, a);
    pis_mnozinu(b_len, b);
    printf("\n");

    // calculate intersection
    unsigned int c[n] = {};
    unsigned int c_len = prienik(a_len, b_len, a, b, c);

    printf("Prienik:\n");
    pis_mnozinu(c_len, c);
    printf("\n");

    // calculate union
    unsigned int d[2 * n] = {};
    unsigned int dlzka_zjednotenie = zjednotenie(a_len, b_len, a, b, d);
    printf("Zjednotenie:\n");
    pis_mnozinu(dlzka_zjednotenie, d);
}
