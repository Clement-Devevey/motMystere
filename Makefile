# Variables to control Makefile operation
 
CC = /usr/bin/g++
CFLAGS = -Wall -g
main = mot_mystere
func = fonctions

# ****************************************************
all: mot_mystere

$(main): $(main).o $(func).o
	$(CC) $(CFLAGS) -o $(main) $(main).o $(func).o
 
$(main).o: $(main).cpp
	$(CC) $(CFLAGS) -c $(main).cpp

$(func).o: $(func).cpp
	$(CC) $(CFLAGS) -c $(func).cpp

clean:
	$(RM) $(main)
