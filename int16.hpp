/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:58 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_H
# define INT16_H

# include "Operand.hpp"

namespace AbstractVM
{
	namespace Operand
	{
		class Int16 : public Operand<int16_t>
		{
			public:
			Int16(const std::string & value);
			~Int16();
		};
	}
}

#endif
