#include "push_swap.h"

int	    fusion(t_pile *a, t_pile *b, int asize, int bsize)
{
    int	    i;
    int	    j;
    int	    count;
    int    (*cmp)(int, int);

    i = 0;
    count = 0;
    cmp = &inf;
    if (b->id == 'a')
	cmp = &sup;
    while (i++ < asize)
    {
	push(a, b);
	count++;
    }
    if (!bsize)
	return (count);
    if (bsize == 1)
    {
	push(a, b);
	count++;
	if (cmp(b->head->value, b->head->next->value))
	{
	    swap(b);
	    count++;
	}
    }
    else
    {
	i = 0;
	while (i++ < bsize)
	{
	    j = 0;
	    while (j < asize && cmp(a->head->value, b->head->value))
	    {
		rotate(b);
		count++;
		j++;
	    }
	    push(a, b);
	    count++;
	    while (j--)
	    {
		reverse_rotate(b);
		count++;
	    }
	}
    }
