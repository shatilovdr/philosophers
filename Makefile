# PHILOSOPHERS_PROJECT_MAKEFILE
NAME			:=	philo

# COMPILER
CC				:=	cc
FLAGS			:=	-Wall -Wextra -Werror -g

# COLORS
GREEN			:=	\033[32m
RED				:=	\033[41m
EC				:=	\033[0m

# HELPERS
HELPERS_NAME	:=	ft_calloc.c ft_atoi.c ft_isdigit.c ft_isspace.c
HELPERS_PATH	:=	helpers/
HELPERS			:=	$(addprefix $(HELPERS_PATH), $(HELPERS_NAME))

# PHILO
PHILO_NAME		:=	main.c init_table.c check_args.c check_arg.c init_destroy_mutexes.c free_table.c \
					run_simulation.c run_philosopher.c get_timestamp.c is_ready.c run_monitor.c
PHILO_PATH		:=	philo/
PHILO			:=	$(addprefix $(PHILO_PATH), $(PHILO_NAME))

# SOURCE_FILES
SRCS			:=	$(PHILO) $(HELPERS)
SRCS_PATH		:=	srcs/

# HEADERS_FILES
HEADERS_NAME	:=	philosophers.h helpers.h
HEADERS_PATH	:=	headers/
HEADERS			:=	$(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

# OBJECT_FILES
OBJS_PATH		:=	objs/
OBJS			:=	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

INCLUDES		:=	$(addprefix -I , $(HEADERS))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(HEADERS)
	@cc $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(EC)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)$(PHILO_PATH)
	@mkdir -p $(OBJS_PATH)$(HELPERS_PATH)

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Object files removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Full clean up completed successfully!$(EC)"

re: fclean all

.PHONY: all clean fclean re