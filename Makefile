SRCS		= push_swap.c parsing_arg.c print.c\
			small_stack.c sort_stack.c\
			stack_operations_1.c stack_operations_2.c\
			stack_utils.c

SRCS_BONUS	= checker_bonus.c checker_utils_bonus.c \
			parsing_arg.c print.c\
			small_stack.c sort_stack.c\
			stack_operations_1.c stack_operations_2.c\
			stack_utils.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME_BONUS	= checker

NAME		= push_swap

CC			= gcc

FLAGS		= -g -Wall -Wextra -Werror

LIBS        = libft/libft.a

HEADER		= push_swap.h

HEADER_BONUS	= checker.h

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS} ${HEADER}
			$(MAKE) libft.a -C ./libft libft.a
			$(CC) ${FLAGS} $(OBJS) $(LIBS) -o $(NAME)

bonus:		${OBJS_BONUS} ${HEADER_BONUS} 
			$(MAKE) libft.a -C ./libft libft.a
			$(CC) ${FLAGS} $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)

clean:
		${MAKE} clean -C ./libft
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean:	clean
		${MAKE} fclean -C ./libft
		rm -rf ${NAME} ${NAME_BONUS}

re:		fclean all

.PHONY:	all clean fclean re 
