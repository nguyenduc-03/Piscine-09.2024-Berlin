# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude/dict -Iinclude/ft

# Directories
SRCDIR = srcs
INCDIR = include
OBJDIR = obj

# Source files and object files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Output binary
NAME = my_program

# Default target
all: $(NAME)

# Link the program
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each source file into an object file
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean all files (object files and executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Check Norminette
norm:
	norminette $(SRCDIR)/*.c $(INCDIR)/**/*.h

# Phony targets
.PHONY: all clean fclean re norm
