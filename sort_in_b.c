#include "push_swap.h"

t_elem	    *get_max(t_pile p, int *maxpos)
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

int	    get_nops(int value, t_pile b)
{
    t_elem  *ite;
    t_elem  *max;
    int	    nops;

    max = get_max(b, &nops);
    ite = max;
    while (value < ite->value)
    {
	ite = ite->next;
	nops++;
	if (!ite)
	{
	    ite = b.head;
	    nops = 0;
	}
	if (ite == max)
	    break;
    }
    return (nops);
}

int	    set_head(t_pile *p, int nops)
{
    void    (*op)(t_pile *);
    char    *msg;
    int	    i;

    i = 0;
    if (nops <= p->size / 2)
    {
	op = &rotate;
	msg = "rb";
    }
    else
    {
	nops = p->size - nops;
	op = &reverse_rotate;
	msg = "rrb";
    }
    while (i < nops)
    {
	op(p);
	printf("%s\n", msg);
	i++;
    }
    return (nops);
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

