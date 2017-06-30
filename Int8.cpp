/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:22:05 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

AbstractVM::Operand::Int8::Int8(const std::string & value) : Operand(INT8, value)
{
}

AbstractVM::Operand::Int8::~Int8()
{
}
