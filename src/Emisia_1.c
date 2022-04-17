//
// Created by Timur Kramar on 17/04/2022.
//

#include "stdio.h"

unsigned int uholnik_roztaty_priamkou_pocet_komponent(
        const float *x, const float *y, unsigned int l, float a, float b, float c) {

    int prienik_counter = 0;                // počítadlo, koľko krát prenikne priamka cez okraj uholnika
    unsigned short int last_pos = 0;        // -1 => pod priemkou, 1 => nad priamkov, 0 => na priamke
    unsigned short int new_pos = 0;

            // Zisti polohu posledného bodu ku priamke
    float diff = y[l-1] - (float) - (a*x[l-1] + c) / (float) b;
    if (diff > 0) {
        last_pos = 1;
    } else if (diff < 0) {
        last_pos = -1;
    } else {
        last_pos = 0;
    }

    for (int i = 0; i < l; i++) {
                // Zisti polohu i-teho bodu ku priamke
        diff = y[i] - (float) - (a*x[i] + c) / (float) b;
        if (diff > 0) {
            new_pos = 1;
        } else if (diff < 0) {
            new_pos = -1;
        } else {
            new_pos = 0;
        }

                // Zisti, či sa zmenila poloha, ak hej, musel byť prienik
        if (new_pos != last_pos) {
            //printf("medzi bodom %d a %d je prienik", i-1, i);
            prienik_counter++;
        }
        last_pos = new_pos;
    }
    return prienik_counter;
}

int main(void) {
    float x[5] = {};
    float y[5] = {};
    float a, b, c;
    a = 5;
    b = 6;
    c = 2;

    printf("Našli sme %d preienikov, to znamená, že uholnik bol rozdelený na %d častí.",
           uholnik_roztaty_priamkou_pocet_komponent(x,y,5,a,b,c),
           uholnik_roztaty_priamkou_pocet_komponent(x,y,5,a,b,c)/2);
}
