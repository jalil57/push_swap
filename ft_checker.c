#include "ft_push_swap.h"

void		print_piles(t_algo *algo)
{
	t_list		*a;
	t_list		*b;

	a = algo->pile_a;
	b = algo->pile_b;
	ft_putstr("*---------------*\n");
	ft_printf("|   A:  |   B:  |\n");
	ft_putstr("*---------------*\n");
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("| %5ld | %-5ld |\n", a->number, b->number);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			ft_printf("| %5ld |       |\n", a->number);
			a = a->next;
		}
		else if (b)
		{
			ft_printf("|       | %-5ld |\n", b->number);
			b = b->next;
		}
		ft_putstr("*---------------*\n");
	}
	ft_printf("| hits: %-7d |\n", algo->count);
	ft_putstr("*---------------*\n");
}

int			check_pile(t_algo *algo)
{
	t_list	*pile;

	pile = algo->pile_a;
	while (pile->next)
	{
		if (pile->number > pile->next->number)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int			check_error(char *str)
{
	int		c;
	int		i;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '.' && (c++) > 1)
			return (0);
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			;
		else if (!ft_isdigit(str[i]) && str[i] !=  '.')
			return (0);
		i++;
	}
	return (1);
}

int			list_is_valid(char	**list)
{
	int		search;
	int		found;

	search = 0;
	while (list[search])
	{
		if (!check_error(list[search]))
		{
			ft_color("Error\n", RED);
			exit(0);
		}
		found = 0;
		while (found < search)
		{
			if (ft_strequ(list[found], list[search]))
				return (0);
			found++;
		}
		search++;
	}
	return (1);
}

t_list		*new_number(t_list *prev, char *number)
{
	t_list	*maillon;

	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if ((maillon->number = ft_atol(number)) > __INT_MAX__ ||
			maillon->number < -__INT_MAX__ - 1)
	{
		ft_color("Error\n", RED);
		exit(0);
	}
	maillon->next = NULL;
	maillon->prev = prev;
	return (maillon);
}

t_algo		*init_algo(char **numbers)
{
	int		i;
	t_algo	*algo;
	t_list	*tmp;

	if (!(algo = (t_algo *)malloc(sizeof(t_algo))))
		return (NULL);
	if (!(algo->pile_a = new_number(NULL, numbers[0])))
	{
		free(algo);
		return (NULL);
	}
	algo->pile_b = NULL;
	tmp = algo->pile_a;
	i = 1;
	algo->max_a = -__LONG_MAX__;
	algo->max_b = -__LONG_MAX__;
	algo->min_a = __LONG_MAX__;
	algo->min_b = __LONG_MAX__;
	while (numbers[i])
	{
		tmp->next = new_number(tmp, numbers[i++]);
		if (tmp->number > algo->max_a)
			algo->max_a = tmp->number;
		if (tmp->number < algo->min_a)
			algo->min_a = tmp->number;
		tmp = tmp->next;
	}
	algo->len_a = i - 1;
	algo->len_b = 0;
	algo->count = 0;
	return (algo);
}

int			check_tab(char **list)
{
	int		i;

	i = 0;
	if (!list_is_valid(list))
		return (0);
	while (list[i + 1])
	{
		if (ft_atol(list[i]) > ft_atol(list[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void		free_algo(t_algo *algo)
{
	t_list		*tmp;
	t_list		*save;

	tmp = algo->pile_a;
	while (tmp)
	{
		save = tmp->next;
		free(tmp);
		tmp = save;
	}
	free(algo->pile_a);
	tmp = algo->pile_b;
	while (tmp)
	{
		save = tmp->next;
		free(tmp);
		tmp = save;
	}
	free(algo->pile_b);
	free(algo);
}

int			main(int ac, char **av)
{
	t_algo	*algo;

	if (ac == 1)
		return (1);
	if (ac == 2 || check_tab(av + 1))
	{
		ft_color("OK\n", GREEN);
		return (1);
	}
	else if (!list_is_valid(av + 1))
	{
		ft_color("KO\n", RED);
		return (0);
	}
	if (!(algo = init_algo(av + 1)))
		return (0);
	split_mediane(algo);
	insert_b(algo);
	print_piles(algo);
	if (check_pile(algo))
	{
		ft_color("OK\n", GREEN);
		printf("fait en %d coups\n", algo->count);
	}
	else
		ft_color("KO\n", RED);
	free_algo(algo);
	return (0);
}