# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/22 19:33:48 by ebaudet           #+#    #+#              #
#    Updated: 2014/05/22 19:44:33 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= irc

SERVEUR	= serveur
F_SRV	= main.c init_env.c clean_fd.c get_opt.c x.c main_loop.c \
		init_fd.c do_select.c check_fd.c \
		srv_create.c srv_accept.c \
		client_read.c client_write.c
SRC_SRV	= $(addprefix srcs_serveur/, $(F_SRV))
OBJ_SRV	= $(SRC_SRV:srcs_serveur/%.c=.obj_serveur/%.o)

CLIENT	= client
F_CLT	= main.c
SRC_CLT	= $(addprefix srcs_client/, $(F_CLT))
OBJ_CLT	= $(SRC_CLT:srcs_client/%.c=.obj_client/%.o)

INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(SERVEUR) $(CLIENT)

$(SERVEUR): make_libft $(OBJ_SRV)
	$(CC) $(FLAGS) $(OBJ_SRV) -o $(SERVEUR) $(INC) $(LIB)

$(CLIENT): make_libft $(OBJ_CLT)
	$(CC) $(FLAGS) $(OBJ_CLT) -o $(CLIENT) $(INC) $(LIB)

.obj_client/%.o: srcs_client/%.c
	@mkdir -p .obj_client
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

.obj_serveur/%.o: srcs_serveur/%.c
	@mkdir -p .obj_serveur
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

make_libft:
	@echo "Compilation de la libft :"
	@make -C libft

clean:
	rm -rf .obj_client
	rm -rf .obj_serveur

fclean: clean
	rm -f $(SERVEUR) $(CLIENT)

re: fclean all

gdb: make_libft
	cc -g $(FLAGS) $(SRC_SRV) -o $(SERVEUR) $(INC) $(LIB)
	cc -g $(FLAGS) $(SRC_CLT) -o $(CLIENT) $(INC) $(LIB)

.PHONY: all clean fclean re gdb
