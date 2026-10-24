CC=clang
BINARIES=main.o

all:
	$(CC) main.c -o main.o

debug:
	lldb ./main

clean:
	rm -f $(BINARIES)
