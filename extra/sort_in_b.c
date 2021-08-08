#include "push_swap.h"

static t_elem	    *get_max(t_pile p, int *maxpos)
{
    int	    i;
    t_elem  *max;

    i = 0;
    *maxpos = 0;
    max = p.head;
    while (p.head && p.head->next)
    {
	i++;
	p.head = p.head->next;
	if (p.head->value > max->value)
	{
	    max = p.head;
	    *maxpos = i;
	}
    }
    return (max);
}

void	    sort_in_b(t_pile *a, t_pile *b)
{
    int	    count;
    int	    nops;
    t_elem  *max;

    count = 0;
    while (a->head)
    {
	if (b->size >= 2)
	{
	    nops = get_nops(a->head->value, *b);
	    count += set_head(b, nops);
	}
	push(a, b);
	printf("pb\n");
	count++;
    }
    max = get_max(*b, &nops);
    count += set_head(b, nops);
    while (b->head)
    {
	push(b, a);
	printf("pa\n");
	count++;
    }
    printf("count = %d\n", count);
}

