//
// Created by Timur Kramar on 05/04/2022.
//
#include <stdlib.h>
#include <stdio.h>
typedef struct {
    float x, y, r;
} CIRCLE;

CIRCLE *new_circle(float x, float y ,float r){
    CIRCLE *circle = (CIRCLE *) malloc(sizeof(CIRCLE));

    if (circle == NULL){
        return NULL;
    }

    circle->x = x;
    circle->y = y;
    circle->r = r;
    return circle;
}

void destroy_circle(CIRCLE *to_destroy){
    free(to_destroy);
}

int main(void){
    CIRCLE *circles[5];
    circles[0] = new_circle(12, 3,0.5);
    circles[1] = new_circle(12, 3,1);
    circles[2] = new_circle(12, 3,1.5);

    printf("%p, %p, %p", circles[0], circles[1], circles[2]);
    destroy_circle(circles[0]);
    destroy_circle(circles[1]);
    destroy_circle(circles[2]);

}