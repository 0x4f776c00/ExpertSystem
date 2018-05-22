/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:36:02 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 14:21:59 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTS_CLASS_HPP
# define FACTS_CLASS_HPP

#include "expert_system.hpp"
#include "hub.class.hpp"

class Fact : public Hub
{
	public:

		int			type;
		const char	symbol;
		bool		queried;
		e_status	status;
		e_status	get_status(void);
		void		set_status(e_status);

		Fact(int type, const char);
		Fact(void);
		~Fact(void);

		bool	compute_status(void);
};

std::ostream & operator<<(std::ostream & o, const Fact & fact);

#endif
