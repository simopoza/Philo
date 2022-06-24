src = *.c 
philo = philo
# SANITIZE = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror -g $(SANITIZE)
CC = cc

all : philo
	
$(philo): $(src)	
	@$(CC) $(FLAGS) $(src) -o philo
	@tput setaf 2; echo "philo IS READY"

clean :
	@rm -f philo
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all