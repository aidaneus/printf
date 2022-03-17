NAME		= libftprintf.a
SRCS		= ft_printf.c ft_printf_utils.c parse.c parse_2.c ft_printf_utils_2.c print.c print_2.c
			
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Werror -Wextra -Wall
.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.
$(NAME) :	${OBJS}
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)
so :        
			${CC} -shared -o ${OBJS}
all :		$(NAME)
clean :
			rm -f ${OBJS} ${OBJS_B}
fclean :	clean
			rm -f $(NAME)
re :		fclean all
.PHONY:		all clean fclean  re 
