/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandCreator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:30 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDCREATOR_H
# define OPERANDCREATOR_H

# include <string>
# include <map>
# include "IOperand.hpp"

namespace AbstractVM
{
	namespace Operand
	{
		class OperandCreator
		{
			IOperand * createInt8(const std::string & value);
			IOperand * createInt16(const std::string & value);
			IOperand * createInt32(const std::string & value);
			IOperand * createFloat(const std::string & value);
			IOperand * createDouble(const std::string & value);
			static std::map<eOperandType,IOperand*(AbstractVM::Operand::OperandCreator::*)(const std::string &)> createMap()
			{
				std::map<eOperandType,IOperand*(AbstractVM::Operand::OperandCreator::*)(const std::string &)> m;

				m[INT8] = &AbstractVM::Operand::OperandCreator::createInt8;
				m[INT16] = &AbstractVM::Operand::OperandCreator::createInt16;
				m[INT32] = &AbstractVM::Operand::OperandCreator::createInt32;
				m[FLOAT] = &AbstractVM::Operand::OperandCreator::createFloat;
				m[DOUBLE] = &AbstractVM::Operand::OperandCreator::createDouble;

				return m;
			}

			public:
			OperandCreator();
			~OperandCreator();
			static IOperand * createOperand(eOperandType type, const std::string & value);
		};
	}
}

typedef IOperand*(AbstractVM::Operand::OperandCreator::*ptr)(const std::string &);

#endif
