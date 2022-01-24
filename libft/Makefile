# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 14:11:35 by khelegbe          #+#    #+#              #
#    Updated: 2021/06/25 19:40:06 by khelegbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror -g

NAME		=	libft.a

SRCS		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memccpy.c \
				ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
				ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
				ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
				ft_putstr.c ft_putchar.c ft_putnbr.c ft_utoa.c ft_convert_base.c \
				ft_convert_base2.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c

HEADERS		=	.

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				@${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@ar rc libft.a ${OBJECTS}
				@printf "\033[92mlibft compiled\n\033[0m"

clean:
				@rm -rf ${OBJECTS}

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
