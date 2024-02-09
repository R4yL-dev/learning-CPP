/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:07:21 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 11:25:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

std::string strToUpper(const std::string &str);

int	main(int argc, char **argv)
{
	std::string msg;

	if (argc <= 1)
	{
		msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		std::stringstream ss;
		for (int i = 1; i < argc; ++i)
		{
			ss << argv[i] << " ";
		}
		msg = ss.str();
		msg = strToUpper(msg);
	}
	std::cout << msg << std::endl;
	return 0;
}

std::string strToUpper(const std::string &str)
{
	std::string res = str;
	for (size_t i = 0; i < res.length(); ++i) {
		res[i] = std::toupper(str[i]);
	}
	return res;
}
