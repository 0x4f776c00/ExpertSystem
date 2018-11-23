/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/11/23 19:49:59 by justasze         ###   ########.fr       */
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
	solve_system(&hub);
	return 0;
}
