NAME = fillit

SRC = main.c checkblock.c readnstore.c fillit.c square.c encode.c checkmove.c

LIBFT = libft.a

SRCO = $(SRC:.c=.o)

SRCH = fillit.h libft.h

SRCGH = $(SRCH:.h=.h.gch)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
		@${CC} -I ${SRCH} -c ${SRC} ${CFLAGS}
		@${CC} ${SRCO} -o ${NAME} ${LIBFT}

.PHONY: clean fclean

clean:
		rm -f ${SRCO}
		rm -f ${SRCGH}

fclean: clean
		rm -f ${NAME}

re: fclean all
