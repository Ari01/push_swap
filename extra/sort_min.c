#include "push_swap.h"

int	    get_min_pos(t_pile src)
{
    int	    min;
    int	    minpos;
    int	    pos;

    pos = 0;
    minpos = 0;
    if (src.head)
    {
	min = src.head->value;
	while (src.head->next)
	{
	    pos++;
	    src.head = src.head->next;
	    if (src.head->value < min)
	    {
		min = src.head->value;
		minpos = pos;
	    }
	}
    }
    return (minpos);
}

int	    push_min(t_pile *src, t_pile *dst)
{
    int	    minpos;
    int	    ret;
    void    (*f)(t_pile *);

    minpos = get_min_pos(*src);
    if (minpos <= src->size / 2)
	f = &rotate;
    else
    {
	f = &reverse_rotate;
	minpos = src->size - minpos;
    }
    ret = minpos + 1;
    while (minpos--)
	f(src);
    push(src, dst);
    return (ret);
}

void	    sort_min(t_pile *a, t_pile *b)
{
    int	    ret;

    ret = 0;
    while (a->head)
	ret += push_min(a, b);
    while (b->head)
    {
	push(b, a);
	ret++;
    }
    printf("moves = %d\n", ret);
}

