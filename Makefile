# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apanikov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 02:16:11 by apanikov          #+#    #+#              #
#    Updated: 2023/06/15 02:16:14 by apanikov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker
SRCDIR = src
OBJDIR = obj
SRCBDIR = srcb
OBJBDIR = objb
SRCS = $(addprefix $(SRCDIR)/, push_swap.c validation.c validation_0.c validation_utils.c \
swap.c push.c rotate.c rrotate.c butterfly.c exception.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
SRCB = $(addprefix $(SRCBDIR)/,push_swap_bonus.c validation_bonus.c validation_0_bonus.c \
validation_utils_bonus.c swap_bonus.c push_bonus.c rotate_bonus.c rrotate_bonus.c)
OBJB = $(patsubst $(SRCBDIR)/%.c, $(OBJBDIR)/%.o, $(SRCB))
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft
LIBGNL = ./get_next_line
LIBGNLA = $(LIBGNL)/libgnl.a
LIBSB = -L$(LIBFT) -lft -L$(LIBGNL) -lgnl
HEADER = $(SRCDIR)/push_swap.h
HEADERB = $(SRCBDIR)/push_swap_bonus.h

all: $(NAME) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) Makefile
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

$(LIBGNLA):
	@$(MAKE) -C $(LIBGNL)

bonus: $(NAMEB)

$(NAMEB): $(OBJB) $(LIBFTA) $(LIBGNLA)
	$(CC) $(CFLAGS) $(OBJB) $(LIBSB) -o $(NAMEB)

$(OBJBDIR)/%.o: $(SRCBDIR)/%.c $(HEADERB) Makefile
	mkdir -p $(OBJBDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJB)
	$(RM) $(OBJDIR) $(OBJBDIR)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

fclean: clean
	$(RM) $(NAME) $(NAMEB)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBGNL) fclean

re: fclean all

.PHONY: all clean fclean re bonus
