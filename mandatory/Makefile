SRCS_SERVER ?= server.c \
			   utils.c 

SRCS_CLIENT ?= client.c \
			   utils.c \
			   send_informations.c

OBJS_SERVER ?= ${SRCS_SERVER:.c=.o}

OBJS_CLIENT ?= ${SRCS_CLIENT:.c=.o}

NAME_SERVER ?= server

NAME_CLIENT ?= client

COMPILER ?= clang

RM		?= rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= libft/libft.a \
		  libft/ft_printf/libftprintf.a \

.c.o:		${OBJS_SERVER} ${OBJS_CLIENT} 
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}:	${OBJS_SERVER}
			make -C libft
			${COMPILER} ${CFLAGS} ${OBJS_SERVER} -o ${NAME_SERVER} ${LIBRARY}

${NAME_CLIENT}:	${OBJS_CLIENT}
			make -C libft
			${COMPILER} ${CFLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT} ${LIBRARY}

clean: 
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 
			make -C libft clean

fclean: 	clean
			${RM} ${NAME_SERVER} ${NAME_CLIENT}
			make -C libft fclean

re:
			make fclean
			make

norm:
			norminette client.c send_informations.c server.c minitalk.h utils.c libft

.PHONY: 	all bonus clean fclean re norm
