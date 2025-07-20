CC = gcc
CFLAGS = -Wall -std=c99
OBJ = main.o temp_api.o

all: app

app: $(OBJ)
	$(CC) $(CFLAGS) -o app $(OBJ)

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c temp_api.c

clean:
	rm -f *.o app.*