vpath %.h
vpath %.c
OBJECTS = main.o tools.o box.o lights.o wave.o
CC = gcc
CFLAGS = -lGL -lGLU -lglut -Wall

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)
main.o : main.c tools.h box.h lights.h wave.h
box.o : box.h global.h
lights.o : lights.h global.h
wave.o : wave.h global.h
tools.o : tools.h global.h

.PHONY : clean
	-rm *.o
