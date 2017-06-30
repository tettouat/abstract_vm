/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:38 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <map>
# include <iostream>
# include "IOperand.hpp"

namespace	AbstractVM
{
	class		Type
	{
		private:
		std::string	_type;
		std::string	_value;
		std::map<std::string , eOperandType> _typemap;

		public:
		Type();
		~Type();
		std::string		getType() const;
		std::string		getValue() const;
		eOperandType	getTypemap(std::string);
		void		setType(std::string);
		void		setValue(std::string);
		void		checkType();
		void		checkValue();
	};
}

#endif
