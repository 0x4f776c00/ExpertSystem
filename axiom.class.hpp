/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:48:32 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 12:27:37 by justasze         ###   ########.fr       */
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
		//TODO : bool is treated (?)

		Axiom(Fact *f1, Fact *f2, bool);
		~Axiom(void);
		
		void	compute_axiom();
};

#endif
