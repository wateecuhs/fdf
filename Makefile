# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 09:45:06 by panger            #+#    #+#              #
#    Updated: 2023/11/18 18:35:40 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config/srcs.mk

NAME=			fdf
CC=				cc
FLAGS=			-Wall -Wextra -Werror 
HEADER_DIR=		./includes/
HEADER=			$(HEADER_DIR)

MLX			=	minilibx/
MLX_A		=	$(MLX)libmlx.a

OBJS=$(SRCS:.c=.o)
OBJS_DIR=.objects/


all : $(NAME)

re: fclean all

%.o : %.c $(HEADER) ./minilibx/mlx.h
	$(CC) $(FLAGS) -I$(HEADER_DIR) -Iminilibx -c $< -o $@


$(NAME):		$(OBJS) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -lmlx -lm -o $(NAME)
#$(NAME): $(OBJS) $(HEADER_DIR)
#	$(CC) $(FLAGS) -I $(HEADER_DIR) -Lminilibx-linux -lminilibx-linux -Iminilibx-linux -lmlx -lXext -lX11 -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(NAME)

.PHONY: clean fclean all re