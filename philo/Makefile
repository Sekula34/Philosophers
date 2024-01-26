CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SOURCES = main.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADERS = philosophers.h

%.o : %.c 
	$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME) : $(OBJECTS) $(HEADERS)
	cc $(OBJECTS) -o $(NAME)

.PHONY : all clean fclean re

all : $(NAME)

clean : 
	-rm $(OBJECTS)

fclean : clean
	-rm $(NAME)

re : fclean all