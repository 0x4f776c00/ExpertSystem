/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 16:49:09 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_CLASS_HPP
# define FORMULA_CLASS_HPP

#include "expert_system.hpp"

class Formula : public Facts
{
	public:
		Formula(Facts *f1, Facts *f2, int relation);
		~Formula(void);

		e_status	not_operator(Facts, Facts);
		e_status	and_operator(Facts, Facts);
		e_status	or_operator(Facts, Facts);
		e_status	xor_operator(Facts, Facts);
		static e_status	(*tab_func[NB_OPERATOR])(Facts, Facts);

		Facts	*fact1;
		Facts	*fact2;
		int		relation; //Position in fonction tab

		void	compute_status(void);



		//operator overload
};

#endif
