all: bind clean
	clear

bind: compile_bison compile_flex
	gcc -o a a.tab.o lex.yy.o -ll
	
compile_bison:
	bison -d a.y
	gcc -c a.tab.c

compile_flex:
	flex a.l
	gcc -c ./lex.yy.c

clean:
	@rm ./*.c
	@rm ./*.h
	@rm ./*.o
	clear