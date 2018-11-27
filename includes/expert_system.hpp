/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/27 22:09:32 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>

enum e_token_type {INVALID, OPERATOR, FACT, RELATION, SEPARATOR, TRUTH, QUERY};
enum e_relations {NOT, XOR, OR, AND};

# define FORMULA		1
# define NB_OPERATOR	4
# define NB_SNARK		3
# define NON_ACTUALISED	0
# define ACTUALISED		1
# define ERROR			2

# define F_FALSE	-3
# define T1_FALSE	-2
# define T2_FALSE	-1
# define PENDING	0
# define F_TRUE		1
# define T1_TRUE	2
# define T2_TRUE	3

constexpr const char *snark_tab[NB_SNARK] =
{
	"You are bad, and you should feel bad.",
	"Unbelievable. You, [subject name here], must be the pride of [subject hometown here]!",
	"Well done. Here come the test results: \"You are a horrible person.\" That's what it says. We weren't even testing for that."
};

# include "fact.class.hpp"
# include "hub.class.hpp"
# include "formula.class.hpp"
# include "axiom.class.hpp"
# include "token.struct.hpp"

void	get_system(Hub *hub, char *file_name);
void	parse_system(std::vector <std::vector <Token>> tokens, Hub *hub);
int		error_n_exit(std::string str);
void	solve_system(Hub *hub);

#endif
