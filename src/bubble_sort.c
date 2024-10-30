// #include"../include/global.h"

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *a, int n) {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n-i; j++)
            if(a[j] > a[j+1])
                Swap(&a[j], &a[j+1]);
}
