/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/11/23 20:18:37 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int	usage()
{
	std::cout << "usage: ./expert_system <file>" << std::endl;
	return (EXIT_FAILURE);
}

static void	create_facts(Hub *hub, e_status default_status)
{
	for (int i = 0; i < 26; i++)
		hub->facts.push_back(Fact(0, 'A' + i, default_status));
}

int		main(int ac, char **av)
{
	e_status	default_status;

	if (ac < 2)
		return (usage());
	default_status = F_FALSE;
	if (ac == 3 && !strcmp(av[2], "-b"))
		default_status = PENDING;
	Hub hub;
	std::srand(std::time(NULL));
	create_facts(&hub, default_status);
	get_system(&hub, av[1]);
	for (size_t it = 0; it < hub.queries.length(); it++)
	{
		hub.facts[hub.queries[it] - 'A'].status = PENDING;
	}
	solve_system(&hub);
	return 0;
}
