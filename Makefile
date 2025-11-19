NAME    = so_long
CC      = cc -g
CFLAGS  = -Wall -Wextra -Werror

INCS_COMMON   = -Iinclude -Iminilibx-linux
INCS_LIBFT    = -Ilibft -Ilibft/includes
INCS_PRINTF   = -Ift_printf
INCS          = $(INCS_COMMON) $(INCS_LIBFT) $(INCS_PRINTF)

SRC     =  src/check_in.c \
           src/render_map.c \
           src/get_next_line.c \
           src/hooks.c \
           src/images.c \
           src/main.c \
           src/parse_map.c \
           src/init.c \
           src/exit_error.c \
		   src/check_map_accsess.c

OBJ_DIR = obj
OBJ     = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ---- libft ----
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

# ---- ft_printf (AYRI DİZİN) ----
FT_PRINTF_DIR = ft_printf
# Çoğu repoda çıktı adı budur. Senin repoda farklıysa (örn. libftprintf.a değilse)
# alttaki ismi kendi çıktına göre değiştir:
FT_PRINTF     = $(FT_PRINTF_DIR)/libftprintf.a

# ---- MiniLibX ----
MLX_DIR   = minilibx-linux
MLX_AR    = $(MLX_DIR)/libmlx_Linux.a
MLX_LIBS  = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# ---- Targets ----
all: $(NAME)

# Link: obje + libft + ft_printf + mlx
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_AR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX_LIBS) -o $(NAME)

# Objeleri derle
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Alt projeleri derle
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(MLX_AR):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
