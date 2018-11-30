/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:46:32 by justasze          #+#    #+#             */
/*   Updated: 2018/11/30 22:52:19 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

int	error_n_exit(std::string str)
{
	int		random_snark = std::rand() % NB_SNARK;

	std::cerr << "Error: " << str << std::endl;
	(void)random_snark;
	// std::cerr << snark_tab[random_snark] << std::endl;
	exit (EXIT_FAILURE);
}
