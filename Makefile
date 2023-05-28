SRCS_SERVER := srcs/mandatory/server.c \
			   srcs/mandatory/utils.c 

SRCS_CLIENT := srcs/mandatory/client.c \
			   srcs/mandatory/utils.c \
			   srcs/mandatory/send_informations.c

OBJS_SERVER := ${SRCS_SERVER:.c=.o}

OBJS_CLIENT := ${SRCS_CLIENT:.c=.o}

NAME_SERVER := server

NAME_CLIENT := client

SRCS_SERVER_BONUS := srcs/bonus/server_bonus.c \
			   srcs/bonus/utils_bonus.c 

SRCS_CLIENT_BONUS := srcs/bonus/client_bonus.c \
			   srcs/bonus/utils_bonus.c \
			   srcs/bonus/send_informations_bonus.c

OBJS_SERVER_BONUS := ${SRCS_SERVER_BONUS:.c=.o}

OBJS_CLIENT_BONUS := ${SRCS_CLIENT_BONUS:.c=.o}

NAME_SERVER_BONUS := server_bonus

NAME_CLIENT_BONUS := client_bonus

COMPILER ?= clang

RM		:= rm -f

CFLAGS 	:= -Wall -Werror -Wextra -g

LIBRARY := includes/libraries/libft/libft.a \
		  includes/libraries/libft/ft_printf/libftprintf.a \

.c.o:		 
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}:	${OBJS_SERVER}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${OBJS_SERVER} -o ${NAME_SERVER} ${LIBRARY}

${NAME_CLIENT}:	${OBJS_CLIENT}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT} ${LIBRARY}

	
bonus: 		${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

${NAME_SERVER_BONUS}:	${OBJS_SERVER_BONUS}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${OBJS_SERVER_BONUS} -o ${NAME_SERVER_BONUS} ${LIBRARY}

${NAME_CLIENT_BONUS}:	${OBJS_CLIENT_BONUS}
			make -C includes/libraries/libft
			${COMPILER} ${CFLAGS} ${OBJS_CLIENT_BONUS} -o ${NAME_CLIENT_BONUS} ${LIBRARY}

clean: 
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}
			make -C includes/libraries/libft clean

fclean: 	clean
			${RM} ${NAME_SERVER} ${NAME_CLIENT} ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}
			make -C includes/libraries/libft fclean

re:
			make fclean
			make

.PHONY: 	all bonus clean fclean re
