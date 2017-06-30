/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 13:40:41 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 13:50:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<cstdlib>
#include		<sstream>
#include		<list>
#include		"Calculator.hpp"
#include		"Exception.hpp"
#include		"OperandCreator.hpp"

AbstractVM::Calculator::Calculator() : _exit(false)
{
	this->_mymap["pop"] = &AbstractVM::Calculator::pop;
	this->_mymap["dump"] = &AbstractVM::Calculator::dump;
	this->_mymap["add"] = &AbstractVM::Calculator::add;
	this->_mymap["sub"] = &AbstractVM::Calculator::sub;
	this->_mymap["mul"] = &AbstractVM::Calculator::mul;
	this->_mymap["div"] = &AbstractVM::Calculator::div;
	this->_mymap["mod"] = &AbstractVM::Calculator::mod;
	this->_mymap["print"] = &AbstractVM::Calculator::print;
	this->_mymap["exit"] = &AbstractVM::Calculator::exit;
}

AbstractVM::Calculator::~Calculator()
{
}

bool		AbstractVM::Calculator::getStatus()
{
	return this->_exit;
}

void		AbstractVM::Calculator::setType(AbstractVM::Type *type, std::string &value)
{
	size_t	pos;

	if (value.find('(') == value.npos || value.find(')') == value.npos)
		throw AbstractVM::Exception("Invalid value");
	pos = value.find('(');
	type->setType(value.substr(0, pos));
	type->setValue(value.substr(pos + 1, value.find(')') - pos - 1));
}

void		AbstractVM::Calculator::do_instruct(std::string &instruct)
{
	if (this->_mymap.find(instruct) == this->_mymap.end())
		throw AbstractVM::Exception("Instruction doesn't exist");
	((this)->*(this->_mymap[instruct]))();
}

void		AbstractVM::Calculator::do_instruct(std::string &instruct, std::string &value)
{
	IOperand		*newOp;
	AbstractVM::Type	type;

	(void)instruct;
	setType(&type, value);
	type.checkType();
	type.checkValue();
	newOp = AbstractVM::Operand::OperandCreator::createOperand(type.getTypemap(type.getType()), type.getValue());

	if (instruct == "push")
		this->push(newOp);
	else if (instruct == "assert")
		this->assert(newOp);
	else
		throw AbstractVM::Exception("Invalid instruction");
}

void		AbstractVM::Calculator::assert(IOperand *Op)
{
	if (Op->getType() != this->_mystack.top()->getType() || Op->toString() != this->_mystack.top()->toString())
		throw AbstractVM::Exception("assert fail");
}

void		AbstractVM::Calculator::push(IOperand *value)
{
	_mystack.push(value);
}

void		AbstractVM::Calculator::pop()
{
	if (_mystack.empty() == true)
		throw AbstractVM::Exception("Stack is empty");
	_mystack.pop();
}

void		AbstractVM::Calculator::dump()
{
	std::list<IOperand *> mylist;

	if (_mystack.empty() == true)
	{
		std::cout << "Stack is empty" << std::endl;
		return ;
	}

	std::cout << "Stack dump :" << std::endl;

	while (!this->_mystack.empty())
	{
		mylist.push_front(_mystack.top());
		this->pop();
		std::cout << mylist.front()->toString() << std::endl;
	}

	for (std::list<IOperand *>::iterator it = mylist.begin(); it != mylist.end(); it++)
		this->push((*it));
}

void		AbstractVM::Calculator::add()
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	if (_mystack.size() < 2)
		throw AbstractVM::Exception("Not enough operands in the stack");

	op1 = _mystack.top();
	_mystack.pop();
	op2 = _mystack.top();
	_mystack.pop();
	res = *op1 + *op2;
	this->push(res);
}

void		AbstractVM::Calculator::sub()
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	if (_mystack.size() < 2)
		throw AbstractVM::Exception("Not enough operands in the stack");

	op1 = _mystack.top();
	_mystack.pop();
	op2 = _mystack.top();
	_mystack.pop();
	res = *op1 - *op2;
	this->push(res);
}

void		AbstractVM::Calculator::mul()
{
  IOperand	*res;
  IOperand	*op1;
  IOperand	*op2;

  if (_mystack.size() < 2)
	throw AbstractVM::Exception("Not enough operands in the stack");
  op1 = _mystack.top();
  _mystack.pop();
  op2 = _mystack.top();
  _mystack.pop();
  res = *op1 * *op2;
  this->push(res);
}

void		AbstractVM::Calculator::div()
{
  IOperand	*res;
  IOperand	*op1;
  IOperand	*op2;

  if (_mystack.size() < 2)
	throw AbstractVM::Exception("Not enough operands in the stack");
  op1 = _mystack.top();
  _mystack.pop();
  op2 = _mystack.top();
  _mystack.pop();
  res = *op1 / *op2;
  this->push(res);
}

void		AbstractVM::Calculator::mod()
{
	IOperand	*res;
	IOperand	*op1;
	IOperand	*op2;

	if (_mystack.size() < 2)
		throw AbstractVM::Exception("Not enough operands in the stack");

	op1 = _mystack.top();
	_mystack.pop();
	op2 = _mystack.top();
	_mystack.pop();
	res = *op1 % *op2;
	this->push(res);
}

void		AbstractVM::Calculator::print()
{
	if (_mystack.size() < 1)
		throw AbstractVM::Exception("Stack is empty");
	if (_mystack.top()->getType() == INT8)
		std::cout << std::atoi(_mystack.top()->toString().c_str()) - '0' << std::endl;
	else
		throw AbstractVM::Exception("Value is not of type Int8");
}

void		AbstractVM::Calculator::exit()
{
	this->_exit = true;
}
