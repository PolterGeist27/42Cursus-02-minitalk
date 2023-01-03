
DIRSRC = ./srcs/

DIRINCS = ./includes/

DIRLIB = ./libft/

SRC = server.c \
      client.c \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = $(SRCS:.c=.o)

NAME = minitalk.a
NAMELIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(DIRINCS)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(DIRLIB)
	cp $(DIRLIB)/$(NAMELIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	make clean -C $(DIRLIB)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(DIRLIB)
	$(RM) $(NAME)

re: fclean all
