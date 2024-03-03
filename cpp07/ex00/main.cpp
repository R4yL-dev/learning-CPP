/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:43:31 by lray              #+#    #+#             */
/*   Updated: 2024/03/03 20:16:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min.hpp"
#include "max.hpp"
#include "swap.hpp"
#include <string>
#include <iostream>

int main()
{
	{
		int a = 2;
		int b = 3;

		std::cout << "--- INT ---" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << "swap(a, b)" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{
		float c = 2.22;
		float d = 2.42;

		std::cout << "--- FLOAT ---" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
		std::cout << "swap(c, d)" << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	std::cout << std::endl;
	{
		std::string e = "chaine1";
		std::string f = "chaine2";

		std::cout << "--- STRING ---" << std::endl;
		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "mix(e, f) = " << ::min(e, f) << std::endl;
		std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
		std::cout << "swap(e, f)" << std::endl;
		::swap(e, f);
		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "mix(e, f) = " << ::min(e, f) << std::endl;
		std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	}
	return 0;
}
