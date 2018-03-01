/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 14:03:59 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_CLASS_HPP
# define FORMULA_CLASS_HPP

class Formula : public Facts
{
	public :
		Facts	fact1;
		Facts	fact2;
		int		relation; //Position in fonction tab

		Formula & operator==(Formula const & rhs);
		Formula(int, Facts, Facts);
		~Formula(void);
		//operator overload
};

#endif
