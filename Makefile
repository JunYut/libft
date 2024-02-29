# Directories
LIBFT_DIR = libft/
FT_PRINTF_DIR = ft_printf/
OBJ_DIR = obj/

# Target
LIBFT = $(LIBFT_DIR)libft.a
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a
NAME = libft.a

# Rules & Recipes
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	ar rc $(NAME) $(OBJ_DIR)*.o

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re: fclean all

# PHONY rules
.PHONY: all clean fclean re
