all: bind clean
	clear

bind: compile_bison compile_flex
	gcc -o bc bc.tab.o lex.yy.o -ll
	
compile_bison:
	bison -d bc.y
	gcc -c bc.tab.c

compile_flex:
	flex bc.l
	gcc -c ./lex.yy.c

clean:
	@rm ./*.c
	@rm ./*.h
	@rm ./*.o
	clear