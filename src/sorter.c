#include "sorter.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int *begin, int *end) {
    int *ptr;
    int *split;
    if (end - begin <= 1)
        return;
    ptr = begin;
    split = begin + 1;
    while (++ptr <= end) {
        if (*ptr < *begin) {
            swap(ptr, split);
            ++split;
        }
    }
    swap(begin, split - 1);
    quicksort(begin, split - 1);
    quicksort(split, end);
}

void mergesort(int *liste, int groesse) {

    if (groesse > 1) {

        int haelfte1[groesse / 2];
        int haelfte2[(groesse + 1) / 2];
        int i;
        for (i = 0; i < groesse / 2; ++i)
            haelfte1[i] = liste[i];
        for (i = groesse / 2; i < groesse; ++i)
            haelfte2[i - groesse / 2] = liste[i];

        mergesort(haelfte1, groesse / 2);
        mergesort(haelfte2, (groesse + 1) / 2);

        int *pos1 = &haelfte1[0];
        int *pos2 = &haelfte2[0];
        for (i = 0; i < groesse; ++i) {
            if (*pos1 <= *pos2) {
                liste[i] = *pos1;
                if (pos1 !=
                    &haelfte2[(groesse + 1) / 2 - 1]) { // pos1 nicht verändern, wenn der größte Wert mehrmals vorkommt
                    if (pos1 == &haelfte1[groesse / 2 - 1]) {
                        pos1 = &haelfte2[(groesse + 1) / 2 - 1];
                    }
                    else {
                        ++pos1;
                    }
                }
            }
            else {
                liste[i] = *pos2;
                if (pos2 == &haelfte2[(groesse + 1) / 2 - 1]) {
                    pos2 = &haelfte1[groesse / 2 - 1];
                }
                else {
                    ++pos2;
                }
            }
        }
    }
}

int main(int argc, const char **argv) {
    if (argc != 2) {
        printf("usage: sorter n\n");
        exit(1);
    }
    int size = atoi(argv[1]);
    //int list[size];
    int *list = (int *) malloc(size * sizeof(int));
    //initialize random generator
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        list[i] = rand();
    }

    //(list+(size-1)) == &list[size-1]
    quicksort(list, list + (size - 1));


    for (int i = 0; i < size; i++) {
        list[i] = rand();
    }
    //mergesort(list, size);

    printf("hi");


}
