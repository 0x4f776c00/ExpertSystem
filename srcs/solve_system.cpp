/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/03 06:26:47 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

bool	is_restart = false;

static void	clean_induction(Hub *hub)
{
	for (std::list <Axiom> :: iterator it = hub->axioms.begin();
			it != hub->axioms.end(); it++)
	{
		it->clean();
	}
}

static int	induction(Hub *hub, int testing)
{
	int	has_actualized;

	do
	{
		has_actualized = NON_ACTUALISED;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin();
				it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom(testing);
			if (has_actualized & SET_PENDING)
			{
				clean_induction(hub);
				has_actualized -= SET_PENDING;
			}
		}
	} while (has_actualized == ACTUALISED);
	return has_actualized;
}

static void	try_induction(Hub *hub)
{
	int	has_actualized;

	for (std::vector <Fact> :: iterator it = hub->facts.begin();
				it != hub->facts.end(); it++)
	{
		if (it->used == true && it->status == PENDING)
		{
			it->status = T1_FALSE;
			has_actualized = induction(hub, 1);
			it->status = PENDING;
			if (has_actualized & ERROR)
			{
				clean_induction(hub);
				it->status = F_TRUE;
				solve_system(hub);
				return ;
			}
			it->status = T2_TRUE;
			has_actualized = induction(hub, 2);
			if (it->status == T2_TRUE)
				it->status = PENDING;
			clean_induction(hub);
			if (has_actualized & ERROR)
			{
				it->status = F_FALSE;
				solve_system(hub);
				return ;
			}
		}
		if (is_restart)
		{
			is_restart = false;
			solve_system(hub);
			return ;
		}
	}
}

void		solve_system(Hub *hub)
{
	int	has_actualized;
	do
	{
		has_actualized = NON_ACTUALISED;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin();
				it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom(false);
			if (has_actualized & SET_PENDING)
			{
				clean_induction(hub);
				has_actualized -= SET_PENDING;
			}
		}
	} while (has_actualized == ACTUALISED);

	try_induction(hub);
}
