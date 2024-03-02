/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:14:22 by lray              #+#    #+#             */
/*   Updated: 2024/03/02 14:31:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isSpe(std::string const &str, std::string const (&set)[9][5], int &id);
static bool isChar(std::string const &str);
static bool isInt(std::string const &str);
static bool isFloat(std::string const &str);
static bool isDouble(std::string const &str);
static void showResult(char value);
static void showResult(int value);
static void showResult(float value);
static void showResult(double value);
static void showResult(std::string const (&set)[5]);

void ScalarConverter::convert(std::string const &str)
{
	std::string specialsSet[9][5] = {
		{"+inff", "impossible", "impossible", "inff", "inf"},
		{"inff", "impossible", "impossible", "inff", "inf"},
		{"-inff", "impossible", "impossible", "-inff", "-inf"},
		{"nanf", "impossible", "impossible", "nanf", "nan"},
		{"+inf", "impossible", "impossible", "inff", "inf"},
		{"inf", "impossible", "impossible", "inff", "inf"},
		{"-inf", "impossible", "impossible", "-inff", "-inf"},
		{"nan", "impossible", "impossible", "nanf", "nan"},
		{"", "", "", "", ""}};
	int speID = -1;

	if (isSpe(str, specialsSet, speID))
	{
		showResult(specialsSet[speID]);
	}
	else if (isChar(str))
	{
		showResult(str[0]);
	}
	else if (isInt(str))
	{
		showResult(std::atoi(str.c_str()));
	}
	else if (isFloat(str))
	{
		showResult(static_cast<float>(std::atof(str.c_str())));
	}
	else if (isDouble(str))
	{
		showResult(std::atof(str.c_str()));
	}
	else
	{
		throw(ScalarConverter::InvalideCastException());
	}
}

const char *ScalarConverter::InvalideCastException::what() const throw()
{
	return "Invalide cast, unknown input type";
}

static bool isSpe(std::string const &str, std::string const (&set)[9][5], int &id)
{
	for (int i = 0; i < 9; i++)
	{
		if (str == set[i][0])
		{
			id = i;
			return true;
		}
	}
	return false;
}

static bool isChar(std::string const &str)
{
	if (str.size() != 1 || std::isdigit(str[0]) || !std::isprint(str[0]))
		return false;
	return true;
}

static bool isInt(std::string const &str)
{
	char *end;
	long int convert = std::strtol(str.c_str(), &end, 10);

	if (end != str.c_str() && *end == '\0')
	{
		if (convert < INT_MIN || convert > INT_MAX)
			return false;
		return true;
	}
	else
		return false;
}

static bool isFloat(std::string const &str)
{
	if (str[str.size() - 1] != 'f')
		return false;
	int count = 0;
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			count++;
	}
	if (count != 1)
		return false;
	std::string::size_type firstNonSpace = str.find_first_not_of(' ');
	if (firstNonSpace == std::string::npos || str[firstNonSpace] == '.')
		return false;
	char *end;
	double convert = std::strtod(str.c_str(), &end);
	if (end != str.c_str() && *end == 'f' && *(end + 1) == '\0')
	{
		if (convert < -FLT_MAX || convert > FLT_MAX)
			return false;
		return true;
	}
	else
	{
		return false;
	}
}

static bool isDouble(std::string const &str)
{
	if (str[str.size() - 1] == 'f' || str[str.size() - 1] == '.')
		return false;
	int count = 0;
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			count++;
	}
	if (count != 1)
		return false;
	std::string::size_type firstNonSpace = str.find_first_not_of(' ');
	if (firstNonSpace == std::string::npos || str[firstNonSpace] == '.')
		return false;
	char *end;
	double convert = std::strtod(str.c_str(), &end);
	if (end != str.c_str() && *end == '\0')
	{
		if (convert < -DBL_MAX || convert > DBL_MAX)
			return false;
		return true;
	}
	else
	{
		return false;
	}
}

static void showResult(char value)
{
	int i = static_cast<int>(value);
	int f = static_cast<float>(value);
	int d = static_cast<double>(value);

	std::cout << "char: '" << value << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0" << std::endl;
}

static void showResult(int value)
{
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (value > CHAR_MIN && value < CHAR_MAX && std::isprint(value))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << value << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0" << std::endl;
}

static void showResult(float value)
{
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: ";
	if (value == i)
		std::cout << value << ".0f\n";
	else
		std::cout << value << "f\n";
	std::cout << "double: ";
	if (d == i)
		std::cout << d << ".0" << std::endl;
	else
		std::cout << d << std::endl;
}

static void showResult(double value)
{
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);

	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: ";
	if (f == i)
		std::cout << f << ".0f\n";
	else
		std::cout << f << "f\n";
	std::cout << "double: ";
	if (value == i)
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

static void showResult(std::string const (&set)[5])
{
	std::cout << "char: " << set[1] << "\n";
	std::cout << "int: " << set[2] << "\n";
	std::cout << "float: " << set[3] << "\n";
	std::cout << "double: " << set[4] << std::endl;
}
