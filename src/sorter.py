import random
import sys
import time


def create_rand_list(size):
    return random.sample(range(size * 1000), size)


def quicksort(a):
    if len(a) <= 1:
        return a
    pivot = a[0]
    return quicksort([x for x in a if x < pivot]) \
           + [x for x in a if x == pivot] \
           + quicksort([x for x in a if x > pivot])


def mergesort(a):
    len_a = len(a)
    if len_a == 1:
        return a
    elif len_a == 0:
        print('ERROR!!!!')
        exit(1)
    else:
        return merge(mergesort(a[:(len_a // 2)]), mergesort(a[(len_a // 2):]))


def merge(a, b):
    len_a = len(a)
    len_b = len(b)
    merged_list = [0] * (len_a + len_b)
    i, k, l = 0, 0, 0
    while k < len_a and l < len_b:
        if a[k] <= b[l]:
            merged_list[i] = a[k]
            k += 1
        else:
            merged_list[i] = b[l]
            l += 1
        i += 1
    if k == len_a:
        merged_list[i:] = b[l:]
    if l == len_b:
        merged_list[i:] = a[k:]
    return merged_list


def main():
    if len(sys.argv) != 2:
        print('sorter.py n')
    size = int(sys.argv[1])
    randlist = create_rand_list(size)

    # print(randlist)
    t0 = time.time()
    foo = quicksort(randlist)
    t1 = time.time()
    print('Quicksort of {} elements takes {} seconds'.format(size, t1 - t0))

    t0 = time.time()
    bar = mergesort(randlist)
    t1 = time.time()
    print('Mergesort of {} elements takes {} seconds'.format(size, t1 - t0))

    for i in range(size):
        if foo[i] != bar[i]:
            print('Error')


if __name__ == "__main__":
    main()
