all: word_scrambler
clean:
	@echo "Cleaning"
	@rm word_scrambler main.o

word_scrambler: main.o
	@echo "Linking: main.o"
	@gcc -o word_scrambler main.o
	@echo "Done"

main.o: main.c
	@echo "Compiling: main.c"
	@gcc -c -o main.o main.c
	@echo "Done"
