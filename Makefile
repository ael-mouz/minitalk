NAME	=	server
NAME2	=	client
RM		=	rm -f
CC		=	cc
CFLAG	=	-Wall -Wextra -Werror

FILES	=	./mandatory/ft_server.c \
			./mandatory/ft_utils.c \

FILESB	=	./bonus/ft_server_bonus.c \
			./bonus/ft_utils_bonus.c \

FILES2	=	./mandatory/ft_client.c \
			./mandatory/ft_utils.c \

FILES2B	=	./bonus/ft_client_bonus.c \
			./bonus/ft_utils_bonus.c \

OBJS	=	${FILES:.c=.o}

OBJSB	=	${FILESB:.c=.o}

OBJS2	=	${FILES2:.c=.o}

OBJS2B	=	${FILES2B:.c=.o}

HEADER	=	./mandatory/minitalk.h

HEADERB	=	./bonus/minitalk_bonus.h

all: server client

%.o : %.c $(HEADER) $(HEADERB)
	@$(CC) $(CFLAG) -c $< -o $@

server : $(OBJS)
	@$(CC) $(CFLAG) $(OBJS)  -o $(NAME)
	@echo "$(shell tput -Txterm setaf 2)█ server ready █\n"

client : $(OBJS2)
	@$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)
	@echo "$(shell tput -Txterm setaf 2)█ client ready █\n"

bonus : $(OBJSB) $(OBJS2B)
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@$(CC) $(CFLAG) $(OBJSB)  -o $(NAME)
	@echo "$(shell tput -Txterm setaf 2)█ server bonus ready █\n"
	@$(CC) $(CFLAG) $(OBJS2B) -o $(NAME2)
	@echo "$(shell tput -Txterm setaf 2)█ client bonus ready █\n"

clean :
	@$(RM) $(OBJS)
	@$(RM) $(OBJS2)
	@$(RM) $(OBJSB)
	@$(RM) $(OBJS2B)
	@echo "$(shell tput -Txterm setaf 1)█ object deleted █\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@echo "$(shell tput -Txterm setaf 1)█ program deleted █\n"

re : fclean all

.PHONY : all clean fclean re
