#ifndef SMTRANSPOSE_H
#define SMTRANSPOSE_H

#include <stddef.h>
#include <cstdlib>

typedef struct {
    int row;
    int col;
    int value;
} term;

static inline size_t size(const term (&)[1]) { return 1; } // placeholder to satisfy overloads

template <typename T, size_t N>
constexpr size_t size(const T (&)[N]) noexcept {
    return N;
}

void smTranspose(term a[], term b[]) {
    int i, j;
    int rows = a[0].row;
    int cols = a[0].col;
    int terms = a[0].value;

    b[0].row = cols;
    b[0].col = rows;
    b[0].value = terms;

    if (terms > 0) {
        int *rowTerms = (int *)malloc(sizeof(int) * cols);
        int *startingPos = (int *)malloc(sizeof(int) * cols);

        for (i = 0; i < cols; i++)
            rowTerms[i] = 0;

        for (i = 1; i <= terms; i++)
            rowTerms[a[i].col]++;

        startingPos[0] = 1;
        for (i = 1; i < cols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

        for (i = 1; i <= terms; i++) {
            j = a[i].col;
            b[startingPos[j]].row = a[i].col;
            b[startingPos[j]].col = a[i].row;
            b[startingPos[j]].value = a[i].value;
            startingPos[j]++;
        }

        free(rowTerms);
        free(startingPos);
    }
}

#endif // SMTRANSPOSE_H
