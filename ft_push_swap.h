#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft/libft.h"
# define NBMIN      -500
# define NBMAX      500
# define LEN_LIST   10

typedef struct      s_algo
{
    t_list          *pile_a;
    t_list          *pile_b;
}                   t_algo;

/*
**      utils
*/
char            **randomize(int len);
void		    print_piles(t_algo *algo);

/*
**      actions
*/
void		    action_sa(t_algo *algo);
void		    action_sb(t_algo *algo);
void		    action_ss(t_algo *algo);
void		    action_pa(t_algo *algo);
void		    action_pb(t_algo *algo);
void		    action_ra(t_algo *algo);
void		    action_rb(t_algo *algo);
void		    action_rr(t_algo *algo);
void		    action_rra(t_algo *algo);
void		    action_rrb(t_algo *algo);
void		    action_rrr(t_algo *algo);

#endif