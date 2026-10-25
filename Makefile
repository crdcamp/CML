CC      = clang
CFLAGS  = -Wall -Wextra -g
SOURCES = main.c load_csv.c
TARGET  = main

.PHONY: all debug clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

debug: $(TARGET)
	lldb ./$(TARGET)

clean:
	rm -f $(TARGET)
