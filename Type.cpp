/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:34 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Type.hpp"
#include "Exception.hpp"

AbstractVM::Type::Type()
{
	this->_typemap["int8"] = INT8;
	this->_typemap["int16"] = INT16;
	this->_typemap["int32"] = INT32;
	this->_typemap["float"] = FLOAT;
	this->_typemap["double"] = DOUBLE;
}

AbstractVM::Type::~Type() {}

std::string	AbstractVM::Type::getType() const
{
	return this->_type;
}

std::string	AbstractVM::Type::getValue() const
{
	return this->_value;
}

void		AbstractVM::Type::setType(std::string type)
{
	this->_type = type;
}

void		AbstractVM::Type::setValue(std::string value)
{
	this->_value = value;
}

void		AbstractVM::Type::checkType()
{
	if (this->_typemap.find(this->_type) == this->_typemap.end())
		throw AbstractVM::Exception("Invalid Type");
}

void		AbstractVM::Type::checkValue()
{
	size_t	found;
	size_t	pos;
	int		mycount = std::count(this->_value.begin(), this->_value.end(), '.');

	if (this->_value == "")
		throw AbstractVM::Exception("Invalid value");
	if (this->_typemap[this->getType()] > INT32)
		found = this->_value.find_first_not_of("-0123456789.");
	else
		found = this->_value.find_first_not_of("-0123456789");
	if ((pos = this->_value.find_last_of('-')) != this->_value.npos && pos != 0)
		throw AbstractVM::Exception("Invalid value");
	if ((this->_value[0] == '.' || this->_value[this->_value.npos] == '.') || (this->_value[0] == '-' && this->_value[1] == '.'))
		throw AbstractVM::Exception("Invalid value");
	if (mycount > 1)
		throw AbstractVM::Exception("Invalid value");
	if (found != this->_value.npos)
		throw AbstractVM::Exception("Invalid value");
}

eOperandType	AbstractVM::Type::getTypemap(std::string type)
{
	return this->_typemap[type];
}
