GDB_FLAG = 

test: test.c link_queue.o link_list.o
	gcc $(GDB_FLAG) -E test.c -o test.i
	gcc $(GDB_FLAG) -S test.i -o test.s
	gcc $(GDB_FLAG) -c test.s -o test.o
	gcc $(GDB_FLAG) test.o link_queue.o link_list.o -o test

link_queue.o: link_queue.c
	gcc $(GDB_FLAG) -E link_queue.c -o link_queue.i
	gcc $(GDB_FLAG) -S link_queue.i -o link_queue.s
	gcc $(GDB_FLAG) -c link_queue.s -o link_queue.o

link_list.o: link_list.c
	gcc $(GDB_FLAG) -E link_list.c -o link_list.i
	gcc $(GDB_FLAG) -S link_list.i -o link_list.s
	gcc $(GDB_FLAG) -c link_list.s -o link_list.o

clean:
	rm *.i *.s *.o test

