/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:48:32 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 14:37:56 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AXIOM_CLASS_HPP
# define AXIOM_CLASS_HPP

#include "expert_system.hpp"

class Axiom : public Hub
{
	public :

		Facts	fact1;
		Facts	fact2;
		bool	biconditional;
		//TODO : bool is treated (?)

		Axiom(Facts, Facts, bool);
		~Axiom(void);
}

#endif
