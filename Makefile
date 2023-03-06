# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:38:18 by rkhinchi          #+#    #+#              #
#    Updated: 2023/03/06 17:03:11 by rkhinchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
NAME	=
CLIENT	=	client
SERVER	=	server
	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

	# ft_printf Variables #
FT_PRINTF	=	./ft_printf/libftprintf.a
FT_PRINTF_DIR	=	./ft_printf


	# Mandatory Variables #
SRC_C	=	client.c
SRC_S	=	server.c
INC	=	-I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

	# Compiling Variables #
CC			=	gcc
CFLAG			=	-Wall -Wextra -Werror
RM			=	rm -f

	# Colors #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

	# Debugger #
ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

	# Fsanitize #
ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=leak -g
endif


all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT) $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRC_S) $(LIBFT) $(FT_PRINTF) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server is ready, my boss!\n"

$(CLIENT): $(LIBFT) $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRC_C) $(LIBFT) $(FT_PRINTF) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client is ready and waiting for your message to type!\n"


$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -s -C ./libft

$(FT_PRINTF):
	@ $(MAKE) DEBUG=$(DEBUG) -s -C ./ft_printf

clean:
	@ $(MAKE) clean -s -C $(LIBFT_DIR)
	@ $(MAKE) clean -s -C $(FT_PRINTF_DIR)
	@printf "$(_INFO) libft objects removed.\n"
	@printf "$(_INFO) ft_printf objects removed.\n"

fclean:
	@ $(MAKE) fclean -s -C $(LIBFT_DIR)
	@ $(MAKE) fclean -s -C $(FT_PRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
