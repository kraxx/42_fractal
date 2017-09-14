# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 22:34:31 by jchow             #+#    #+#              #
#    Updated: 2017/06/21 22:34:32 by jchow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		fractol

SRC = 		main \
			draw \
			fractals \
			fractals2 \
			init \
			key_hooks \
			key_f_pointers \
			key_f_pointers2 \
			key_f_pointers3 \
			key_f_pointers4 \
			key_f_pointers5 \
			key_f_pointers6 \
			key_f_pointers7 \
			key_f_pointers8 \
			key_f_pointers9 \
			loop_hooks \
			mouse_f_pointers \
			mouse_hooks \
			pulsers \
			set_colour \
			set_colour2 \
			transformations \

SRC_DIR = 	src/
SRC_FILES =	$(addsuffix .c, $(SRC))
SRCS =		$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR =	obj/
OBJ_FILES =	$(addsuffix .o, $(SRC))
OBJS =		$(addprefix $(OBJ_DIR), $(OBJ_FILES))

LFT_DIR =	libft/
LFT_FILES =	libft.a
LFTS =		$(addprefix $(LFT_DIR), $(LFT_FILES))

MLX =		minilibx/libmlx.a
MLX_FLAGS =	-L minilibx -lmlx -framework OpenGL -framework AppKit

HDR_DIR =	-I includes -I libft/includes -I minilibx/
HDR_FILES =	includes/$(addsuffix .h, $(NAME)) includes/keys.h

C_FLAGS =	-Wall -Wextra -Werror

RED =				[31m
GREEN =				[32m
BLUE =				[34m
YELLOW =			[33m
MAGENTA =			[35m
GREY =				[37m
GREEN_LIGHT =		[92m
YELLOW_LIGHT =		[93m
YELLOW_BOLD =		[1;33m
YELLOW_LIGHT_BOLD =	[1;93m
MAGENTA_LIGHT =		[95m
BLINK =				[5m
GREEN_LIGHT_BLINK =	[5;92m
END_COLOUR =		\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(LFTS) $(MLX)
	@echo "$(YELLOW)Compiling $(NAME)...$(END_COLOUR)"
	@gcc $(C_FLAGS) $(MLX_FLAGS) -lpthread $^ -o $@
	@echo "$(GREEN)Successfully compiled $(NAME)!$(END_COLOUR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR_FILES)
	@mkdir -p obj
	@gcc $(C_FLAGS) $(HDR_DIR) -c $< -o $@

$(LFTS): force
	@make -C $(LFT_DIR)

$(MLX): force
	@make -C minilibx

force:
	@true

clean:
	@echo "$(YELLOW)Cleaning objects...$(END_COLOUR)"
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning library objects...$(END_COLOUR)"
	@make clean -C $(LFT_DIR) && make clean -C minilibx
	@echo "$(GREEN)Successfully cleaned all objects!$(END_COLOUR)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(END_COLOUR)"
	@/bin/rm -f $(NAME)
	@echo "$(YELLOW)Cleaning libraries...$(END_COLOUR)"
	@make fclean -C $(LFT_DIR)
	@echo "$(GREEN)Successfully cleaned everything!$(END_COLOUR)"

re:	fclean all

.PHONY: all force clean fclean re