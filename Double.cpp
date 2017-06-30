/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:39 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Double.hpp"

AbstractVM::Operand::Double::Double(const std::string & value) : Operand(DOUBLE, value)
{
}

AbstractVM::Operand::Double::~Double()
{
}
