NAME		=	multiplier

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	$(wildcard *.cpp) ../ex00/adder.cpp

INCS		=	$(wildcard *.hpp) ../ex00/adder.hpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
