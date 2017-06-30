/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandCreator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:27 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OperandCreator.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Double.hpp"
#include "Float.hpp"

AbstractVM::Operand::OperandCreator::OperandCreator()
{
}

AbstractVM::Operand::OperandCreator::~OperandCreator()
{
}

IOperand * AbstractVM::Operand::OperandCreator::createOperand(eOperandType type, const std::string & value)
{
	OperandCreator *p = NULL;
	static std::map<eOperandType, IOperand*(AbstractVM::Operand::OperandCreator::*)(const std::string &)> _operandMap = AbstractVM::Operand::OperandCreator::createMap();
	ptr create;

	create = _operandMap[type];

	return ((p->*create)(value));
}

IOperand*	AbstractVM::Operand::OperandCreator::createInt8(const std::string & value)
{
	return (new AbstractVM::Operand::Int8(value));
}

IOperand*	AbstractVM::Operand::OperandCreator::createInt16(const std::string & value)
{
	return (new AbstractVM::Operand::Int16(value));
}

IOperand*	AbstractVM::Operand::OperandCreator::createInt32(const std::string & value)
{
	return (new AbstractVM::Operand::Int32(value));
}

IOperand*	AbstractVM::Operand::OperandCreator::createFloat(const std::string & value)
{
	return (new AbstractVM::Operand::Float(value));
}

IOperand*	AbstractVM::Operand::OperandCreator::createDouble(const std::string & value)
{
	return (new AbstractVM::Operand::Double(value));
}
