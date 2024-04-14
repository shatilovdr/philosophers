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

#####HELPERS#####
HELPERS_NAME		:=	ft_calloc.c ft_memset.c ft_isspace.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_atoi.c \
						ft_isdigit.c
HELPERS_PATH		:=	helpers/
HELPERS				:=	$(addprefix $(HELPERS_PATH), $(HELPERS_NAME))


SRCS				:=	main.c check_args.c check_arg.c $(HELPERS)
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
	@mkdir -p $(OBJS_PATH)$(HELPERS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(GREEN)*.o files removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)All files removed!$(EC)"

re: fclean all