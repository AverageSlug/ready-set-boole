NAME		=	gray_code

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	$(wildcard *.cpp)

INCS		=	$(wildcard *.hpp)

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
