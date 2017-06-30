/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:50 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

AbstractVM::Operand::Float::Float(const std::string & value) : Operand(FLOAT, value)
{
}

AbstractVM::Operand::Float::~Float()
{
}
