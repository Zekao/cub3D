# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 20:05:12 by nabentay          #+#    #+#              #
#    Updated: 2022/03/06 22:58:35 by emaugale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = gcc
INCLUDE = mandatory/include
INCLUDE_B = bonus/include
CFLAGS = -Werror -Wextra -Wall -g -I/usr/include -Imlx_linux
DEBUG = -g
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -rf

FILES = cub3D 						\
		mlx/init_mlx				\
		math/math_utils				\
		RayCasting/raycasting		\
		RayCasting/raycasting_utils	\
		RayCasting/raycasting_utils2\
		get_next_line/get_next_line	\
		memory/memory0				\
		memory/memory1				\
		parsing/check_content		\
		parsing/create_map			\
		parsing/utils_parsing		\
		parsing/check_name			\
		parsing/check_textures		\
		parsing/adjust_map			\
		parsing/start_direction		\
		parsing/get_size_map		\
		draw/functions				\
		mlx/command					\
		textures/create_textures	\

FILES_B = cub3D 					\
		mlx/init_mlx				\
		mlx/mouse					\
		math/math_utils				\
		minimap/minimap				\
		RayCasting/raycasting		\
		RayCasting/raycasting_utils	\
		RayCasting/raycasting_utils2\
		get_next_line/get_next_line	\
		memory/memory0				\
		memory/memory1				\
		parsing/check_content		\
		parsing/create_map			\
		parsing/utils_parsing		\
		parsing/check_name			\
		parsing/check_textures		\
		parsing/adjust_map			\
		parsing/start_direction		\
		parsing/get_size_map		\
		draw/functions				\
		mlx/command					\
		textures/create_textures	\

SRCS_DIR = ./mandatory/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

BONUS_DIR = ./bonus/
BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_B_DIR = ./objs_b/
OBJS_B = $(addprefix $(OBJS_B_DIR), $(addsuffix .o, $(FILES_B)))

OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDE)
		@echo "$(GREEN)************ $< COMPILED SUCESSFULLY$(RST)"

$(NAME): $(OBJS)
		@make -C libft all --no-print-directory
		@make -C libft bonus --no-print-directory
		@make -C mlx_linux --no-print-directory
		@$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ $^ $(MLXFLAGS) libft/libft.a
		@echo "$(GREEN)************ $@ SUCESS$(RST)"
		@echo "$(CYAN)┌────────────────────────────────────┐$(RST)"
		@echo "$(CYAN)│             cub3D                  │$(RST)"
		@echo "$(CYAN)│ Authors                            │$(RST)"
		@echo "$(CYAN)│                                    │$(RST)"
		@echo "$(CYAN)│ Elidjah Maugalem                   │$(RST)"
		@echo "$(CYAN)│ Naofel Bentayeb                    │$(RST)"
		@echo "$(CYAN)└────────────────────────────────────┘$(RST)"

$(OBJS_DIR):
		@mkdir $@
		@mkdir $@/memory
		@mkdir $@/math
		@mkdir $@/RayCasting
		@mkdir $@/parsing
		@mkdir $@/get_next_line
		@mkdir $@/draw
		@mkdir $@/mlx
		@mkdir $@/textures
		@echo "$(GREEN)************ OBJS FOLDER CREATED$(RST)"

$(OBJS_B_DIR):
		@mkdir $@
		@mkdir $@/memory
		@mkdir $@/math
		@mkdir $@/RayCasting
		@mkdir $@/parsing
		@mkdir $@/get_next_line
		@mkdir $@/draw
		@mkdir $@/mlx
		@mkdir $@/minimap
		@mkdir $@/textures
		@echo "$(GREEN)************ OBJS FOLDER CREATED$(RST)"

$(OBJS_B_DIR)%.o: $(BONUS_DIR)%.c
		@$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDE_B)
		@echo "$(GREEN)************ $< COMPILED SUCESSFULLY$(RST)"

debug: $(OBJS_DIR) $(OBJS)
		@make -C libft all --no-print-directory
		@make -C libft bonus --no-print-directory
		@$(CC) $(DEBUG) -I $(INCLUDE) -o $(NAME) $(OBJS) $(LFLAGS) libft/libft.a
		@echo "$(YELLOW)**/ DEBUG MODE (wo/ flags w/ -g) \**$(RST)"


bonus: $(OBJS_B_DIR) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_B)
		@make -C libft all --no-print-directory
		@make -C libft bonus --no-print-directory
		@make -C mlx_linux --no-print-directory
		@$(CC) $(CFLAGS) -I $(INCLUDE_B) -o $@ $^ $(MLXFLAGS) libft/libft.a
		@echo "$(GREEN)************ $@ SUCESS$(RST)"
		@echo "$(CYAN)┌────────────────────────────────────┐$(RST)"
		@echo "$(CYAN)│             cub3D                  │$(RST)"
		@echo "$(CYAN)│ Authors                   BONUS    │$(RST)"
		@echo "$(CYAN)│                                    │$(RST)"
		@echo "$(CYAN)│ Elidjah Maugalem                   │$(RST)"
		@echo "$(CYAN)│ Naofel Bentayeb                    │$(RST)"
		@echo "$(CYAN)└────────────────────────────────────┘$(RST)"

clean:
		@make -C libft clean --no-print-directory
		@make -C mlx_linux clean --no-print-directory
		@$(RM) $(OBJS_DIR) $(OBJS_B_DIR)
		@echo "$(GREEN)************ OBJS DELETE SUCESS$(RST)"

fclean: clean
		@rm -f $(NAME)
		@rm -f $(BONUS_NAME)
		@rm -f libft/libft.a
		@echo "$(GREEN)************ $(NAME) DELETE SUCESS$(RST)"

re: clean all

.PHONY: bonus all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RST = \033[0m
