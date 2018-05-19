/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 15:36:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

void	solve_system(Hub *hub)
{
	for (std::list <Axiom> :: iterator it = hub->axioms.begin(); it != hub->axioms.end(); it++)
	{
		it->compute_axiom();
	}
	for (std::vector <Fact> :: iterator it = hub->facts.begin(); it != hub->facts.end(); it++)
	{
		std::cout << it->symbol << ": " << it->status << std::endl;
	}
}