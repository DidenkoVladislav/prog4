CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = bitrgbled.c matrix2d.c contqueue.c fioqueue.c main.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o main.out
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./main.out save -t test.txt
	valgrind --leak-check=full --show-leak-kinds=all ./main.out load -t test.txt
	valgrind --leak-check=full --show-leak-kinds=all ./main.out save -b test.bin
	valgrind --leak-check=full --show-leak-kinds=all ./main.out load -b test.bin
	valgrind --leak-check=full --show-leak-kinds=all ./main.out get -t 1 test.txt
	valgrind --leak-check=full --show-leak-kinds=all ./main.out get -b 1 test.bin
	valgrind --leak-check=full --show-leak-kinds=all ./main.out list -t test.txt
	valgrind --leak-check=full --show-leak-kinds=all ./main.out list -b test.bin
save_t:
	./main.out save -t test.txt
load_t:
	./main.out load -t test.txt >res.txt
save_b:
	./main.out save -b test.bin
load_b:
	./main.out load -b test.bin >res.txt
get_t:
	./main.out get -t 1 test.txt >res.txt
get_b:
	./main.out get -b 1 test.bin >res.txt
list_t:
	./main.out list -t test.txt >res.txt
list_b:
	./main.out list -b test.bin >res.txt
test_funcs:
	./main.out save -t test.txt
	./main.out load -t test.txt
	./main.out save -b test.bin
	./main.out load -b test.bin
	./main.out get -t 1 test.txt
	./main.out get -b 1 test.bin
	./main.out list -t test.txt
	./main.out list -b test.bin
