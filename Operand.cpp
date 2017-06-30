/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:21 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include "OperandCreator.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

template			<typename T>
AbstractVM::Operand::Operand<T>::Operand(eOperandType type, const std::string & value) : _type(type)
{
	std::stringstream	ss;

	ss.str(value);
	this->_str = ss.str();

	if (std::atof(value.c_str()) > std::numeric_limits<T>::max())
		throw AbstractVM::Exception("Overflow on value");
	else if (std::atof(value.c_str()) < -std::numeric_limits<T>::max() - 1)
		throw AbstractVM::Exception("Underflow on value");
}

template			<typename T>
AbstractVM::Operand::Operand<T>::~Operand()
{
}

template			<typename T>
int					AbstractVM::Operand::Operand<T>::getPrecision() const
{
	return (this->_type);
}

template			<typename T>
eOperandType		AbstractVM::Operand::Operand<T>::getType() const
{
	return (this->_type);
}

template			<typename T>
std::string const & AbstractVM::Operand::Operand<T>::toString() const
{
	return (this->_str);
}

template			<typename T>
IOperand * 			AbstractVM::Operand::Operand<T>::operator+(const IOperand & rhs) const
{
	IOperand 		*newOp;
	double		tmp;
	double		leftOperand = std::atof(this->toString().c_str());
	double		rightOperand = std::atof(rhs.toString().c_str());
	std::ostringstream	strs;

	if ((rightOperand > 0) && (leftOperand > std::numeric_limits<double>::max() - rightOperand))
		throw AbstractVM::Exception("Overflow on a value");
	if ((rightOperand < 0) && (leftOperand < -std::numeric_limits<double>::max() - rightOperand - 1))
		throw AbstractVM::Exception("Underflow on a value");

	tmp = leftOperand + rightOperand;
	strs << tmp;

	if (this->getPrecision() > rhs.getPrecision())
		newOp = AbstractVM::Operand::OperandCreator::createOperand(this->getType(), strs.str());
	else
		newOp = AbstractVM::Operand::OperandCreator::createOperand(rhs.getType(), strs.str());

	return (newOp);
}

template			<typename T>
IOperand * 			AbstractVM::Operand::Operand<T>::operator-(const IOperand & rhs) const
{
	IOperand 		*newOp;
	double		tmp;
	double		leftOperand = std::atof(this->toString().c_str());
	double		rightOperand = std::atof(rhs.toString().c_str());
	std::ostringstream  strs;

	if ((rightOperand > 0) && (leftOperand > std::numeric_limits<double>::max() + rightOperand))
		throw AbstractVM::Exception("Overflow on a value");
	if ((rightOperand < 0) && (leftOperand < -std::numeric_limits<double>::max() + rightOperand - 1))
		throw AbstractVM::Exception("Underflow on a value");

	tmp = leftOperand - rightOperand;
	strs << tmp;

	if (this->getPrecision() > rhs.getPrecision())
		newOp = AbstractVM::Operand::OperandCreator::createOperand(this->getType(), strs.str());
	else
		newOp = AbstractVM::Operand::OperandCreator::createOperand(rhs.getType(), strs.str());

	return (newOp);
}

template 			<typename T>
IOperand * 			AbstractVM::Operand::Operand<T>::operator*(const IOperand & rhs) const
{
	IOperand 		*newOp;
	double		tmp;
	double		leftOperand = std::atof(this->toString().c_str());
	double		rightOperand = std::atof(rhs.toString().c_str());
	std::ostringstream  strs;

	if ((rightOperand > 0) && (leftOperand > std::numeric_limits<double>::max() / rightOperand))
		throw AbstractVM::Exception("Overflow on a value");
	if ((rightOperand < 0) && (leftOperand < -std::numeric_limits<double>::max() / rightOperand - 1))
		throw AbstractVM::Exception("Underflow on a value");

	tmp = leftOperand * rightOperand;
	strs << tmp;

	if (this->getPrecision() > rhs.getPrecision())
		newOp = AbstractVM::Operand::OperandCreator::createOperand(this->getType(), strs.str());
	else
		newOp = AbstractVM::Operand::OperandCreator::createOperand(rhs.getType(), strs.str());

	return (newOp);
}

template 			<typename T>
IOperand * 			AbstractVM::Operand::Operand<T>::operator/(const IOperand & rhs) const
{
	IOperand	*newOp;
	double		tmp;
	double		leftOperand = std::atof(this->toString().c_str());
	double		rightOperand = std::atof(rhs.toString().c_str());
	std::ostringstream  strs;

	if ((rightOperand > 0) && (leftOperand > std::numeric_limits<double>::max() * rightOperand))
		throw AbstractVM::Exception("Overflow on a value");
	if ((rightOperand < 0) && (leftOperand < -std::numeric_limits<double>::max() * rightOperand - 1))
		throw AbstractVM::Exception("Underflow on a value");
	if (rhs.toString() == "0")
		throw AbstractVM::Exception("Division by 0");

	tmp = leftOperand / rightOperand;
	strs << tmp;

	if (this->getPrecision() > rhs.getPrecision())
		newOp = AbstractVM::Operand::OperandCreator::createOperand(this->getType(), strs.str());
	else
		newOp = AbstractVM::Operand::OperandCreator::createOperand(rhs.getType(), strs.str());

	return (newOp);
}

template			<typename T>
IOperand * 			AbstractVM::Operand::Operand<T>::operator%(const IOperand & rhs) const
{
	IOperand 		*newOp;
	int32_t 		tmp;
	int32_t    leftOperand = std::atoi(this->toString().c_str());
	int32_t    rightOperand = std::atoi(rhs.toString().c_str());
	std::ostringstream  strs;

	if ((rightOperand > 0) && (leftOperand > std::numeric_limits<int32_t>::max() - rightOperand))
		throw AbstractVM::Exception("Overflow on a value");
	if ((rightOperand < 0) && (leftOperand < -std::numeric_limits<int32_t>::max() - rightOperand - 1))
		throw AbstractVM::Exception("Underflow on a value");
	if (this->getPrecision() > INT32 || rhs.getPrecision() > INT32)
		throw AbstractVM::Exception("Modulo with decimal");
	if (rhs.toString() == "0")
		throw AbstractVM::Exception("Mobulo by 0");

	tmp = leftOperand % rightOperand;
	strs << tmp;

	if (this->getPrecision() > rhs.getPrecision())
		newOp = AbstractVM::Operand::OperandCreator::createOperand(this->getType(), strs.str());
	else
		newOp = AbstractVM::Operand::OperandCreator::createOperand(rhs.getType(), strs.str());

	return (newOp);
}

template AbstractVM::Operand::Operand<int8_t>::Operand(eOperandType type, const std::string & value);
template AbstractVM::Operand::Operand<int16_t>::Operand(eOperandType type, const std::string & value);
template AbstractVM::Operand::Operand<int32_t>::Operand(eOperandType type, const std::string & value);
template AbstractVM::Operand::Operand<float>::Operand(eOperandType type, const std::string & value);
template AbstractVM::Operand::Operand<double>::Operand(eOperandType type, const std::string & value);
