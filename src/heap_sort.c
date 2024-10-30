// #include"../include/global.h"

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *a, int n) {
    for(int i=2; i<=n; i++) {
        for(int j=i; j > 1 && a[j] > a[j/2]; j /= 2) {
            Swap(&a[j], &a[j/2]);
        }
    }
    for(int i=n; i>1; i--) {
        Swap(&a[1], &a[i]);
        for(int j=1; j*2 < i; ) {
            int next;
            if(j*2+1 < i && a[j*2+1] > a[j*2]) {
                next = j*2+1;
            } else {
                next = j*2;
            }
            if(a[next] < a[j]) {
                break;
            }
            Swap(&a[j], &a[next]);
            j = next;
        }
    }
}
