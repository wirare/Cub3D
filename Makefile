include Sources.mk
NAME			:= Cub3d

DIR_LIB			:= lib
DIR_HEADERS     := headers
DIR_SOURCES     := srcs
DIR_OBJS        := .objs

DIR_MLX         := $(DIR_LIB)/MacroLibX
MLX_INCLUDES    := $(DIR_MLX)/includes
MLX             := $(DIR_MLX)/libmlx.so

DIR_LIBFT		:= $(DIR_LIB)/libft
LIBFT_INCLUDES	:= $(DIR_LIBFT)/headers
LIBFT			:= $(DIR_LIBFT)/libft.a

OBJS            := $(addprefix $(DIR_OBJS)/, $(CUB3D_SOURCES:%.c=%.o))

CC              := cc
DEBUG_FLAG		:= -g -DSLOW
GPROF			:= -pg
OPT_FLAGS	    := -O3 -mfma -march=native -mtune=native -funroll-loops -fvectorize -ffp-contract=fast  -freciprocal-math -ffast-math -fstrict-aliasing -flto=full -mprefer-vector-width=256 -fomit-frame-pointer
CFLAGS          := -Wall -Wextra -Werror -mavx2 #$(OPT_FLAGS)
IFLAGS          := -I $(DIR_HEADERS) -I $(MLX_INCLUDES) -I $(LIBFT_INCLUDES)

PURPLE			 = \033[0:35m
GREEN            = \033[0;32m
RED              = \033[0;31m
END              = \033[0m
DIR_DUP          = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(IFLAGS) -lm -lSDL2 $(OBJS) -o $(NAME) $(MLX) $(LIBFT)
	@printf "$(GREEN)$(NAME) compiled$(END)\n"

$(MLX):
	$(MAKE) -C $(DIR_MLX) --no-print-directory -j

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT) --no-print-directory -j

clean:
	@rm -rf $(DIR_OBJS)
	@printf "$(RED)$(NAME) cleaned objs$(END)\n"
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(DIR_MLX) fclean
	@printf "$(RED)$(NAME) removed$(END)\n"
	$(MAKE) -C $(DIR_LIBFT) fclean
	@printf "$(RED)LIBFT removed$(END)\n"

re: fclean all

rebuild:
	@rm -rf $(DIR_OBJS)
	@rm -f $(NAME)
	@$(MAKE) all

debug:	
	@rm -rf $(DIR_OBJS)
	@rm -f $(NAME)
	@$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_FLAG)" all

.PHONY: clean fclean re all rebuild
