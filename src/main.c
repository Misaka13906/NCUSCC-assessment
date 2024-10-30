#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include"../include/global.h"
#include"../include/const.h"

const int scale[6] = {
    1, 10, 100, 1000, 10000, 100000
};
int arr[N], a[N];
double t[4][6][1005];
int n;
int repeat = 10;

long test(int *arr, int n, void (*sort)(int*, int), char* name);

int main(int argc, char *argv[]) {
    srand(time(0));
    if(argc > 1) {
        puts(argv[1]);
        if(argv[1][10] == 'b') repeat = 6;
        else if(argv[1][10] == 'h') repeat = 500;
        else if(argv[1][10] == 'f') repeat = 10;
    } else {
        printf("args not found: %s", argv[0]);
    }
    
    for(int s=2; s<=5; s++) {
        n = scale[s];
        for(int r=1; r<=repeat; r++) {
            for(int i=1; i<=n; i++) {
                arr[i] = rand();
            }
            t[0][s][r] = test(arr, n, sort, argv[0]) *1.0/CLOCKS_PER_SEC;
            // t[0][s][r] = test(arr, n, fibHeapSort, "fibonacci heap sort") *1.0/CLOCKS_PER_SEC;
            // t[0][s][r] = test(arr, n, heapSort, "heap sort") *1.0/CLOCKS_PER_SEC;
            // t[0][s][r] = test(arr, n, bubbleSort, "bubble sort") *1.0/CLOCKS_PER_SEC;
        }
    }
    puts("---------------finished sorting----------------");
    char outputFile[50] = "./data/sort_time.csv";
    if(argc > 1) {
        strcpy(outputFile, argv[1]);
    } else {
        sprintf(outputFile, "%s.csv", argv[0]+8);
    }
    freopen(outputFile, "w", stdout);
    for(int s=2; s<=5; s++) {
        printf(",%d", scale[s]);
    }
    printf("\n\n");
    for(int r=1; r<=repeat; r++) {
        for(int s=2; s<=5; s++) {
            if(t[0][s][r] > 0)
                printf(",%.6lf", t[0][s][r]);
        }
        puts("");
    }
    fclose(stdout);
    return 0;
}

int check(int *a, int n) {
    for(int i=2; i<=n; i++)
        if(a[i] < a[i-1])
            return i;
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
    if(finish - start > 1000000 / 10) {
        printf("time used: %lfs\n", (double)(finish - start)/(CLOCKS_PER_SEC));
    }
    int failed = check(a, n);
    if(!failed) {
        // printf("test passed: %s\n", name);
    } else {
        printf("%s: failed at position %d\n", name, failed);
        return -1;
    }
    return (finish - start);
}