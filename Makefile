##
## EPITECH PROJECT, 2022
## TEK1_22-23
## File description:
## Makefile
##

SRC	=	src/my_str_to_word_array.c	\
		src/parther.c	\
		src/errors_handling.c	\
		src/cd.c	\
		src/generic_function.c	\
		src/set_env.c	\
		src/unset_env.c	\
		src/manage_struct.c	\
		src/my_realloc.c    \
		src/my_memcpy.c	\
		src/exec_binary.c	\
		src/env_manage.c	\
		src/parth_getline.c	\
		src/array_of_function_pointer.c	\
		src/set_args.c	\
		src/check_semicolons.c		\

LIB_UT	=	lib/my/mini_printf.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_atoi.c	\
			lib/my/my_str_is_alpha.c	\
			lib/my/my_strcat.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_strncpy.c	\
			lib/my/my_strdup.c	\
			lib/my/my_strncmp.c	\

NAME	=	mysh

UT_NAME	=	unit_tests

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L./lib/ -lmy

LIB     =       libmy.a

CFLAGS +=  -Wall -Wextra -I./include

CFLAGS	+=	-Wall -Wextra

CRIT	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) main.c $(SRC) $(LDFLAGS) $(CFLAGS)

$(LIB):
	make -C lib/my

debug:	CFLAGS	+= -g3
debug:	all

test_run:
	gcc -o $(UT_NAME) $(SRC) tests/*.c $(LIB_UT) $(CRIT) $(LDFLAGS) $(CFLAGS)
	./$(UT_NAME)

clean:
	@rm -f $(NAME)
	@rm -f *.o
	@rm -f lib/my/*.o
	@rm -f lib/my/libmy.a
	@find -name "vgcore.*" -delete
	@rm -f *~
	@echo -e "\e[1;32mMake clean in mysh\e[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(UT_NAME)
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f lib/libmy.a
	@rm -f src/*.o
	@rm -f lib/my/*.o
	@echo -e "\e[1;32mMake Fclean in mysh\e[0m"

re:     fclean all

.PHONY: all clean fclean re
