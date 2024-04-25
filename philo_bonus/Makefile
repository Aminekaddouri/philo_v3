NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

SRCS = free_and_close_bonus.c init_and_parse_args_bonus.c init_data_bonus.c monitor_bonus.c philo_action_bonus.c philo_bonus.c \
		print_message_bonus.c time_bonus.c utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re