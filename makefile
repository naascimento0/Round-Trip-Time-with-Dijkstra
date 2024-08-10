CC = gcc
INPUT = input/N10_S3_C3_M3.txt
OUTPUT = saida.txt
EXEC = trab2

all: object compile

object:
	mkdir -p objects
	gcc -g -c main.c source/*.c source/data_structures/*.c -Iheaders && mv *.o objects/

compile:
	gcc -o $(EXEC) objects/*.o -lm

run:
	@./$(EXEC)  $(INPUT) $(OUTPUT)
	
valgrind:
	@valgrind --track-origins=yes --leak-check=full -s ./$(EXEC)  $(INPUT) $(OUTPUT)

clean:
	rm -r $(EXEC) objects
