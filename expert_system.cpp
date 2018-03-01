/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:18:17 by justasze          #+#    #+#             */
/*   Updated: 2018/03/01 17:58:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

int		main()
{
	Facts a('A');
	a.set_status(F_TRUE);
	Facts b('B');
	b.set_status(F_TRUE);
	Facts c('C');
	c.set_status(F_FALSE);

	Formula x(&a, &b, 1);
	Formula y(&a, &b, 2);
	Formula z(&a, &c, 1);

	x.compute_status();
	y.compute_status();
	z.compute_status();

	return 0;
}
