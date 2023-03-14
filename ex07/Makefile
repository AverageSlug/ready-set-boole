NAME		=	sat

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	$(wildcard *.cpp) ../ex03/boolean_evaluation.cpp

INCS		=	$(wildcard *.hpp) ../ex03/boolean_evaluation.hpp

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
