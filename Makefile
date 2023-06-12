NAME = push_swap
# NAMEB = so_long_bonus
SRCDIR = src
OBJDIR = obj
# SRCBDIR = srcb
# OBJBDIR = objb
SRCS = $(addprefix $(SRCDIR)/, push_swap.c validation.c validation_0.c validation_utils.c \
swap.c push.c rotate.c rrotate.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
# SRCB = $(addprefix $(SRCBDIR)/, so_long_bonus.c check_map_bonus.c check_map_2_bonus.c \
# render_map_bonus.c moves_bonus.c exit_bonus.c utils_bonus.c)
# OBJB = $(patsubst $(SRCBDIR)/%.c, $(OBJBDIR)/%.o, $(SRCB))
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft
HEADER = $(SRCDIR)/push_swap.h
# HEADERB = $(SRCBDIR)/so_long_bonus.h

all: $(NAME) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) Makefile
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

# bonus: $(NAMEB)

# $(NAMEB): $(OBJB) $(LIBFTA) 
# 	$(CC) $(CFLAGS) $(OBJB) $(LIBS) -o $(NAMEB)

# $(OBJBDIR)/%.o: $(SRCBDIR)/%.c $(HEADERB)
# 	mkdir -p $(OBJBDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re 
# bonus