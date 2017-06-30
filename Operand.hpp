/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

# include	<stdint.h>
# include	"IOperand.hpp"

namespace AbstractVM
{
	namespace Operand
	{
		template <typename T>
		class 	Operand : public IOperand
		{
			protected:
			eOperandType	_type;
			std::string 	_str;

			public:
			virtual std::string const & toString() const;
			virtual int getPrecision() const;
			virtual eOperandType getType() const;
			virtual IOperand * operator+(const IOperand &rhs) const;
			virtual IOperand * operator-(const IOperand &rhs) const;
			virtual IOperand * operator*(const IOperand &rhs) const;
			virtual IOperand * operator/(const IOperand &rhs) const;
			virtual IOperand * operator%(const IOperand &rhs) const;
			Operand(eOperandType type, const std::string & value);
			virtual ~Operand();
		};
	}
}

#endif
