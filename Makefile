NAME = push_swap
LIBFT = libft.a
LIBFTDIR = libft

SRCS = elem.c \
insert.c \
single_pile.c \
multiple_piles.c \
sort_utils.c \
sort.c

OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L. -lft
RM = rm -rf

all :	    $(NAME)

$(NAME) :   $(OBJS) $(LIBFT) push_swap.c
	    $(CC) $(CFLAGS) push_swap.c $(OBJS) -o $@ $(LFLAGS)

handtester: $(OBJS) $(LIBFT) hand_tester.c
	    $(CC) $(CFLAGS) $(SRCS) hand_tester.c -o $@ $(LFLAGS)

randomize:  $(OBJS) $(LIBFT) randomize.c
	    $(CC) $(CFLAGS) $(SRCS) randomize.c -o $@ $(LFLAGS)

$(LIBFT) :  
	    cd $(LIBFTDIR) && $(MAKE) $(BONUS) && mv $@ ../$@

.c.o :
	    $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	    $(RM) $(OBJS)

fclean :    clean
	    $(RM) $(NAME) $(LIBFT) handtester randomize
	    $(RM) .*.swp
	    cd $(LIBFTDIR) && $(MAKE) fclean

re :	    fclean all

.PHONY:	    all clean fclean re
