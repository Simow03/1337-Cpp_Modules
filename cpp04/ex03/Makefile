NAME = interfaces

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

HEADERS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp \
		ICharacter.hpp IMateriaSource.hpp 

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