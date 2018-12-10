#include "ft_push_swap.h"

void    ft_tri_2(t_algo *algo)
{
    if (algo->pile_a->number > algo->pile_a->next->number)
        action_sa(algo);
}

void    ft_tri_3(t_algo *algo)
{
     if (algo->pile_a->number < algo->pile_a->next->number 
    && algo->pile_a->next->number < algo->pile_a->next->next->number &&  algo->pile_a->number < algo->pile_a->next->next->number)
        action_rra(algo);
    else if (algo->pile_a->number > algo->pile_a->next->number 
    && algo->pile_a->next->number < algo->pile_a->next->next->number &&  algo->pile_a->number < algo->pile_a->next->next->number)
        action_sa(algo);
    else if (algo->pile_a->number < algo->pile_a->next->number 
    && algo->pile_a->next->number > algo->pile_a->next->next->number && algo->pile_a->number > algo->pile_a->next->next->number)
        action_rra(algo);
    else if (algo->pile_a->number < algo->pile_a->next->number 
    && algo->pile_a->next->number > algo->pile_a->next->next->number)
    {
        action_rra(algo);
        action_sa(algo);
    }
    else if (algo->pile_a->number > algo->pile_a->next->number 
    && algo->pile_a->next->number < algo->pile_a->next->next->number)
        {
            action_ra(algo);
            if (algo->pile_a->next->number > algo->pile_a->next->next->number)
            action_sa(algo);
        }
    else if (algo->pile_a->number > algo->pile_a->next->number 
    && algo->pile_a->next->number > algo->pile_a->next->next->number && algo->pile_a->number > algo->pile_a->next->next->number)
    {
        action_sa(algo);
        action_rra(algo);
    }
}