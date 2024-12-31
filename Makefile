CFLAGS := -Wall -Wextra -Werror

LIBFT := libft
LIBFTCHECK := libcheck
 
SRC := utils.c ft_atoi_base.c
OBJ := $(SRC:.c=.o)

NAME := server
CLIENT := client

all: ${NAME}
	@-./${NAME}
#	@-./${CLIENT}

${NAME}: ${OBJ} ${LIBFTCHECK} ${NAME}.c ${CLIENT}.c
	@-cc -g ${CFLAGS} ${OBJ} ${CLIENT}.c -L ${LIBFT} -lft -o ${CLIENT}
	@-cc -g ${CFLAGS} ${OBJ} ${NAME}.c -L ${LIBFT} -lft -o ${NAME}

${OBJ}: ${SRC}
	@- cc -g -c ${CFLAGS} ${SRC}

${LIBFTCHECK}:
	@- ${MAKE} -C ${LIBFT} bonus clean
	touch ${LIBFTCHECK}

b : bonus
bonus :

c : clean
clean:
#@ ${MAKE} -C ${LIBFT} clean --- it s already cleaned after creating archive 
	@- rm -f ${OBJ} checker.o push_swap.o

f : fclean
fclean: clean
	@ ${MAKE} -C ${LIBFT} fclean
	rm -f ${NAME} ${LIBFTCHECK} ${CLIENT}

re: fclean all bonus

val: all
	@valgrind -q --vgdb-error=0 --xml=yes --leak-check=yes --show-leak-kinds=all ./${NAME}

fun: all
	@funcheck ${NAME}

.PHONY: all bonus clean fclean re val fun