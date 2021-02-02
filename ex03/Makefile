# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 16:38:37 by lsuardi           #+#    #+#              #
#    Updated: 2021/02/02 18:58:03 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.var

NAME =		Mindopen

OBJDIR =	.obj
CLASSDIR =	class

SRC =		main.cpp\
			Mindopen.cpp
INC =		Mindopen.hpp
OBJ =		$(SRC:.cpp=.o)

SRCPATH =	$(addprefix $(SRCDIR)/, $(SRC))
INCPATH =	$(addprefix $(INCDIR)/, $(INC))
OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))

SRCPATH_CLASS =	$(foreach i, $(CLASS), $(CLASSDIR)/$(SRCDIR)/$i.class.cpp)
INCPATH_CLASS = $(foreach i, $(CLASS), $(CLASSDIR)/$(INCDIR)/$i.class.hpp)
OBJPATH_CLASS = $(foreach i, $(CLASS), $(OBJDIR)/$i.class.o)

CFLAGS =	-Wall\
			-Wextra\
			-Werror\
			-I $(INCDIR)\
			-I $(CLASSDIR)/$(INCDIR)

all: class $(NAME)
	@echo '$(NAME) is up to date'

$(OBJDIR):
	@mkdir $@

class: $(OBJDIR)
	@(\
		cd $(CLASSDIR);\
		$(MAKE);\
		cd ..\
	)

$(NAME): $(INCPATH) $(OBJPATH) $(OBJPATH_CLASS)
	@(\
		echo '\nBuilding objects...';\
		clang++ $(CFLAGS) $(OBJPATH) $(OBJPATH_CLASS) -o $@\
	)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@(\
		printf '\r\033[2KCompiling $<...';\
		clang++ $(CFLAGS) -c $< -o $@\
	)

clean:
	@(\
		rm -rf $(OBJDIR);\
		echo 'Removed objects'\
	)

fclean: clean
	@(\
		rm -f $(NAME);\
		echo 'Removed $(NAME)'\
	)

re: fclean all
