# Makefile

CC = gcc
CFLAGS = -O2 -Wall -Iheader -L. -lraylib -lopengl32 -lgdi32 -lwinmm
SRC = main.c $(wildcard /body/clue.c body/kata.c body/linkedlist.c body/log.c body/menu.c body/pairkata.c body/player.c body/queue.c body/stack.c body/tree.c body/ui.c body/vote.c)
OBJ = $(SRC:.c=.o)
OUT = IntrudeMe.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	del /q *.o *.exe

