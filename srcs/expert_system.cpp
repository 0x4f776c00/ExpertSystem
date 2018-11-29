/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/11/29 21:32:07 by justasze         ###   ########.fr       */
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

static void	display_system(Hub *hub)
{
	for (size_t it = 0; it < hub->queries.length(); it++)
	{
		std::cout << hub->facts[hub->queries[it] - 'A'].symbol << ": ";
		if (hub->facts[hub->queries[it] - 'A'].status == F_TRUE)
			std::cout << "True." << std::endl;
		else if (hub->facts[hub->queries[it] - 'A'].status == F_FALSE || hub->facts[hub->queries[it] - 'A'].status == S_FALSE)
			std::cout << "False." << std::endl;
		else
			std::cout << "Unknownable." << std::endl;
	}
}

int		main(int ac, char **av)
{
	Hub			hub;
	int	default_status;

	if (ac < 2)
		return (usage());

	default_status = S_FALSE;

	if (ac == 3 && !strcmp(av[2], "-b"))
		default_status = PENDING;

	std::srand(std::time(NULL));
	create_facts(&hub, default_status);
	get_system(&hub, av[1]);
	solve_system(&hub);
	display_system(&hub);

	return 0;
}
