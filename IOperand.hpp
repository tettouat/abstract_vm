/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/21 13:34:10 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_H
# define IOPERAND_H

# include <string>

enum eOperandType
{
	INT8 = 0,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
};

class IOperand
{
	public:
		virtual		int				getPrecision(void) const = 0;
		virtual		eOperandType	getType(void) const = 0;

		virtual		IOperand * operator+(IOperand const &rhs) const = 0;
		virtual		IOperand * operator-(IOperand const &rhs) const = 0;
		virtual		IOperand * operator*(IOperand const &rhs) const = 0;
		virtual		IOperand * operator/(IOperand const &rhs) const = 0;
		virtual		IOperand * operator%(IOperand const &rhs) const = 0;

		virtual		std::string const & toString(void) const = 0;

		virtual		~IOperand() {}
};

#endif
