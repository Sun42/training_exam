NAME = inter
CC = gcc
SRC = inter.c
OBJ = $(SRC:.c=.o)
CFLAGS += -ansi -pedantic -w -Wall
RM = `rm -f`

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean : $(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(NAME)