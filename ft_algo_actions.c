#include "ft_push_swap.h"

void		action_sa(t_algo *algo)
{
	int		swap;

	if (algo->pile_a && algo->pile_a->next)
	{
		swap = algo->pile_a->number;
		algo->pile_a->number = algo->pile_a->next->number;
		algo->pile_a->next->number = swap;
	}
	algo->count++;
	ft_putstr("sa\n");
}

void		action_sb(t_algo *algo)
{
	int		swap;

	if (algo->pile_b && algo->pile_b->next)
	{
		swap = algo->pile_b->number;
		algo->pile_b->number = algo->pile_b->next->number;
		algo->pile_b->next->number = swap;
	}
	algo->count++;
	ft_putstr("sb\n");
}

void		action_pb(t_algo *algo)
{
	t_list		*save;

	if (!algo->pile_a)
		return ;
	save = algo->pile_a;
	if ((algo->pile_a = algo->pile_a->next))
		algo->pile_a->prev = NULL;
	if (algo->pile_b)
	{
		algo->pile_b->prev = save;
		save->next->prev = NULL;
		algo->pile_b->prev->next = algo->pile_b;
		algo->pile_b = algo->pile_b->prev;
	}
	else
	{
		algo->pile_b = save;
		save->next->prev = NULL;
		algo->pile_b->next = NULL;
		algo->pile_b->prev = NULL;
	}
	algo->len_a--;
	algo->len_b++;
	if (algo->pile_b->number > algo->max_b)
		algo->max_b = algo->pile_b->number;
	if (algo->pile_b->number > algo->min_b)
		algo->min_b = algo->pile_b->number;
	algo->count++;
	ft_putstr("pb\n");
}

void		action_pa(t_algo *algo)
{
	t_list		*save;

	if (!algo->pile_b)
		return ;
	save = algo->pile_b;	
	if ((algo->pile_b = algo->pile_b->next))
		algo->pile_b->prev = NULL;
	if (algo->pile_a)
	{
		algo->pile_a->prev = save;
		algo->pile_a->prev->next = algo->pile_a;
		algo->pile_a = algo->pile_a->prev;
	}
	else
	{
		algo->pile_a = save;
		algo->pile_a->next = NULL;
	}
	algo->len_b--;
	algo->len_a++;
	if (algo->pile_a->number > algo->max_a)
		algo->max_a = algo->pile_a->number;
	algo->count++;
	ft_putstr("pa\n");
}