/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/27 23:06:35 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

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
		}
	} while (has_actualized == ACTUALISED);
	return has_actualized;
}

static void	clean_induction(Hub *hub)
{
	std::cout << "clean" << std::endl;
	for (std::list <Axiom> :: iterator it = hub->axioms.begin();
			it != hub->axioms.end(); it++)
	{
		it->clean();
	}
	std::cout << "end 0clean" << std::endl;

}

static void	try_induction(Hub *hub)
{
	int	has_actualized;

	for (std::vector <Fact> :: iterator it = hub->facts.begin();
				it != hub->facts.end(); it++)
	{
		if (it->status == PENDING)
		{
			it->status = T1_FALSE;
			has_actualized = induction(hub, 1);
			it->status = PENDING;
			if (has_actualized & ERROR)
			{
				std::cout << it->symbol << " set F_TRUE" << std::endl;

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
				std::cout << it->symbol << " set F_FALSE" << std::endl;

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
	std::cout << "solve_system" << std::endl;
	int i = 0;
	do
	{
		std::cout << "loop " << i << std::endl;
		i++;
		int j = 0;
		has_actualized = NON_ACTUALISED;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin(); it != hub->axioms.end(); it++)
		{
			std::cout << "axiom " << j << std::endl;
			j++;
			has_actualized |= it->compute_axiom(false);
			for (size_t it = 0; it < hub->queries.length(); it++)
			{
				std::cout << hub->facts[hub->queries[it] - 'A'].symbol << ": "
						<< hub->facts[hub->queries[it] - 'A'].status << std::endl;
			}
		}
	} while (has_actualized == ACTUALISED);

	std::cout << "try induction" << std::endl;
	try_induction(hub);
}