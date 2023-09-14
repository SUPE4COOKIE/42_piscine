CFLAGS = -Wall -Wextra -Werror
SRC = *.c
NAME = rush-02

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRC) 

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
