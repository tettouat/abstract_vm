/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:08:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/08/21 13:20:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Calculator.hpp"
#include	"Exception.hpp"

void		parseFile(std::string filename)
{
	std::ifstream			file;
	std::string				instruct;
	std::string				value;
	AbstractVM::Calculator	op;
	size_t					pos;
	size_t					pos2;

	file.open(filename.c_str());
	if (file.is_open() == false)
		throw AbstractVM::Exception("File does not exist");
	while (file.good() == true && file.eof() != true && instruct != ";;")
	{
		getline(file, instruct, '\n');
		if (instruct[0] == ';'){}
		else if (!instruct[0]) {}
		else if ((pos = instruct.find(' ')) != instruct.npos)
		{
			pos2 = pos;
			while(instruct[pos] == ' ')
			{
				pos++;
			}
			value = instruct.substr(pos, instruct.npos - 1);
			instruct = instruct.substr(0, pos2);
			op.do_instruct(instruct, value);
		}
		else
		{
			op.do_instruct(instruct);
			if (op.getStatus() == true)
				return ;
		}
	}
	file.close();
	if (instruct != "exit")
		throw AbstractVM::Exception("Last instruction should be exit");
}

void		putIntoFile()
{
	std::string	instruct = "";
	std::ofstream	file;

	file.open("/tmp/.tmpfile");
	while (instruct != ";;")
	{
		getline(std::cin, instruct);
		file << instruct << std::endl;
	}
	file.close();
	parseFile("/tmp/.tmpfile");
}

int			main(int ac, char **av)
{
	if (ac > 1)
		parseFile(av[1]);
	else
		putIntoFile();
}
