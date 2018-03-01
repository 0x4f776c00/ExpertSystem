/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 14:36:21 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Axiom::Axiom(Facts fact1, Facts fact2, bool bicond)
{
    this->fact1 = fact1;
    this->fact2 = fact2;
    this->biconditional = bicond;
}

Axiom::~Axiom(void)
{
    return ;
}