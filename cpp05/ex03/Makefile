NAME = intern

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

HEADERS = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
	RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

OBJS = ${SRCS:.cpp=.o}

DEPS = ${HEADERS}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

%.o : %.cpp ${DEPS}
	${CXX} ${CXXFLAGS}  -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re