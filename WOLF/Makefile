# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 12:22:29 by vtiterin          #+#    #+#              #
#    Updated: 2016/12/02 12:22:31 by vtiterin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= wolf3d
GCC		= gcc
WWW		= -Wall -Wextra -Werror
SRC		= main.c raycast_g.c raycast_v.c raycast.c rd_lvl.c keys1.c functions.c \
		skybox.c rd_tex.c lvl0.c lvl1.c lvl2.c keys2.c rd_tex1.c rd_tex2.c key1.c \
		key2.c t1_lvl1.c t2_lvl1.c t4_lvl1.c t3_lvl1.c rd_tc1.c lvl3.c rd_tc2.c \
		rd_tc3.c rd_tc4.c  
OBJ		= $(SRC:.c=.o)
LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft
SRCS 	= ./srcs/
INC		= ./includes/
IGRAPH  =   -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
            -framework AppKit

all: libft $(NAME)

%.o:$(SRCS)%.c
	$(GCC) $(LIBINC) -I $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ)
	$(GCC) $(IGRAPH) $(LIBLINK) -o $(NAME) $(OBJ)

clean: cleanlibft
	rm -rf $(OBJ)

cleanlibft:
	make clean -C ./libft 

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re: fclean all
