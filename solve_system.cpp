/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/06/02 15:08:53 by bcozic           ###   ########.fr       */
=======
/*   Updated: 2018/06/02 13:41:53 by justasze         ###   ########.fr       */
>>>>>>> 843b9dac8e56244c42ac26a6596b05fb3aebc675
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

<<<<<<< HEAD
static bool	induction(Hub *hub)
{

}

static void	deduction(Hub *hub, bool testing)
{
	bool	has_actualized;

	do
	{
		has_actualized = false;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin(); it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom(testing);
		}
	} while (has_actualized == true);
}

void		solve_system(Hub *hub)
=======


void	solve_system(Hub *hub)
>>>>>>> 843b9dac8e56244c42ac26a6596b05fb3aebc675
{
	bool	has_actualized;

	do
	{
		has_actualized = false;
		for (std::list <Axiom> :: iterator it = hub->axioms.begin(); it != hub->axioms.end(); it++)
		{
			has_actualized |= it->compute_axiom();
		}
	} while (has_actualized == true);

	for (size_t it = 0; it < hub->queries.length(); it++)
	{
		std::cout << hub->facts[hub->queries[it] - 'A'].symbol << ": "
			<< hub->facts[hub->queries[it] - 'A'].status << std::endl;
	}
}