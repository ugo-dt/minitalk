# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 14:00:28 by ugdaniel          #+#    #+#              #
#    Updated: 2021/06/22 16:22:33 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OSTYPE = $(shell uname)

white = \033[39m
green = \033[92m
cyan = \033[96m
magenta = \033[35m
lmagenta = \033[95m
yellow = \033[33m
gray = \033[37m
red = \033[91m
blue = \033[94m

CLIENT = client
SRCS_CLIENT = $(wildcard srcs/client/*.c srcs/utils/*.c)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SERVER = server
SRCS_SERVER = $(wildcard srcs/server/*.c srcs/utils/*.c)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = @clang
FLAGS = -Wall -Werror -Wextra
HEADERS = -I srcs/

all: $(CLIENT) $(SERVER)
	@echo "$(green)Minitalk ready!"
	@echo "$(white)\c"

.c.o:
	@echo "$(gray)Compiling $<... \c"
	@echo "$(red)\c"
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "$(cyan)OK!"

$(CLIENT): $(OBJS_CLIENT)
	@echo "$(yellow)Client: source files compiled"
	@echo "$(red)\c"
	$(CC) $(FLAGS) -o $(CLIENT) $(OBJS_CLIENT)
	@echo "$(blue)Client ready!"
	@echo "$(white)\c"

clean_client:
	@echo "$(gray)Cleaning client object files"
	@echo "$(red)\c"
	@rm -f $(OBJS_CLIENT) $(OBJS_CLIENT_BONUS)

fclean_client: clean_client
	@rm -f $(CLIENT)
	@echo "$(lmagenta)Client executable removed"
	@echo "$(red)\c"

re_client: fclean_client $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@echo "$(yellow)Server: source files compiled"
	@echo "$(red)\c"
	$(CC) $(FLAGS) -o $(SERVER) $(OBJS_SERVER)
	@echo "$(blue)Server ready!"
	@echo "$(white)\c"

clean_server:
	@echo "$(gray)Cleaning server object files"
	@echo "$(red)\c"
	@rm -f $(OBJS_SERVER) $(OBJS_SERVER_BONUS)

fclean_server: clean_server
	@rm -f $(SERVER)
	@echo "$(lmagenta)Server executable removed"
	@echo "$(red)\c"

clean: clean_client clean_server

fclean: fclean_client fclean_server

re_server: fclean_server $(SERVER)

re: fclean all

.PHONY: all clean_client fclean_client re_client clean_server fclean_server clean fclean re_server re