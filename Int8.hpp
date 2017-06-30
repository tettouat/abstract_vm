/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:07 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_H
# define INT8_H

# include "Operand.hpp"

namespace AbstractVM
{
	namespace Operand
	{
		class Int8 : public Operand<int8_t>
		{
			public:
			Int8(const std::string & value);
			~Int8();
		};
	}
}

#endif
