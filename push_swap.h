/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:17:26 by user42            #+#    #+#             */
/*   Updated: 2021/08/19 17:53:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define MIN 0
# define MAX 1

/*
** TYPES
*/
typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_pile
{
	t_elem	*head;
	t_elem	*tail;
	int		size;
	char	id;
}	t_pile;

/*
** PARSING
*/
int		get_args(char **av, t_pile *p);

/*
** LIST FUNCTIONS
*/
t_elem	*new_elem(int value);
t_pile	init_pile(char id);
void	push_back(t_pile *pile, int value);
void	print_pile(t_pile pile);
void	clear(t_pile *pile);

/*
** PILE FUNCTIONS
*/
void	swap_elem(t_elem *e1, t_elem *e2);
void	swap(t_pile *pile);
void	rotate(t_pile *pile);
void	reverse_rotate(t_pile *pile);

void	push(t_pile *src, t_pile *dst);
void	ss(t_pile *p1, t_pile *p2);
void	rr(t_pile *p1, t_pile *p2);
void	rrr(t_pile *p1, t_pile *p2);

/*
** SORT UTILS
*/
int		inf(int a, int b);
int		sup(int a, int b);
int		is_sorted(t_pile a, t_pile b);
t_elem	*get_minmax(t_pile p, int *pos);
int		get_newpos(int value, t_pile p, t_elem *start, int newpos);
void	*get_op(int pilesize, int *nops);
void	insert(t_pile *a, t_pile *b);
void	convert_values(t_pile *a);

/*
** SORT FUNCTIONS
*/
int		is_sorted(t_pile a, t_pile b);
void	sort(t_pile *a, t_pile *b);
void	sort_min(t_pile *a, t_pile *b);
void	sort_in_b(t_pile *a, t_pile *b);

/*
**  PRINT
*/
void	print_op(char *op, char id);

#endif
