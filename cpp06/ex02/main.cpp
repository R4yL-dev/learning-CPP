/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:18 by lray              #+#    #+#             */
/*   Updated: 2024/03/02 19:20:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base *generate(void);
static void identify(Base *p);
static void identify(Base &p);

int main()
{
	srand(time(0));

	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return 0;
}

static Base *generate(void)
{
	int index = rand() % 3;
	switch (index)
	{
	case 0:
		std::cout << "A generated\n";
		return new A;
	case 1:
		std::cout << "B generated\n";
		return new B;
	case 2:
		std::cout << "C generated";
		return new C;
	default:
		std::cerr << "[ERROR]\n";
		return NULL;
	}
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Type: A ptr\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Type: B ptr\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Type: C ptr\n";
	else
		std::cout << "Unknown ptr\n";
}

static void identify(Base &p)
{
	try
	{
		A var = dynamic_cast<A &>(p);
		std::cout << "Type: A ref\n";
		return;
	}
	catch (std::exception &err)
	{
	}
	try
	{
		B var = dynamic_cast<B &>(p);
		std::cout << "Type: B ref\n";
		return;
	}
	catch (std::exception &err)
	{
	}
	try
	{
		C var = dynamic_cast<C &>(p);
		std::cout << "Type: C ref\n";
	}
	catch (std::exception &err)
	{
	}
}
