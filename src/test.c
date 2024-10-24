#include<stdio.h>
#include<time.h>
#include"../include/const.h"
int a[N];

int check(int *a, int n) {
    for(int i=2; i<=n; i++)
        if(a[i] < a[i-1])
            return i-1;
    return 0;
}

long test(int *arr, int n, void (*sort)(int*, int), char* name) {
    for(int i=1; i<=n; i++) {
        a[i] = arr[i];
    }
    long start, finish;
    start = clock();
    sort(a, n);
    finish = clock();
    // printf("time used: %lfs\n", (double)(finish - start)/(CLOCKS_PER_SEC));
    int res = check(a, n);
    if(!res) {
        // printf("test passed: %s\n", name);
    } else {
        printf("failed at position %d\n", res);
        return -1;
    }
    return (finish - start);
}