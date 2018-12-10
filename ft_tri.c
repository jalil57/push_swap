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

int			get_min(t_list *tmp)
{
	int		min;

	min = tmp->number;
	while (tmp)
	{
		if (tmp->number > min)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

void		split_mediane(t_algo *algo)
{
	int		mediane;

	mediane = calculate_mediane(algo->pile_a);
	printf("mediane = %d\n", mediane);
	algo->min_a = get_min(algo->pile_a);
	while (algo->pile_a->number != algo->min_a)
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
	//	print_piles(algo);
	//	sleep(1);
	}
	if (algo->len_a > 2)
		split_mediane(algo);
	else
	{
		while (!check_pile(algo))
		{
			if (algo->pile_a->number < algo->pile_a->next->number)
				action_sa(algo);
			else
				action_ra(algo);
		//	print_piles(algo);
		}
	}
}

void		insert_b(t_algo *algo)
{
	int min;

	min = get_min(algo->pile_b);
	while (algo->pile_b->number != min)
		action_rb(algo);
	action_pa(algo);
	if (algo->len_b)
		insert_b(algo);
}