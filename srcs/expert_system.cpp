/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/05/21 15:13:38 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int	usage()
{
	std::cout << "usage: ./expert_system <file>" << std::endl;
	return (EXIT_FAILURE);
}

static void	create_facts(Hub *hub)
{
	for (int i = 0; i < 26; i++)
		hub->facts.push_back(Fact(0, 'A' + i));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (usage());
	Hub hub;
	std::srand(std::time(NULL));
	create_facts(&hub);
	get_system(&hub, av[1]);
	solve_system(&hub);
	return 0;
}