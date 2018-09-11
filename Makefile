NAME		= fdf
SRCS		=	main.c \
				get_next_line.c \
				get_map.c \
				rotation.c \
				parse_map.c \
				key_hooks.c \
				scale_map.c \
				ft_new_list.c \
				color.c \
				out_error.c \
				read_map.c \

SRCO		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
MLX			= -lmlx -framework OpenGL -framework Appkit
LIBS		= libft/libft.a minilibx_macos/libmlx.a
DIR = obj
SRC = $(SRCS)
OBJ = $(addprefix $(DIR)/,$(SRCO))

all: $(NAME)


$(NAME): $(LIBS) $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIBS) $(MLX)

obj/%.o: %.c
	@mkdir -p $(DIR)
	@gcc -c $(FLAGS) -o $@ -c $<


$(LIBS):

	@make -C libft
	@make -C minilibx_macos



clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@make -C minilibx_macos clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
	