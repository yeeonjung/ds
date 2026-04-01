#ifndef LISTS_H
#define LISTS_H

#define MAX 100

int insertElement(int list[], int size, int element) {
    int i, pos = size;
    int moveCount = 0;

    for (i = 0; i < size; i++) {
        if (list[i] > element) {
            pos = i;
            break;
        }
    }

    for (i = size; i > pos; i--) {
        list[i] = list[i - 1];
        moveCount++;
    }

    list[pos] = element;
    return moveCount;
}

int deleteElement(int list[], int size, int element) {
    int i, pos = -1;
    int moveCount = 0;

    for (i = 0; i < size; i++) {
        if (list[i] == element) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return size;
    }

    for (i = pos; i < size - 1; i++) {
        list[i] = list[i + 1];
        moveCount++;
    }

    return moveCount;
}

#endif // LISTS_H
