#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -c *.c && ar -rc libft.a *.o && rm *.o
