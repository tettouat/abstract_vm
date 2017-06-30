/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:02 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_H
# define INT32_H

# include "Operand.hpp"

namespace AbstractVM
{
	namespace Operand
	{
		class Int32 : public Operand<int32_t>
		{
			public:
			Int32(const std::string & value);
			~Int32();
		};
	}
}
#endif
