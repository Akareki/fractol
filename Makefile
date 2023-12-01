# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoizel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 15:58:39 by aoizel            #+#    #+#              #
#    Updated: 2023/12/01 11:25:37 by aoizel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	fractol

LIBFTPRINTF		=	libftprintf/libftprintf.a

LIBFTPRINTF_DIR	=	libftprintf/

INCLUDES		=	-I. -I./minilibx-linux/ -L./minilibx-linux/ -lmlx -lXext -lX11

CFLAGS 			=	-Wall -Wextra -Werror

CC 				=	cc $(CFLAGS)

SOURCES 		=	main.c mandelbrot.c julia.c burning_ship.c tricorn.c utils.c \
					color.c hooks.c

OBJECTS 		=	$(SOURCES:.c=.o)

DEPENDENCIES	=	Makefile fractol.h get_next_line.h

MAKE			=	make --no-print-directory


all:		 
				$(MAKE) -C $(LIBFTPRINTF_DIR)
				cp $(LIBFTPRINTF) .
				$(MAKE) $(NAME)

$(NAME):		$(OBJECTS)
				$(CC) $(OBJECTS) -L. libftprintf.a $(INCLUDES) -o $(NAME)


%.o:		%.c $(DEPENDENCIES)
				$(CC) -c $(INCLUDES) $<

clean:
				$(MAKE) clean -C $(LIBFTPRINTF_DIR)
				rm -rf $(OBJECTS)

fclean:		clean
				$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
				rm -rf $(NAME) libftprintf.a

re:			fclean 
				make all

.PHONY: 	all clean fclean re
