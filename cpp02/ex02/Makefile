NAME = fixedPoint01

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp

HEADERS = Fixed.hpp

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