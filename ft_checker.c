#include "ft_push_swap.h"

void		print_piles(t_algo *algo)
{
	t_list		*tmp;

	tmp = algo->pile_a;
	ft_putstr("A: ");
	while (tmp)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_putstr("\nB: ");
	tmp = algo->pile_b;
	while (tmp)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_putchar('\n');	
}

void		check_pile(t_algo *algo)
{
	t_list		*tmp;

	tmp = algo->pile_a;
	while (tmp->next)
	{
		if (tmp->next->number < tmp->number)
		{
			ft_putstr("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
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
	while (numbers[i])
	{
		tmp->next = new_number(tmp, numbers[i++]);
		tmp = tmp->next;
	}
	return (algo);
}

int			main(int ac, char **av)
{
	t_algo	*algo;

	if (ac == 1 || !list_is_valid(av + 1))
	{
		ft_putstr("KO\n");
		return (0);
	}
	if (!(algo = init_algo(av + 1)))
		return (0);
	print_piles(algo);

	action_rra(algo);
	print_piles(algo);
	//check_pile(algo);
	free(algo->pile_a);
	free(algo->pile_b);
	free(algo);
	return (0);
}