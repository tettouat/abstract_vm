/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:55 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int16.hpp"

AbstractVM::Operand::Int16::Int16(const std::string & value) : Operand(INT16, value)
{
}

AbstractVM::Operand::Int16::~Int16()
{
}
