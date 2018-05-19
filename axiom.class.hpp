/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:48:32 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 17:27:30 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AXIOM_CLASS_HPP
# define AXIOM_CLASS_HPP

#include "expert_system.hpp"

class Axiom : public Hub
{
	public:

		Facts	*fact1;
		Facts	*fact2;
		bool	biconditional;
		//TODO : bool is treated (?)

		Axiom(Facts *f1, Facts *f2, bool);
		~Axiom(void);
		
		void	compute_axiom();
};

#endif
