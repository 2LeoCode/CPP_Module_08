NAME = postfix

SRCDIR = src
INCDIR = inc
OBJDIR = .obj

SRC = Op.class.cpp main.cpp 
INC = Num.class.hpp Op.class.hpp ParClose.class.hpp ParOpen.class.hpp Token.class.hpp postfix.hpp 
OBJ = $(SRC:.cpp=.o)

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))
INCPATH = $(addprefix $(INCDIR)/, $(INC))
OBJPATH = $(addprefix $(OBJDIR)/, $(OBJ))

CFLAGS = -Wall -Werror -Wextra -I $(INCDIR)

all: $(NAME)
	@echo '$(NAME) is up to date'

$(NAME): $(INCPATH) $(OBJDIR) $(OBJPATH)
	@(echo '\nBuilding objects...'; clang++ $(CFLAGS) $(OBJPATH) -o $@)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@(printf '\r\033[2KCompiling $<...'; clang++ $(CFLAGS) -c $< -o $@)

clean:
	@(rm -rf $(OBJDIR); echo 'Removed objects')

fclean: clean
	@(rm -rf $(NAME); echo 'Removed $(NAME)')

re: fclean all
