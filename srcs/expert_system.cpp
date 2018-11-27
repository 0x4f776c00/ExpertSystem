/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/11/27 22:08:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int	usage()
{
	std::cout << "usage: ./expert_system <file>" << std::endl;
	return (EXIT_FAILURE);
}

static void	create_facts(Hub *hub, int default_status)
{
	for (int i = 0; i < 26; i++)
		hub->facts.push_back(Fact(0, 'A' + i, default_status));
}

static void	set_queries(Hub *hub)
{
	for (size_t it = 0; it < hub->queries.length(); it++)
	{
		if (hub->facts[hub->queries[it] - 'A'].status != F_TRUE)
			hub->facts[hub->queries[it] - 'A'].status = PENDING;
	}
}

static void	display_system(Hub *hub)
{
	for (size_t it = 0; it < hub->queries.length(); it++)
	{
		std::cout << hub->facts[hub->queries[it] - 'A'].symbol << ": "
			<< hub->facts[hub->queries[it] - 'A'].status << std::endl;
	}
}

int		main(int ac, char **av)
{
	Hub			hub;
	int	default_status;

	if (ac < 2)
		return (usage());

	default_status = F_FALSE;

	if (ac == 3 && !strcmp(av[2], "-b"))
		default_status = PENDING;

	std::srand(std::time(NULL));
	create_facts(&hub, default_status);
	get_system(&hub, av[1]);
	set_queries(&hub);
	display_system(&hub);

	solve_system(&hub);
	display_system(&hub);

	return 0;
}
