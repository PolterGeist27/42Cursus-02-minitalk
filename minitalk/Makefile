DIRLIB = ./libft

DIRINC = ./includes

SRC_S = srcs/server.c
      
SRC_C = srcs/client.c

BNSSRC_S = srcs/server_bonus.c
      
BNSSRC_C = srcs/client_bonus.c

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

bonus: $(NAMELIBFT)
	$(CC) $(CFLAGS) $(BNSSRC_C) libft/libft.a -o client
	$(CC) $(CFLAGS) $(BNSSRC_S) libft/libft.a -o server
clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
	$(RM) client server

re: fclean all
