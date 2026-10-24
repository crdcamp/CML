CC=clang
BINARIES=main.o

main:
	$(CC) main.c simple_linear_regression.c -o main.o

debug:
	lldb ./main

clean:
	rm -f $(BINARIES)
