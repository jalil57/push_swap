#include "ft_push_swap.h"

void		print_piles(t_algo *algo)
{
	t_list		*tmp_a;
	t_list		*tmp_b;

	tmp_a = algo->pile_a;
	tmp_b = algo->pile_b;
	printf("A: ");
	while (tmp_a)
	{
		printf("%ld ", tmp_a->number);
		tmp_a = tmp_a->next;
	}
	printf("\nB: ");
	while (tmp_b)
	{
		printf("%ld ", tmp_b->number);
		tmp_b = tmp_b->next;
	}
	printf("\n\n");
}

int			check_pile(t_list *pile)
{
	while (pile->next)
	{
		if (pile->next->number < pile->number)
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
			ft_putstr("Error\n");
			exit(0);
		}
		found = 0;
		while (found < search)
		{
			if (ft_strequ(list[found], list[search]))
			{
				printf("DOUBLON\n");
				return (0);
			}
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
		ft_putstr("Error\n");
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
	algo->max_a = -__INT_MAX__ - 1;
	algo->max_b = -__INT_MAX__ - 1;
	algo->min_a = __INT_MAX__;
	algo->min_b = __INT_MAX__;
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

int			main(int ac, char **av)
{
	t_algo	*algo;

	if (ac == 1)
		return (1);
	if (ac == 2 || check_tab(av + 1))
	{
		ft_putstr("OK\n");
		return (1);
	}
	else if (!list_is_valid(av + 1))
	{
		ft_putstr("KO\n");
		return (0);
	}
	if (!(algo = init_algo(av + 1)))
		return (0);
	split_mediane(algo);
print_piles(algo);
sleep(1);
	insert_b(algo);
	print_piles(algo);
	if (check_pile(algo->pile_a))
	{
		ft_putstr("OK\n");
		printf("fait en %d coups\n", algo->count);
	}
	else
		ft_putstr("KO\n");
	free(algo->pile_a);
	free(algo->pile_b);
	free(algo);
	return (0);
}