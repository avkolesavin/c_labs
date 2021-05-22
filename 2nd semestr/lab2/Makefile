DEPS=../utils.c ./list.c
PWD=$(shell PWD)
EXECUTABLE=$(shell basename "$(shell PWD)")

all: run

$(EXECUTABLE): $(EXECUTABLE).c $(DEPS)
	gcc $(EXECUTABLE).c $(DEPS) -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

leak: $(EXECUTABLE)
	valgrind ./$(EXECUTABLE)
