# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/19 13:40:41 by tettouat          #+#    #+#              #
#    Updated: 2015/08/19 13:58:36 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = Int8.cpp \
	Int16.cpp \
	Int32.cpp \
	Double.cpp \
	Float.cpp \
	Exception.cpp \
	OperandCreator.cpp \
	Operand.cpp \
	Type.cpp \
	Calculator.cpp \
	main.cpp

OBJ = $(SRC:.cpp=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	clang++ $(FLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	clang++ $(FLAG) -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
