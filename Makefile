NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -Imlx -lmlx -framework OpenGL -framework Appkit 

CFILES = control.c image.c main.c map.c move.c windows.c utils.c get_next_line.c 

OBJECTS = $(CFILES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o  $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@
	
clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re