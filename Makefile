CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	so_long

NAME_BONUS		=	so_long_bonus

LD_FLAGS		=	-L mlx

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

SRCS		=	srcs/main.c srcs/utils.c srcs/utils_mem.c srcs/utils_checkmap.c \
				srcs/utils2.c srcs/engine.c srcs/engine2.c srcs/moves.c

SRCS_BONUS	=	srcs/main.c srcs/utils.c srcs/utils_mem.c srcs/utils_checkmap.c \
				srcs/utils2.c srcs/engine_bonus.c srcs/engine2_bonus.c srcs/moves_bonus.c

HEADERS		=	-I includes -I libft -I mlx

LIB			=	-lft -L libft

LIBFT_PATH	=	libft

LIBFT		=	${LIBFT_PATH}/libft.a

OBJECTS		=	${SRCS:.c=.o}

OBJECTS_BONUS	=	${SRCS_BONUS:.c=.o}

all:			$(NAME)

.c.o:
				${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@make -C libft
				@make -C mlx
				@${CC} ${CFLAGS} ${OBJECTS} ${HEADERS} ${LIB} ${LIBFT} -o ${NAME} ${LD_FLAGS} ${MLX_FLAGS}
				@printf "\033[92mso_long compiled\n\033[0m"

bonus:			${OBJECTS_BONUS}
				@make -C libft
				@make -C mlx
				@${CC} ${CFLAGS} ${OBJECTS_BONUS} ${HEADERS} ${LIB} ${LIBFT} -o ${NAME_BONUS} ${LD_FLAGS} ${MLX_FLAGS}
				@printf "\033[92mso_long compiled\n\033[0m"

clean:
				@make clean -C ${LIBFT_PATH}
				@make clean -C mlx
				@rm -rf ${OBJECTS}
				@rm -rf ${OBJECTS_BONUS}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@make fclean -C ${LIBFT_PATH}
				@rm -rf $(NAME)
				@rm -rf $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re bonus
