CC = cc 

CFLAGS = -Wall -Wextra -Werror

ARGS = 5 100 200 200 

NAME = philo

SOURCES = main.c \
eating_func.c \
gravedigger.c \
input_checker.c \
make_philos.c \
philo_init.c \
mutex_init.c \
philo_dying.c \
philo_func.c \
sleeping_func.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADERS = philosophers.h

%.o : %.c 
	$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME) : $(OBJECTS) $(HEADERS)
	cc $(OBJECTS) -o $(NAME) -g -pthread

.PHONY : all clean fclean re valgrind ulimit

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

ulimit : philo 
	(ulimit -v 140000 ; valgrind --tool=helgrind ./philo 5 610 200 200 10)