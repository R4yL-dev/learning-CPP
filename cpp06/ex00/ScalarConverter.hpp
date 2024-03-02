/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:10:55 by lray              #+#    #+#             */
/*   Updated: 2024/03/02 14:31:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

class ScalarConverter
{

public:
	static void convert(std::string const &str);

	class InvalideCastException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	ScalarConverter();
};

#endif
