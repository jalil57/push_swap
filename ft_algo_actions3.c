#include "ft_push_swap.h"

void		action_ss(t_algo *algo)
{
	action_sa(algo);
	action_sb(algo);
	ft_putstr("ss\n");
}

void		action_rr(t_algo *algo)
{
	action_ra(algo);
	action_rb(algo);
	ft_putstr("rr\n");
}

void		action_rrr(t_algo *algo)
{
	action_rra(algo);
	action_rrb(algo);
	ft_putstr("rrr\n");
}