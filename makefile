NAME = client server

C_FILES = client.c\
		  server.c\

SRCS = $(addprefix srcs/,$(C_FILES))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I include/ -g

LIB = libft/libft.a printf/libftprintf.a
DEPS = $(addprefix libs/,$(LIB))

all: ${NAME}

${NAME}: %: srcs/%.o ${DEPS}
	cc ${CFLAGS} $< -o $@ ${DEPS}

srcs/%.o: srcs/%.c
	cc ${CFLAGS} -c $< -o $@

${DEPS}:
	make -C libs/libft
	make -C libs/printf

clean:
	rm -f ${OBJS}
	make -C libs/libft clean
	make -C libs/printf clean

fclean: clean
	rm -f ${NAME}
	make -C libs/libft fclean
	make -C libs/printf fclean

re: fclean all

.PHONY: all clean fclean re
