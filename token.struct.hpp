/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.struct.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:09:11 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/02 19:12:56 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STRUCT_HPP
# define TOKEN_STRUCT_HPP

#include "expert_system.hpp"

struct Token
{
	char			symbol;
	e_token_type	type;
	Token(char symbol);
	~Token(void);
};

#endif