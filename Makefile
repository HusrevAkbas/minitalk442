CFLAGS := -Wall -Wextra -Werror

LIBFT := libft
LIBFTCHECK := libcheck
 
SRC := utils.c
OBJ := $(SRC:.c=.o)

NAME := server
CLIENT := client

all: ${NAME}
	@-./${NAME}

${NAME}: ${OBJ} ${NAME}.c
	@-cc -g ${CFLAGS} ${OBJ} ${NAME}.c -o ${NAME}

${OBJ}: ${SRC}
	@- cc -g -c ${CFLAGS} ${SRC}

#${LIBFTCHECK}:
#	@- ${MAKE} -C ${LIBFT} bonus clean
#	touch ${LIBFTCHECK}

${CLIENT}: ${OBJ} ${CLIENT}.c
	@-cc -g ${CFLAGS} ${OBJ} ${CLIENT}.c -o ${CLIENT}

bonus :

clean:
#@ ${MAKE} -C ${LIBFT} clean --- it s already cleaned after creating archive 
	@- rm -f ${OBJ} checker.o push_swap.o

fclean: clean
#	@ ${MAKE} -C ${LIBFT} fclean
	rm -f ${NAME} ${LIBFTCHECK} ${BONUSNAME}

re: fclean all bonus

val: all
	@valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ./${NAME}

fun: all
	@funcheck ${NAME}

.PHONY: all bonus clean fclean re val fun