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
		algo->pile_b->prev->next = algo->pile_b->prev;
		algo->pile_b = algo->pile_b;
	}
	else
	{
		algo->pile_b = save;
		algo->pile_b->next = NULL;
	}
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
	ft_putstr("pa\n");
}