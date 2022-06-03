documents = $(wildcard docs/html/*)

All: main Doc

main: main.o Cell.o CellList.o Random.o
	gcc main.o Cell.o CellList.o Random.o -o main

%.o: %.c 
	gcc -c $^ -o $@

Doc: $(documents)
	doxygen Doxyfile

clean: 
	rm *.o
	rm -r docs/*


