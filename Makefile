CC=clang
BINARIES=main.o

main:
	$(CC) main.c -o main.o

debug:
	lldb ./main.o

clean:
	rm -f $(BINARIES)
