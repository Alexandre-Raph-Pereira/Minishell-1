##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	reallocation.c 			\
		my_strcmp.c 			\
		setenv.c 				\
		my_str_to_word_array.c 	\
		my_strcat.c 			\
		env_copy.c 				\
		unsetenv.c 				\
		cd_function.c 			\
		pwd_gestion.c 			\
		exec_gestion.c 			\
		exec_function.c 		\
		env_function.c 			\
		free_function.c 		\

SRC_TEST 	= tests/unit_tests.c     \


OBJ	=	$(SRC:.c=.o)

OBJ_TEST	= 	$(SRC_TEST:.c=.o)

NAME	=	mysh

NAME_T  =       unit_tests

CC	=	gcc -g3

CFLAGS  =       -I./include/ -L./lib/ -lmy -L./ -Wall -Wextra

FLAG_T  =       --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) main.c $(CFLAGS)

tests_run: $(OBJ_TEST)
			make re
			gcc -o $(NAME_T) $(SRC) $(SRC_TEST) $(CFLAGS) $(FLAG_T)
			./$(NAME_T)

clean:
		rm -f *.o
		rm -f tests/*.o
		make clean -C lib/

fclean:		clean
		rm -f $(NAME)
		make fclean -C lib/

tclean:		fclean
		rm -f $(NAME_T)
		rm -f *gcno
		rm -f *gcda

re:		fclean all
		make re -C lib/

