/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:21:25 by lray              #+#    #+#             */
/*   Updated: 2024/03/04 22:41:53 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "-- TEST MUTANTSTACK --" << std::endl;
		MutantStack<int> mstack;
		std::cout << "add 5 and 17" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		std::cout << "mstack.pop(), stack is 5" << std::endl;
		mstack.pop();
		std::cout << "mstack.size() = " << mstack.size() << std::endl;
		std::cout << "add 3, 5, 737, 0 to stack, stack is 5, 3, 5, 737, 0" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "- " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "-- TEST LIST --" << std::endl;
		std::list<int> lst;
		std::cout << "add 5 and 17" << std::endl;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "lst.back() = " << lst.back() << std::endl;
		std::cout << "lst.pop_back(), list is 5" << std::endl;
		lst.pop_back();
		std::cout << "lst.size() = " << lst.size() << std::endl;
		std::cout << "add 3, 5, 737, 0 to list, list is 5, 3, 5, 737, 0" << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "- " << *it << std::endl;
			++it;
		}
		std::list<int> s(lst);
	}
	return 0;
}
