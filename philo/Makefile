CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SOURCES = main.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADERS = philosophers.h

%.o : %.c 
	$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME) : $(OBJECTS) $(HEADERS)
	cc $(OBJECTS) -o $(NAME) -pthread

.PHONY : all clean fclean re valgrind

all : $(NAME)

clean : 
	-rm $(OBJECTS)

fclean : clean
	-rm $(NAME)

re : fclean all

valgrind : philo
	valgrind --tool=helgrind ./philo