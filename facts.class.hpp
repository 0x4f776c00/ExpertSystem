/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facts.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:36:02 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 14:51:33 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTS_CLASS_HPP
# define FACTS_CLASS_HPP

#include "expert_system.hpp"

class Facts : public Hub
{
	public :

		const char	symbol;
		
		e_status	get_status(void);
		void		set_status(e_status);

		Facts(const char);
		~Facts(void);
		//to do: add operator overload

	private :

		e_status	_status;
};

#endif
