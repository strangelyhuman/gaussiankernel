#This is a makefile for the kernel program

CC=gcc

CFLAGS=-o
LDFLAGS=-lm

OBJS= main.o kernel.o kernel.h
VAR1=cat

kernel.o: kernel.c kernel.h
	$(CC) kernel.c -c $(LDFLAGS)

main.o: main.c kernel.h
	$(CC) main.c -c $(LDFLAGS)

main: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) main $(LDFLAGS)