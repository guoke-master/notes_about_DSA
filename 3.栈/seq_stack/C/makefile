test: test.c seq_stack.o
	gcc -E test.c -o test.i
	gcc -S test.i -o test.s
	gcc -c test.s -o test.o
	gcc seq_list.o seq_stack.o test.o -o test

seq_stack.o: seq_stack.c seq_list.o
	gcc -E seq_stack.c -o seq_stack.i
	gcc -S seq_stack.i -o seq_stack.s
	gcc -c seq_stack.s -o seq_stack.o

seq_list.o: seq_list.c
	gcc -E seq_list.c -o seq_list.i
	gcc -S seq_list.i -o seq_list.s
	gcc -c seq_list.s -o seq_list.o

clean:
	rm *.i *.s *.o test
