/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:44 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include "Exception.hpp"

AbstractVM::Exception::Exception(std::string const& message) throw() : _errorMessage(message)
{
}

AbstractVM::Exception::~Exception() throw()
{
}

const char* AbstractVM::Exception::what() const throw()
{
	return (this->_errorMessage.c_str());
}
