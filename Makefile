NAME = push_swap
LIBFT = libft.a
LIBFTDIR = libft

SRCS = elem.c \
single_pile.c \
multiple_piles.c \
sort.c

OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L. -lft
RM = rm -rf

all :	    $(NAME)

$(NAME) :   $(OBJS) $(LIBFT)
	    $(CC) $(CFLAGS) push_swap.c $(OBJS) -o $@ $(LFLAGS)

handtester: $(OBJS) $(LIBFT)
	    $(CC) $(CFLAGS) $(SRCS) hand_tester.c -o $@ $(LFLAGS)

$(LIBFT) :  
	    cd $(LIBFTDIR) && $(MAKE) $(BONUS) && mv $@ ../$@

.c.o :
	    $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	    $(RM) $(OBJS)

fclean :    clean
	    $(RM) $(NAME) $(LIBFT)
	    cd $(LIBFTDIR) && $(MAKE) clean fclean

re :	    fclean all

.PHONY:	    all clean fclean re
