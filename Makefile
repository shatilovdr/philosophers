#PHILOSOPHERS_PROJECT_MAKEFILE
NAME				:=	philo

CC					:=	cc
FLAGS				:=	-Wall -Wextra -Werror -g

#######COLORS_FOR_MESSAGES
GREEN				=	\033[32m
GREY				=	\033[90m
EC					=	\033[0m

###############################
#########START_SOURCES#########
###############################

# #####AST_TREE_CREATION#####
# AST_TREE_NAME		:=	create_tree.c add_nodes.c constructors.c constructors_2.c create_node.c \
# 						free_tree.c
# AST_TREE_PATH		:=	ast/ast_create_tree/
# AST_TREE			:=	$(addprefix $(AST_TREE_PATH), $(AST_TREE_NAME))


SRCS				:=	main.c
SRCS_PATH			:=	srcs/

###############################
##########END_SOURCES##########
###############################

OBJS_PATH			:=	objs/
OBJS				:=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) 
	@cc $(FLAGS) $(OBJS)  -o $(NAME)
	@echo "$(GREEN)\n---------------> $(NAME) created successfully! <---------------$(EC)"

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(GREEN)*.o files removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)All files removed!$(EC)"

re: fclean all