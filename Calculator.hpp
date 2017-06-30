/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 13:40:41 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 13:50:13 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CALCULATOR_H
# define	CALCULATOR_H

# include	<fstream>
# include	<iostream>
# include	<stack>
# include	"Type.hpp"

namespace	AbstractVM
{
	class		Calculator
	{
		private:
		std::stack<IOperand *> _mystack;
		std::map<std::string, void (Calculator::*)()> _mymap;
		std::map<std::string, eOperandType> _typemap;
		bool	_exit;

		public:
		Calculator();
		~Calculator();

		bool		getStatus();
		void		setType(AbstractVM::Type *, std::string &);
		void		do_instruct(std::string &);
		void		do_instruct(std::string &, std::string &);
		void		push(IOperand *);
		void		assert(IOperand *);
		void		pop();
		void		dump();
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		mod();
		void		print();
		void		exit();
	};
}

#endif
