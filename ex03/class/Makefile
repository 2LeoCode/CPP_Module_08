# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 16:17:37 by lsuardi           #+#    #+#              #
#    Updated: 2021/02/01 17:52:15 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../Makefile.var

OBJDIR =	../.obj

SRC =		$(addsuffix .class.cpp, $(CLASS))
INC =		$(addsuffix .class.hpp, $(CLASS))
OBJ =		$(SRC:.cpp=.o)

SRCPATH =	$(addprefix $(SRCDIR)/, $(SRC))
INCPATH =	$(addprefix $(INCDIR)/, $(INC))
OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))

CFLAGS =	-Wall\
			-Wextra\
			-Werror\
			-I $(INCDIR)

all: $(OBJPATH)
	@(\
		echo;\
		echo 'Classes are up to date'\
	)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	@(\
		printf '\r\033[2KCompiling $<...';\
		clang++ $(CFLAGS) -c $< -o $@\
	)
