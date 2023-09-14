NAME = bsq

SOURCES = src/main.c src/read_file.c src/read_first_line.c src/save_file.c src/square_calc.c src/tools.c src/error.c src/read_term.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra -I includes

$(NAME): $(OBJECTS)
	cc $(FLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c includes/includes.h includes/prototypes.h includes/struct.h
	cc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY = clean fclean re
