### directories
SRC_DIR		= 	src/
OBJ_DIR 	= 	obj/

### files
SRCS		= 	main.cpp \
				ClapTrap.cpp \
				UI.cpp

SRCS		:=	$(addprefix $(SRC_DIR), $(SRCS))

OBJS		=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

### variables
NAME		= ex00
CC			= c++
RM			= rm -rf
INCLUDES	=	-I ./includes

FLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
			mkdir -p $(@D)
			${CC} $(INCLUDES) $(FLAGS) -c $< -o $@

all:		${NAME}

run:		all
			./${NAME}

clean:
			${RM} $(OBJ_DIR)

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re