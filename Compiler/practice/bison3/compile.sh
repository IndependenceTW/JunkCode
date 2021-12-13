bison -d -o ex3.tab.c ex3.y
gcc -c -g -I.. ex3.tab.c
flex -o ex3.yy.c ex3.l
gcc -c -g -I.. ex3.yy.c
gcc -o ex3 ex3.tab.o ex3.yy.o -ll
