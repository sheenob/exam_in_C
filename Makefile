# Nom du compilateur / choix de gcc car c'est le compilateur C par défaut sur la plupart des systèmes
# GCC v.13.2.0
CC = gcc

# Options de compilation / WALL pour les avertissements / WEXTRA pour les avertissements supplémentaires / G pour le débogage / FSANITIZE pour la détection des fuites de mémoire
CFLAGS = -Wall -Wextra -g -fsanitize=address

# Fichiers objets
OBJS = main.o tree.o

# Fichier exécutable final
EXEC = test

# Règle principale pour compiler l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Règle pour compiler chaque fichier .o à partir des fichiers .c
main.o: main.c functions.h node.h
	$(CC) $(CFLAGS) -c main.c

tree.o: tree.c functions.h node.h
	$(CC) $(CFLAGS) -c tree.c

# Commande pour nettoyer (supprimer) les fichiers objets et l'exécutable
clean:
	rm -f *.o $(EXEC)

# Commande pour recompiler tout (avec clean d'abord)
rebuild: clean $(EXEC)
