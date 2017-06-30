/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/19 14:21:47 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

#include <string>
#include <exception>

namespace AbstractVM
{
	class Exception : public std::exception
	{
		public:
		Exception(std::string const& msg) throw();
		virtual ~Exception() throw();
		virtual const char* what() const throw();

		private:
		std::string _errorMessage;
	};
}
#endif
