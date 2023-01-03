DIRLIB = ./libft

DIRINC = ./includes

SRC_S = srcs/server.c
      
SRC_C = srcs/client.c

NAME = minitalk.a
NAMELIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAMELIBFT):
	make all -C $(DIRLIB)

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRC_C) libft/libft.a -o client
	$(CC) $(CFLAGS) $(SRC_S) libft/libft.a -o server

bonus: $(NAME)

clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
	$(RM) client server

re: fclean all
