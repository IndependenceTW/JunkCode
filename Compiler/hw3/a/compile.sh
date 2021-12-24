bison -d -o stack_base.tab.c stack_base.y
flex -o stack_base.yy.c stack_base.l
gcc -c -g -I.. stack_base.tab.c
gcc -c -g -I.. stack_base.yy.c
gcc -o stack_base stack_base.tab.o stack_base.yy.o -ll
