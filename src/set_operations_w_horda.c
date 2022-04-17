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
        pis_mnozinu(list, list_length);
        swap(largest_index, root_index, list);
        pis_mnozinu(list, list_length);
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
        pis_mnozinu(list, list_length);
    }
    pis_mnozinu(list, list_length);
}

int main(void){
    int a[n] = {4, 2, 8, 4, 14, 12, 53, 13, 11, 9, 1, 10, 20};

    heap_sort(a,n);
}