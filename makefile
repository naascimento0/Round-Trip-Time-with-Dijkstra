CC = gcc
FILE = input/main_input.txt
EXEC = trab2

make:
	$(CC) -o $(EXEC) main.c source/*.c -lm

run:
	./$(EXEC)  $(FILE) 2
	
valgrind:
	valgrind --track-origins=yes ./$(EXEC)  $(FILE) 2
