/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/27 16:43:05 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int	induction(Hub *hub, bool testing)
{
	int	has_actualized;

	do
	{
		has_actualized = NON_ACTUALISED;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin();
				it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom(testing);
		}
	} while (has_actualized == ACTUALISED);
	//  std::cout << "actu : " << has_actualized << std::endl;
	return has_actualized;
}

static void	clean_induction(Hub *hub)
{
	for (std::vector <Fact> :: iterator it = hub->facts.begin(); it != hub->facts.end(); it++)
	{
		if (it->status == T_TRUE || it->status == T_FALSE)
			it->status = PENDING;
	}
}

static void	try_induction(Hub *hub)
{
	int	has_actualized;

	for (std::vector <Fact> :: iterator it = hub->facts.begin();
				it != hub->facts.end(); it++)
	{
		if (it->status == PENDING)
		{
			// std::cout << it->symbol << " T_FALSE" << std::endl;
			it->status = T_FALSE;
			has_actualized = induction(hub, true);
			clean_induction(hub);
			it->status = T_TRUE;
			if (has_actualized & ERROR)
			{
			// std::cout << it->symbol << " set F_TRUE" << std::endl;

				it->status = F_TRUE;
				solve_system(hub);
				return ;
			}
			// std::cout << it->symbol << " T_TRUE" << std::endl;

			has_actualized = induction(hub, true);
			clean_induction(hub);
			if (has_actualized & ERROR)
			{
			// std::cout << it->symbol << " set F_FALSE" << std::endl;

				it->status = F_FALSE;
				solve_system(hub);
				return ;
			}
		}
	}
}

void		solve_system(Hub *hub)
{
	int	has_actualized;

	do
	{
		has_actualized = NON_ACTUALISED;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin(); it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom(false);
		}
	} while (has_actualized == ACTUALISED);

	try_induction(hub);
}