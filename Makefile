# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samirza <samirza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 15:54:18 by samirza           #+#    #+#              #
#    Updated: 2023/12/11 21:23:22 by samirza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

PRINTF 		= ft_printf/libftprintf.a
PRINTF_DIR 	= ft_printf

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_SERVER = server.c sources.c

SRCS_CLIENT = client.c sources.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): all

bonus: all

clean:
	$(MAKE) clean -C ./ft_printf
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT) $(NAME)

re: fclean all
