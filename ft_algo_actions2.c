#include "ft_push_swap.h"

void		action_ra(t_algo *algo)
{
	t_list		*tmp;

	if (!algo->pile_a && !algo->pile_a->next)
		return ;
	tmp = algo->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = algo->pile_a;
	tmp = tmp->next;
	algo->pile_a = algo->pile_a->next;
	algo->pile_a->prev = NULL;
	tmp->next = NULL;
	algo->count++;
	ft_putstr("ra\n");
}

void		action_rb(t_algo *algo)
{
	t_list		*tmp;

	if (!algo->pile_b && !algo->pile_b->next)
		return ;
	tmp = algo->pile_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = algo->pile_b;
	tmp = tmp->next;
	algo->pile_b = algo->pile_b->next;
	algo->pile_b->prev = NULL;
	tmp->next = NULL;
	algo->count++;
	ft_putstr("rb\n");
}

void		action_rra(t_algo *algo)
{
	long		swap;
	t_list		*last;

	last = algo->pile_a;
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		swap = last->number;
		last->number = last->prev->number;
		last->prev->number = swap;
		last = last->prev;
	}
	algo->count++;
	ft_putstr("rra\n");
}

void		action_rrb(t_algo *algo)
{
	t_list		*tmp;

	tmp = algo->pile_b;
	while (tmp->next)
		tmp = tmp->next;
	algo->pile_b->prev = tmp;
	tmp->next = algo->pile_b;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	algo->pile_b = algo->pile_b->prev;
	algo->count++;
	ft_putstr("rrb\n");
}