NAME = cub3d

CC= gcc

CFLAGS= -Wall -Wextra -Werror

SRC= cub3d.c parse_file.c

OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

GNL= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -D BUFFER_SIZE=1

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	echo "Libft done"
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(GNL) $(OBJ)
	echo "Compilation done"

clean:
	@cd libft && make clean
	@rm -f $(OBJ)
	@echo "Clean done"

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re