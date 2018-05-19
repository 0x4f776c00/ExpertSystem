/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:48:32 by bcozic            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/10 17:27:30 by bcozic           ###   ########.fr       */
=======
/*   Updated: 2018/05/19 10:55:35 by justasze         ###   ########.fr       */
>>>>>>> e4af69235dea7b2227aa409141a02169dbee469f
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
