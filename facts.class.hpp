/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facts.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:36:02 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/01 18:05:40 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTS_CLASS_HPP
# define FACTS_CLASS_HPP

#include "expert_system.hpp"
#include "hub.class.hpp"

class Facts : public Hub
{
	public:

		const char	symbol;
		bool		queried;
		
		e_status	get_status(void);
		void		set_status(e_status);

		Facts(const char);
		Facts(void);
		~Facts(void);
		//to do: add operator overload

	private:

		e_status	_status;
};

std::ostream & operator<<(std::ostream & o, const Facts & fact);

#endif
