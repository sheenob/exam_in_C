# Nom du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g -fsanitize=address

# Fichiers objets
OBJS = main.o tree.o

# Fichier exécutable final
EXEC = test

# Règle principale pour compiler l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Règle pour compiler chaque fichier .o à partir des fichiers .c
main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c functions.h
	$(CC) $(CFLAGS) -c tree.c

# Commande pour nettoyer (supprimer) les fichiers objets et l'exécutable
clean:
	rm -f *.o $(EXEC)

# Commande pour recompiler tout (avec clean d'abord)
rebuild: clean $(EXEC)
