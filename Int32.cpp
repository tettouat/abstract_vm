/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:00 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

AbstractVM::Operand::Int32::Int32(const std::string & value) : Operand(INT32, value)
{
}

AbstractVM::Operand::Int32::~Int32()
{
}
