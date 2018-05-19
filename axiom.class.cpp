/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/10 17:34:45 by bcozic           ###   ########.fr       */
=======
/*   Updated: 2018/05/19 10:55:39 by justasze         ###   ########.fr       */
>>>>>>> e4af69235dea7b2227aa409141a02169dbee469f
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Axiom::Axiom(Fact *f1, Fact *f2, bool bicond)
{
	this->fact1 = f1;
	this->fact2 = f2;
	this->biconditional = bicond;
}

Axiom::~Axiom(void)
{
	return ;
}

void	Axiom::compute_axiom()
{
		std::cout << "bicond: " << this->biconditional << std::endl;
		this->fact1->compute_status();
		std::cout << "\n";
		this->fact2->compute_status();
	//this->set_status(tab_func[this->relation](*this->fact1, *this->fact2));
}
