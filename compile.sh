
gcc -c src/bubble_sort.c -O0 -o bin/sort/bubble_sort_o0.o
gcc -c src/bubble_sort.c -O1 -o bin/sort/bubble_sort_o1.o
gcc -c src/bubble_sort.c -O2 -o bin/sort/bubble_sort_o2.o
gcc -c src/bubble_sort.c -O3 -o bin/sort/bubble_sort_o3.o
gcc -c src/bubble_sort.c -Ofast -o bin/sort/bubble_sort_ofast.o

gcc -c src/heap_sort.c -O0 -o bin/sort/heap_sort_o0.o
gcc -c src/heap_sort.c -O1 -o bin/sort/heap_sort_o1.o
gcc -c src/heap_sort.c -O2 -o bin/sort/heap_sort_o2.o
gcc -c src/heap_sort.c -O3 -o bin/sort/heap_sort_o3.o
gcc -c src/heap_sort.c -Ofast -o bin/sort/heap_sort_ofast.o

gcc -c src/fib_heap_sort.c -O0 -o bin/sort/f_heap_sort_o0.o
gcc -c src/fib_heap_sort.c -O1 -o bin/sort/f_heap_sort_o1.o
gcc -c src/fib_heap_sort.c -O2 -o bin/sort/f_heap_sort_o2.o
gcc -c src/fib_heap_sort.c -O3 -o bin/sort/f_heap_sort_o3.o
gcc -c src/fib_heap_sort.c -Ofast -o bin/sort/f_heap_sort_ofast.o


gcc bin/sort/bubble_sort_o0.o src/test.c src/main.c -O1 -o bin/out/bubble_sort_o0.out
gcc bin/sort/bubble_sort_o1.o src/test.c src/main.c -O1 -o bin/out/bubble_sort_o1.out
gcc bin/sort/bubble_sort_o2.o src/test.c src/main.c -O1 -o bin/out/bubble_sort_o2.out
gcc bin/sort/bubble_sort_o3.o src/test.c src/main.c -O1 -o bin/out/bubble_sort_o3.out
gcc bin/sort/bubble_sort_ofast.o src/test.c src/main.c -O1 -o bin/out/bubble_sort_ofast.out

gcc bin/sort/heap_sort_o0.o src/test.c src/main.c -O1 -o bin/out/heap_sort_o0.out
gcc bin/sort/heap_sort_o1.o src/test.c src/main.c -O1 -o bin/out/heap_sort_o1.out
gcc bin/sort/heap_sort_o2.o src/test.c src/main.c -O1 -o bin/out/heap_sort_o2.out
gcc bin/sort/heap_sort_o3.o src/test.c src/main.c -O1 -o bin/out/heap_sort_o3.out
gcc bin/sort/heap_sort_ofast.o src/test.c src/main.c -O1 -o bin/out/heap_sort_ofast.out

gcc bin/sort/f_heap_sort_o0.o src/test.c src/main.c -O1 -o bin/out/f_heap_sort_o0.out
gcc bin/sort/f_heap_sort_o1.o src/test.c src/main.c -O1 -o bin/out/f_heap_sort_o1.out
gcc bin/sort/f_heap_sort_o2.o src/test.c src/main.c -O1 -o bin/out/f_heap_sort_o2.out
gcc bin/sort/f_heap_sort_o3.o src/test.c src/main.c -O1 -o bin/out/f_heap_sort_o3.out
gcc bin/sort/f_heap_sort_ofast.o src/test.c src/main.c -O1 -o bin/out/f_heap_sort_ofast.out


gcc record/main.c -o bin/record.out
