#include "vector.h"
#include <stdio.h>

void selection_sort(vector *v) {
    int n = v->size;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (getAt(v, j) < getAt(v, min_index)) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = getAt(v, i);
            v->arr[i] = getAt(v, min_index);
            v->arr[min_index] = temp;
        }
    }
}

void merge_sorted_vectors(vector *v1, vector *v2, vector *result) {
    int i = 0, j = 0;

    while (i < v1->size && j < v2->size) {
        if (getAt(v1, i) < getAt(v2, j)) {
            push(result, getAt(v1, i));
            i++;
        } else {
            push(result, getAt(v2, j));
            j++;
        }
    }

    while (i < v1->size) {
        push(result, getAt(v1, i));
        i++;
    }

    while (j < v2->size) {
        push(result, getAt(v2, j));
        j++;
    }
}


int main() {
    vector* v1 = init_vector(2);
    vector* v2 = init_vector(10);

    push(v1, 10);
    push(v1, 3);
    push(v1, 8);
    push(v1, 4);

    push(v2, 5);
    push(v2, 6);
    push(v2, -5);
    push(v2, 1);

    selection_sort(v1);
    selection_sort(v2);

    vector *result = init_vector(v1->size + v2->size);

    merge_sorted_vectors(v1, v2, result);

    print_vector(v1);
    print_vector(v2);
    print_vector(result);

    int sum = vectorSum(v1, 0);
    printf("Sum: %d\n", sum);

    allVectorSums(result, 0, 0);
    printf("\n");

    free_vector(v1);
    free_vector(v2);
    free_vector(result);
}