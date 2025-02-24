NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_BONUS = client_bonus

NAME_SERVER_BONUS = server_bonus

SOURCES_CLIENT = client.c

SOURCES_SERVER = server.c

BONUS_CLIENT = client_bonus.c

BONUS_SERVER = server_bonus.c

LIBFTDIR = libft


OBJ_CLIENT = $(SOURCES_CLIENT:.c=.o)

OBJ_SERVER = $(SOURCES_SERVER:.c=.o)

OBJ_B_CLIENT = $(BONUS_CLIENT:.c=.o)

OBJ_B_SERVER = $(BONUS_SERVER:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -I. -I$(LIBFTDIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT)
	@make -C $(LIBFTDIR)
	$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(LIBFTDIR)/libft.a

$(NAME_SERVER) : $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -o $(NAME_SERVER) $(LIBFTDIR)/libft.a

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_B_CLIENT)
	@make -C $(LIBFTDIR)
	$(CC) $(OBJ_B_CLIENT) -o $(NAME_CLIENT_BONUS) $(LIBFTDIR)/libft.a

$(NAME_SERVER_BONUS): $(OBJ_B_SERVER)
	$(CC) $(OBJ_B_SERVER) -o $(NAME_SERVER_BONUS) $(LIBFTDIR)/libft.a
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFTDIR)
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_B_CLIENT) $(OBJ_B_SERVER)

fclean : clean
	@make fclean -C $(LIBFTDIR)
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re : fclean all

.PHONY : all clean fclean re