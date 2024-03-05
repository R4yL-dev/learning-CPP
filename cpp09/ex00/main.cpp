/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:13:09 by lray              #+#    #+#             */
/*   Updated: 2024/03/05 20:40:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

static void showUsage();

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		showUsage();
		return 1;
	}

	try
	{
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			std::cerr << RED << "[!] " << argv[1] << RESET<< std::endl;
			throw std::runtime_error("cannot open input file");
		}
		std::cout << CYAN << "[?] input file has been successfully opened" << RESET << std::endl;
		BitcoinExchange be("data.csv");

		std::string line;
		int i = 1;
		while (std::getline(file, line))
		{
			try
			{
				std::stringstream ss(line);
				std::string date;
				float value;
				if (!(std::getline(ss, date, ' ') && ss.ignore(2) && ss >> value))
					throw std::runtime_error("invalid entry in input file");
				be.getExchangeRate(date, value);
			}
			catch (std::exception &err)
			{
				std::cerr << RED << "[!] input file: line " << i  << ": " << err.what() << RESET << std::endl;
			}
			++i;
		}
	}
	catch (std::exception &err)
	{
		std::cerr << RED << "[!] " << err.what() << RESET << std::endl;
		return 2;
	}
	return 0;
}
static void showUsage()
{
	std::cerr << "Usage: ./btc <path>\n\t<path>: Path to a file" << std::endl;
	std::cout << "\tFile format:" << std::endl;
	std::cout << "\t\t- each line must be: <date> | <value>" << std::endl;
	std::cout << "\t\t- <date>: Year-Month-Day" << std::endl;
	std::cout << "\t\t- <value>: must be either a float or a positive integer, between 0 and 100" << std::endl;
}
