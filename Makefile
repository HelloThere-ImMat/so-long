# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdorr <mdorr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 15:37:01 by mdorr             #+#    #+#              #
#    Updated: 2023/01/24 19:28:43 by mdorr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
		str_utils.c \
		get_next_line.c \
		get_next_line_utils.c

NAME	=	./so_long

OBJS	= 	${SRCS:.c=.o}

CC	= 	gcc


CFLAGS	= 	-Wall -Wextra -Werror


.c.o:

		${CC} -Imlx -c $< -o ${<:.c=.o}



all:	${OBJS}
	$(CC) $(OBJS) -I minilibx_linux/libmxl.a -L ./minilibx-linux -l mlx -lXext -lX11 -o $(NAME)



mac :	${OBJS}
	$(CC) $(OBJS) -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -f ${OBJS}


fclean:	clean
		rm -f ${NAME}


re:	fclean all

.PHONY : 	all clean fclean re
