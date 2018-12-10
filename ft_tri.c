#include "ft_push_swap.h"

static int		calculate_mediane(t_list *pile)
{
	int		min_value;
	int		max_value;

	min_value = pile->number;
	max_value = min_value;
	while (pile)
	{
		if (pile->number < min_value)
			min_value = pile->number;
		if (pile->number > max_value)
			max_value = pile->number;
		pile = pile->next;
	}
	return ((max_value + min_value) / 2);
}

static int		have_inf_mediane(t_list	*list, int mediane)
{
	while (list)
	{
		if (list->number < mediane)
			return (1);
		list = list->next;
	}
	return (0);
}

int			get_max(t_list *tmp)
{
	int		max;

	max = tmp->number;
	while (tmp)
	{
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

void		split_mediane(t_algo *algo)
{
	int		mediane;

	mediane = calculate_mediane(algo->pile_a);
	algo->max_a = get_max(algo->pile_a);
	while (algo->pile_a->number != algo->max_a)
		action_ra(algo);
	while (have_inf_mediane(algo->pile_a, mediane))
	{
		if (algo->pile_a->number < mediane && (!algo->pile_b ||
				algo->pile_a->number > algo->pile_b->number))
			action_pb(algo);
		else if (algo->pile_a->number < mediane)
		{
			action_pa(algo);
			action_ra(algo);
			action_pb(algo);
		}
		else
			action_ra(algo);
	}
	if (algo->len_a > 2)
		split_mediane(algo);
	else
	{
		while (!check_pile(algo->pile_a))
		{
			if (algo->pile_a->number < algo->pile_a->next->number)
				action_sa(algo);
			else
				action_ra(algo);
		}
	}
}

void		insert_b(t_algo *algo)
{
	while (algo->pile_b)
		action_pa(algo);
}