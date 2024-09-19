term : first.o
	gcc -o term first.o
first.o : first.c
	gcc -c first.c 
