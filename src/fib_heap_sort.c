#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#define max(a, b) (a > b ? (a) : (b))
#define N 100005
#define lgN 25
const int INF = 1e9;

typedef struct node {
    struct node *left, *right, *parent, *child;
    int value, rank, degree;
} node;

typedef struct Heap {
    node *minRoot;
} Heap;

Heap heap;
node pool[N];
int cnt = 0;

void insert(node *bro, node *newNode) {
    if(bro == newNode) {
        return;
    }
    puts("before insert");
    newNode->left = bro;
    newNode->right = bro->right;
    bro->right->left = newNode;
    bro->right = newNode;
    printf("insert [%ld](%d) beside [%ld](%d)\n", newNode - pool, newNode->value, bro - pool, bro->value);
}

void insertValue(int value) {
    pool[++cnt].value = value;
    pool[cnt].rank = 0;
    // pool[cnt].parent = NULL;
    if(heap.minRoot == NULL) {
        heap.minRoot = &pool[cnt];
        pool[cnt].left = &pool[cnt];
        pool[cnt].right = &pool[cnt];
    }
    insert(heap.minRoot, &pool[cnt]);
    // update
    if(value < heap.minRoot->value) {
        heap.minRoot = &pool[cnt];
    }
}

node* rankRoot[lgN];
// rank <= lg n

void merge(node *par, node *chi) {
    puts("before merge");
    chi->parent = par;
    par->degree ++;
    par->rank = max(par->rank, par->degree);
    // delete "chi" from original linked list
    chi->left->right = chi->right;
    chi->right->left = chi->left;

    if(par->child == NULL) {
        par->child = chi;
        chi->right = chi;
    }
    puts("before insert in merge");
    insert(par->child, chi);
}

void consolidate(node *now) {
    puts("before consolidate");
    if(rankRoot[now->rank] == NULL) {
        rankRoot[now->rank] = now;
        printf("new: rank = %d\n", now->rank);
    } else {
        printf("conflict: rank = %d,  merge %ld & %ld\n", now->rank, now-pool, rankRoot[now->rank]-pool);
        if(rankRoot[now->rank]->value < now->value) {
            merge(rankRoot[now->rank], now);
        } else {
            merge(now, rankRoot[now->rank]);
            rankRoot[now->rank] = now;
        }
    }
    puts("after consolidate");
}

bool deleteMin() {
    if(heap.minRoot == NULL) {
        return false;
    }
    node *oldMinRoot = heap.minRoot;
    // merge children into root list
    puts("merge children into root list");
    if(oldMinRoot->child != NULL) {
        insert(oldMinRoot, oldMinRoot->child);
        for(node *now = oldMinRoot->child->right; now != oldMinRoot->child; now = now->right) {
            insert(oldMinRoot, now);
        }
    }
    // delete old min root
    puts("delete old min root");
    oldMinRoot->left->right = oldMinRoot->right;
    oldMinRoot->right->left = oldMinRoot->left;
    // update min root
    puts("update min root");
    heap.minRoot = oldMinRoot->right;
    for(node *now = oldMinRoot->right->right; now != oldMinRoot->right; now = now->right) {
        if(now->value < heap.minRoot->value) {
            printf("old: %d, new: %d\n", heap.minRoot->value, now->value);
            heap.minRoot = now;
        }
    }
    // Consolidate trees so that no two roots have same rank
    puts("Consolidate trees so that no two roots have same rank");
    for(int i=0; i<lgN; i++) {
        rankRoot[i] = NULL;
    }
    node *now = heap.minRoot;
    consolidate(now);
    for(node *now = heap.minRoot->right; now != heap.minRoot; now = now->right) {
        consolidate(now);
    }
    return true;
}

void fibHeapSort(int *a, int n) {
    for(int i=1; i<=n; i++) {
        insertValue(a[i]);
    }
    puts("finished insert");
    for(int i=1; i<=n; i++) {
        printf("%d ", heap.minRoot->value);
        deleteMin();
    }
}


int main() {
    int n = 9;
    int a[10] = {0, 4, 2, 8, 5, 7, 1, 9, 3, 6};
    //  a[10] = {0, 100, 5, 3, 11, 33, 6, 8, 7};
    fibHeapSort(a, n);
    for(int i=1; i<=n; i++)
        printf("%d%c", a[i], " \n"[i==n]);
}
