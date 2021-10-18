test: test.c seq_queue.o seq_list.o
	gcc -g -E test.c -o test.i
	gcc -g -S test.i -o test.s
	gcc -g -c test.s -o test.o
	gcc -g test.o seq_queue.o seq_list.o -o test

seq_queue.o: seq_queue.c
	gcc -g -E seq_queue.c -o seq_queue.i
	gcc -g -S seq_queue.i -o seq_queue.s
	gcc -g -c seq_queue.s -o seq_queue.o

seq_list.o: seq_list.c
	gcc -g -E seq_list.c -o seq_list.i
	gcc -g -S seq_list.i -o seq_list.s
	gcc -g -c seq_list.s -o seq_list.o

clean: 
	rm *.i *.s *.o test
