/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:48:32 by bcozic            #+#    #+#             */
/*   Updated: 2018/06/02 15:08:52 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AXIOM_CLASS_HPP
# define AXIOM_CLASS_HPP

#include "expert_system.hpp"

class Axiom : public Hub
{
	public:

		Fact	*fact1;
		Fact	*fact2;
		bool	biconditional;

		Axiom(Fact *f1, Fact *f2, bool);
		~Axiom(void);
		
		bool	compute_axiom(bool testing);
};

#endif
