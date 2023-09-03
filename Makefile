NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -I -framework AppKit -framework OpenGL

SRCS 	=	utils/so_long.c \
			include/get_next_line/get_next_line_utils.c	\
			include/get_next_line/get_next_line.c \
			utils/check_map.c \
			utils/character_controller.c \
			include/ft_printf.c \
			utils/put_image.c \
			utils/map_validation.c utils/ft_itoa.c utils/enemy_controller.c utils/animation.c

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a
RED = '\033[0;31m'

all: ${NAME}

$(PRNTF): 
	@make -C ./printf

$(MINI):
	@make -C ./mlx

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
	@echo "\033[1;96mStarted Program\033[1;96m"

%.o: %.c
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)

fclean: clean
	@rm -rf ${NAME}
	@echo $(R)Removed [$(NAME)]$(B)
	@make clean -C mlx/

re: fclean all

.PHONY: fclean re all clean