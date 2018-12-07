#include "libft/libft.h"
#include "ft_push_swap.h"

void		print_piles(t_algo *algo)
{
	t_list		*tmp;

	tmp = algo->pile_a;
	while (tmp)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	tmp = algo->pile_b;
	while (tmp)
	{
		ft_printf("%d ", tmp->number);
		tmp = tmp->next;
	}
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

t_list		*new_number(t_list *prev, char *number)
{
	t_list	*maillon;

	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	maillon->number = ft_atoi(number);
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

	if (ac == 1)
	{
		ft_putstr("KO\n");
		return (0);
	}
	if (!(algo = init_algo(av + 1)))
		return (0);
	print_piles(algo);
	check_pile(algo);
	free(algo->pile_a);
	free(algo->pile_b);
	free(algo);
	return (0);
}