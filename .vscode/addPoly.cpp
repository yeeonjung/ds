#include <stdio.h>
#include "addPoly.h"

polynomial addPoly(polynomial A, polynomial B) {
    polynomial C;
    int i;
    C.degree = (A.degree > B.degree) ? A.degree : B.degree;

    for (i = 0; i <= C.degree; i++)
        C.coef[i] = 0.0f;

    for (i = 0; i <= A.degree; i++)
        C.coef[i] += A.coef[i];

    for (i = 0; i <= B.degree; i++)
        C.coef[i] += B.coef[i];

    while (C.degree > 0 && C.coef[C.degree] == 0.0f)
        C.degree--;

    return C;
}

void printPoly(polynomial P) {
    int i;
    int first = 1;

    for (i = P.degree; i >= 0; i--) {
        if (P.coef[i] == 0.0f)
            continue;

        if (!first) {
            if (P.coef[i] > 0)
                printf("+");
        }

        if (i == 0)
            printf(" %.1f", P.coef[i]);
        else if (i == 1)
            printf(" %.1fx", P.coef[i]);
        else
            printf(" %.1fx^%d", P.coef[i], i);

        first = 0;
    }

    if (first)
        printf(" 0");
}
