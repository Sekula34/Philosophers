CC = cc 

CFLAGS = -Wall -Wextra -Werror

ARGS = 5 10 10 10

NAME = philo

SOURCES = main.c \
input_checker.c \
make_philos.c \
philo_func.c \
philo_init.c \
mutex_init.c

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
	valgrind --tool=helgrind ./philo $(ARGS)

leak : philo
	valgrind --leak-check=full ./philo $(ARGS)

fun :philo
	funcheck -a ./philo $(ARGS)

start : philo
	./philo $(ARGS)