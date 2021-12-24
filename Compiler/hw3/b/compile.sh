bison -d -o matrix.tab.c matrix.y
flex -o matrix.yy.c matrix.l
gcc -c -g -I.. matrix.tab.c
gcc -c -g -I.. matrix.yy.c
gcc -o matrix matrix.tab.o matrix.yy.o -lfl
