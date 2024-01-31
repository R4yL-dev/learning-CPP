/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:42:37 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 13:14:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

static bool	replace(char **argv);

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return 1;
	}
	if (!replace(argv))
		return 1;
	return 0;
}

static bool	replace(char **argv)
{
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return false;
	}
	std::ostringstream ss;
	ss << file.rdbuf();
	std::string content = ss.str();
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	std::ofstream outfile(std::string(argv[1]) + ".replace");
	if (!outfile)
	{
		std::cerr << "Error: Could not open output file " << argv[1] << ".replace" << std::endl;
		return false;
	}
	outfile << content;
	return true;
}
