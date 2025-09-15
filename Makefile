CC 			= 	cc
FLAGS		=	-g -Wall -Wextra -Werror
INCS		=	-Iinc										\
				-Ilibft/inc
SRC_DIR		=	src
OBJ_DIR		=	build
SRCS		=	clean.c										\
				errors.c									\
				main.c										\
				run_processes.c								\
				set_structs.c
SRC_FILES	=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIBFT		=	-Llibft -lft
NAME		=	pipex

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

