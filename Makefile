CC=clang
CFLAGS=-Wall -Wextra -std=c17 -g
SRC=src/main.c
OUT=stockmon

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
