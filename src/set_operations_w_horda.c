//
// Created by Timur Kramar on 17/04/2022.
//

//parent[i] := i-1/2
//child[i] := i*2 + 1(2)
#define n 13

#include "stdio.h"

void pis_mnozinu(int *list, unsigned int list_length){
    for (int i = 0; i < list_length; i++){
        printf("%d\t", list[i]);
    }
    printf("\n");
}

void swap(unsigned int i, unsigned int j, int *list) {
    int aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}

void remove_element(int *list, unsigned int *list_length, unsigned int index){
    for(int i = index + 1; i < *list_length; i++){
        list[i-1] = list[i];
    }
}

void remove_duplicates(int *list, unsigned int *list_length){
    for(int i = 0; i < &list_length; i++){

    }
}

void heapify_node(int *list, unsigned int list_length, unsigned int root_index){
    unsigned int largest_index = root_index;
    unsigned int child1 = root_index*2 + 1;
    unsigned int child2 = root_index*2 + 2;

    // Porovnaj ho s deťmi, najväčšie nechaj pod largest
    if (child1 < list_length && list[child1] > list[largest_index]){
        largest_index = child1;
    }
    if (child2 < list_length && list[child2] > list[largest_index]){
        largest_index = child2;
    }
            // Ak nejaké dieťa je väčšie, vymeň ho s rodičom
            // a pokračuj v heapify o level hlbšie
    if (largest_index != root_index) {
//        pis_mnozinu(list, list_length);
        swap(largest_index, root_index, list);
//        pis_mnozinu(list, list_length);
        heapify_node(list, list_length, largest_index);
    }
}

void heap_sort(int *list, unsigned int list_length){
    // Konvertuj na heap
    // stačí začať od rodiča poslednej, čiže n/2-1
    for (unsigned int i = list_length/2 - 1; i < list_length; i--) {
        heapify_node(list, list_length, i);
    }
    swap(0, list_length-1, list);

    // Postupne vždy uprac heap a daj najväčšie na koniec
    for (unsigned int i = list_length-1; i > 1; i--){
        heapify_node(list, i,0);
        swap(0, i-1, list);
//        pis_mnozinu(list, list_length);
    }
//    pis_mnozinu(list, list_length);
}

void Union(int *a, int *b, int *c, unsigned int a_l, unsigned int b_l){
    unsigned int c_l = a_l + b_l;
    for (unsigned int i = 0; i < a_l; i++){
        c[i] = a[i];
    }
    for (unsigned int i = a_l; i < c_l; i++){
        c[i] = b[i-a_l];
    }
    pis_mnozinu(c,c_l);
}

void Intersection(int *a, int *b, int *d, unsigned int a_l, unsigned int b_l){
    heap_sort(a,a_l);
    heap_sort(b,b_l);
}

int main(void){
    unsigned int a_l = 5;
    unsigned int b_l = 7;
    unsigned int c_l = 12;
    unsigned int d_l = 7;

    int a[5] = {4, 2, 8, 4, 14};
    int b[7] = {6, 2, 16, 3, 9, 11, 7};
    int c[5+7];
    int d[7];
    heap_sort(a, a_l);
    heap_sort(b,b_l);
    pis_mnozinu(a,a_l);
    remove_element(a, &a_l, 2);
    pis_mnozinu(a,a_l);
//    pis_mnozinu(b,b_l);
//    pis_mnozinu(c,c_l);
//    Union(a,b,c,a_l,b_l);
//    pis_mnozinu(c,c_l);
//    Intersection(a,b,d,a_l,b_l);
}