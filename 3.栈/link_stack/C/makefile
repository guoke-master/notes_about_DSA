test: test.c link_stack.o link_list.o
	gcc -E test.c -o test.i
	gcc -S test.i -o test.s
	gcc -c test.s -o test.o
	gcc -g test.c link_stack.o link_list.o -o test

link_stack.o: link_stack.c
	gcc -E link_stack.c -o link_stack.i
	gcc -S link_stack.i -o link_stack.s
	gcc -g -c link_stack.c -o link_stack.o

link_list.o: link_list.c
	gcc -E link_list.c -o link_list.i
	gcc -S link_list.i -o link_list.s
	gcc -g -c link_list.c -o link_list.o

clean:
	rm *.i *.s *.o test
