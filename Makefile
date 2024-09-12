OBJS = src/get_next_line.o src/get_next_line_utils.o main.o

BONUS_OBJS = bonus/src/get_next_line_bonus.o bonus/src/get_next_line_utils_bonus.o main.o

BONUS_NAME = get_next_line_bonus
NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME):$(BONUS_OBJS)
	cc $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re