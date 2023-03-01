NAME = push_swap
SRCS = main.c argv_checking.c parsing.c swap.c checker.c push.c rotate.c algo.c utils.c utils2.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all : ${OBJS} ${NAME}

%.o : %.c
	$(CC) -c $< -o $@

${NAME} :
	${MAKE} bonus -C ./Libft 
	$(CC) $(OBJS) $(CFLAGS) ./Libft/libft.a -o ${NAME} -G3

clean:
	${RM} ${OBJS}
	make fclean -C ./Libft

fclean: clean
	${RM} ${NAME}

re: fclean all