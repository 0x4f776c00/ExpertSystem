/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 15:21:16 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_CLASS_HPP
# define FORMULA_CLASS_HPP

#include "expert_system.hpp"

class Formula : public Facts
{
	public :
		Facts	*fact1;
		Facts	*fact2;
		int		relation; //Position in fonction tab
		e_status	(*tab_func[NB_OPERATOR])(Facts, Facts);

		void	compute_status(void);

		Formula(int, Facts *f1, Facts *f2);
		~Formula(void);

		//operator overload
};

#endif
