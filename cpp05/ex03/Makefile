### directories
SRC_DIR		= 	Sources/
OBJ_DIR 	= 	Objects/

### files
SRCS		= 	main.cpp \
				UI.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

SRCS		:=	$(addprefix $(SRC_DIR), $(SRCS))

OBJS		=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))

### variables
NAME		= ex03
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
			${RM} $(OBJ_DIR) *_shrubbery

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re