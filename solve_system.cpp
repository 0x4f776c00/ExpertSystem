/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_system.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:22:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 17:20:34 by justasze         ###   ########.fr       */
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