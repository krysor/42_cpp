SRCS	= main.cpp \
			Contact.cpp \
			PhoneBook.cpp \
			addContact.cpp \
			search.cpp

OBJS	= ${SRCS:.cpp=.o}

NAME	= PhoneBook

CC		= c++
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${bOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re