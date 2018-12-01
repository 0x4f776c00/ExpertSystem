/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/12/01 02:10:30 by bcozic           ###   ########.fr       */
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
		if (hub->facts[hub->queries[it] - 'A'].status >= F_TRUE)
			std::cout << "True." << std::endl;
		else if (hub->facts[hub->queries[it] - 'A'].status <= F_FALSE)
			std::cout << "False." << std::endl;
		else
			std::cout << "Unknownable." << std::endl;
	}
}

static void	queried_arg(char *queries, Hub *hub)
{
	for (int i = 1; queries[i]; i++)
	{
		if ((uint)(queries[i] - 'A') < 26)
		{
			hub->facts[queries[i] - 'A'].used = true;
			hub->queries += queries[i];
		}
		else
			error_n_exit("Non factual query");
	}
}

static void		fact_set_truth_arg(char *truth, Hub *hub)
{
	int	status;
	for (int i = 1; truth[i]; i++)
	{
		status = F_TRUE;
		if (truth[i] == '!' && truth[i + 1])
		{
			status = F_FALSE;
			i++;
		}
		if ((uint)(truth[i] - 'A') < 26)
		{
			if (hub->facts[truth[i] - 'A'].set == true)
				error_n_exit("Fact's truth set twice");
			hub->facts[truth[i] - 'A'].set = true;
			hub->facts[truth[i] - 'A'].used = true;
			hub->facts[truth[i] - 'A'].status = status;
		}
		else
			error_n_exit("Non factual fact's truth");
	}
}

static void	get_args(int ac, char **av, Hub *hub)
{
	while (ac-- > 2)
	{
		if (!strcmp(av[ac], "-b"))
			continue ;
		else if (av[ac][0] == '=')
			fact_set_truth_arg(av[ac], hub);
		else if (av[ac][0] == '?')
			queried_arg(av[ac], hub);
		else
			error_n_exit("Two files specifieds or wrong argument");
	}
}

int		main(int ac, char **av)
{
	Hub		hub;
	int		default_status;

	default_status = B_FALSE;
	if (ac < 2)
		return (usage());
	if (ac > 2 && !strcmp(av[2], "-b"))
		default_status = PENDING;

	std::srand(std::time(NULL));
	create_facts(&hub, default_status);
	get_system(&hub, av[1]);
	get_args(ac, av, &hub);
	solve_system(&hub);
	display_system(&hub);

	return 0;
}
