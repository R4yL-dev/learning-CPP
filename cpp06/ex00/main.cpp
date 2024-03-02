/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:57:30 by lray              #+#    #+#             */
/*   Updated: 2024/03/02 14:34:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERR] 1 expected argument\n";
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	if (std::string(argv[1]) != "test")
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return 2;
		}
	}
	else
	{
		try
		{
			ScalarConverter::convert("0");
			std::cout << "----------\n";
			ScalarConverter::convert("nan");
			std::cout << "----------\n";
			ScalarConverter::convert("42.0f");
			std::cout << "----------\n";
			ScalarConverter::convert("42.42");
			std::cout << "----------\n";
			ScalarConverter::convert("100");
			std::cout << "----------\n";
			ScalarConverter::convert("424242");
			std::cout << "----------\n";
			ScalarConverter::convert("nann");
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return 0;
		}
	}
	return 0;
}
