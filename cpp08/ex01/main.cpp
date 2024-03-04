/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:03:02 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 20:51:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <climits>

static void init_bigDeque(std::deque<int> &dq, unsigned int const size);

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	{
		std::cout << "-- TEST FROM SUBJECT --" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST COPY CONSTRUCTOR --" << std::endl;
		Span sp1(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		Span sp2(sp1);

		std::cout << "sp1.shortestSpan() = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1.longestSpan() = " << sp1.longestSpan() << std::endl;
		std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST COPY OPERATOR --" << std::endl;
		Span sp1(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		Span sp2(2);
		sp2.addNumber(42);
		sp2 = sp1;

		std::cout << "sp1.shortestSpan() = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1.longestSpan() = " << sp1.longestSpan() << std::endl;
		std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST ERRORS --" << std::endl;
		Span sp(1);

		std::cout << "- Test full -" << std::endl;
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "- Test shortestSpan error -" << std::endl;
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "- Test longestSpan error -" << std::endl;
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST 10000 --" << std::endl;
		const unsigned int spanSize = 10000;
		Span sp(spanSize);
		std::deque<int> dq;

		init_bigDeque(dq, spanSize);
		sp.addRange(dq.begin(), dq.end());
		std::cout << "dq.size() = " << dq.size() << std::endl;
		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST 100000 --" << std::endl;
		const unsigned int spanSize = 100000;
		Span sp(spanSize);
		std::deque<int> dq;

		init_bigDeque(dq, spanSize);
		sp.addRange(dq.begin(), dq.end());
		std::cout << "dq.size() = " << dq.size() << std::endl;
		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST 1000000 --" << std::endl;
		const unsigned int spanSize = 1000000;
		Span sp(spanSize);
		std::deque<int> dq;

		init_bigDeque(dq, spanSize);
		sp.addRange(dq.begin(), dq.end());
		std::cout << "dq.size() = " << dq.size() << std::endl;
		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST 10000000 --" << std::endl;
		const unsigned int spanSize = 10000000;
		Span sp(spanSize);
		std::deque<int> dq;

		init_bigDeque(dq, spanSize);
		sp.addRange(dq.begin(), dq.end());
		std::cout << "dq.size() = " << dq.size() << std::endl;
		std::cout << "sp.shortestSpan() = " << sp.shortestSpan() << std::endl;
		std::cout << "sp.longestSpan() = " << sp.longestSpan() << std::endl;
	}

	return 0;
}

static void init_bigDeque(std::deque<int> &dq, unsigned int const size)
{
	srand(static_cast<unsigned int>(time(0))); // Initialize random seed

	for (unsigned int i = 0; i < size; ++i)
	{
		unsigned int random_uint = static_cast<unsigned int>(rand()) * (static_cast<unsigned long long>(RAND_MAX) + 1) + static_cast<unsigned int>(rand());
		int random_int = static_cast<int>(random_uint / 2) - (INT_MAX / 2);
		dq.push_back(random_int);
	}
}
