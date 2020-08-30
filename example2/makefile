# App Name
TARGET=example2

# Compiler
CC=gcc

# Debug
DEBGUG=-g

# Optimization
OPT=-O0

# Warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# Linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o

clean:
	rm -rf *.o $(TARGET)
	rm -rf *~
	rm -rf src/*~
	rm -rf glade/*~
	rm -rf glade/*\#
