# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 16:30:17 by huakbas           #+#    #+#              #
#    Updated: 2024/11/29 14:57:56 by huakbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Wextra -Werror

SRCFILES := ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c\
ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c\
ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c\
ft_strlen.c ft_strrchr.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c\
ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c\
ft_get_const.c ft_printf_handle_uint.c ft_printf_set_flags.c ft_printf_handle_char.c\
ft_itobase_uint.c ft_printf_set_zeropadded_str.c ft_printf_handle_convertion.c\
ft_itobase_ul.c ft_printf_handle_int.c ft_printf.c ft_printf_handle_pointer.c\
ft_printf_handle_string.c ft_printf_set_flagged_str.c get_next_line.c get_next_line_utils.c

BONUSFILES := ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c\
ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c

OBJECTFILES := $(SRCFILES:.c=.o)

BONUSOBJECTFILES := $(BONUSFILES:.c=.o)

NAME := libft.a

BONUSCHECK = checkbonus

all: ${NAME} clean

bonus: ${BONUSCHECK}

${NAME}: ${OBJECTFILES}
	@ar rcs $@ ${OBJECTFILES}

${OBJECTFILES}: ${SRCFILES}
	@cc -g -c $(CFLAGS) ${SRCFILES}

${BONUSCHECK}: ${NAME} ${BONUSFILES}
	@cc -g -c $(CFLAGS) ${BONUSFILES}
	@ar rs ${NAME} ${BONUSOBJECTFILES}
	touch ${BONUSCHECK}

clean:
	@rm -f ${OBJECTFILES} ${BONUSOBJECTFILES} ${BONUSCHECK}

fclean: clean
	rm -f $(NAME)
	
re: fclean all

show:
	ar -tv ${NAME}

.PHONY: all clean fclean re show val
