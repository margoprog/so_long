# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheraul <maheraul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 00:22:02 by maheraul          #+#    #+#              #
#    Updated: 2023/02/03 00:22:06 by maheraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

GNL				=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

LIBFT			=	libft.a

PRINTF			=	libftprintf.a

SRCS			=	srcs/parse_sl.c \
					srcs/parse_sl2.c \
					srcs/main.c \
					srcs/spread.c \
					srcs/basic_parse.c \
					srcs/ft_mlx.c \
					srcs/move.c \
					srcs/exit_access.c \
					srcs/put_image.c \
					srcs/annexe.c\
					srcs/end_game.c\

BONUS			=	bonus/parse_sl_bonus.c \
					bonus/parse_sl2_bonus.c \
					bonus/main.c \
					bonus/spread_bonus.c \
					bonus/basic_parse_bonus.c \
					bonus/ft_mlx_bonus.c \
					bonus/ft_farmer_move_bonus.c \
					bonus/move_bonus.c \
					bonus/intro_bonus.c \
					bonus/farmer_way_bonus.c \
					bonus/exit_access_bonus.c \
					bonus/put_image_bonus.c \
					bonus/put_logo_bonus.c\
					bonus/annexe_bonus.c\
					bonus/end_game_bonus.c\

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		=	${BONUS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-Iincludes/

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C libft
	@make -C ft_printf
	@mv libft/libft.a .
	@mv ft_printf/libftprintf.a .
	cc $(OBJS) $(HEAD) ${OBJS_GNL} mlx/libmlx.a mlx/libmlx_Linux.a -Lmlx/minilibx-linux -lXext -lmlx -lX11  ${LIBFT} ${PRINTF} -o $(NAME)

bonus			: $(OBJS_GNL) ${OBJS_BONUS}
	@make -C libft
	@make -C ft_printf
	@mv libft/libft.a .
	@mv ft_printf/libftprintf.a .
	cc $(OBJS_BONUS) $(HEAD) ${OBJS_GNL} mlx/libmlx.a mlx/libmlx_Linux.a -Lmlx/minilibx-linux -lXext -lmlx -lX11  ${LIBFT} ${PRINTF} -o $(NAME)

clean			:
					make clean -C libft
					make clean -C ft_printf
					rm -rf ${OBJS} ${OBJS_GNL} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					make fclean -C ft_printf
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus
