# Variables to control Makefile operation
 
CC = /usr/bin/g++
CFLAGS = -Wall -g
main = mot_mystere
func = fonctions

# ****************************************************
all: mot_mystere

$(main): fichiers_objets/$(main).o fichiers_objets/$(func).o
	$(CC) $(CFLAGS) -o $(main) fichiers_objets/$(main).o fichiers_objets/$(func).o
 
fichiers_objets/$(main).o: $(main).cpp
	$(CC) $(CFLAGS) -c $(main).cpp
	mv $(main).o fichiers_objets/

fichiers_objets/$(func).o: $(func).cpp
	$(CC) $(CFLAGS) -c $(func).cpp
	mv $(func).o fichiers_objets/

clean:
	$(RM) $(main)
