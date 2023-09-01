##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## make lib
##


SRC     =   my_putstr.c     \
            my_putchar.c    \
            my_strlen.c    \
            my_strcat.c    \
            my_put_nbr.c    \
            my_strcmp.c   \
            mini_printf.c   \
            my_strcpy.c     \
            my_atoi.c    \
            my_str_is_alpha.c   \
            my_strncmp.c    \
            my_strncpy.c    \
            my_strdup.c     \

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all: $(NAME)

$(NAME):        $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@echo -e "\e[1;32mmysh lib compilated\e[0m"

clean:
	@rm -f $(NAME)
	@rm -f *.o
	@rm -f lib/my/*.o

fclean: clean
	@rm -f libmy.a
	@rm -f ../libmy.a
