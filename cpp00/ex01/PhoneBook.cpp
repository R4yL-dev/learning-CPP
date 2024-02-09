/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:48:59 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 11:31:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_numContact = 0;
}

PhoneBook::~PhoneBook()
{
}


void PhoneBook::addContact()
{
	if (_numContact > 0)
	{
		for (int i = BOOK_SIZE - 1; i > 0; --i)
		{
			_array[i] = _array[i - 1];
		}
	}
	_array[0].fillContactInfo();
	if (_numContact < BOOK_SIZE)
		_numContact++;
}

void PhoneBook::searchContact() const
{
	std::cout << "| " << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nickname" << " |"<< std::endl;
	std::cout << "| ---------- | ---------- | ---------- | ---------- |" << std::endl;
	for (int i = 0; i < _numContact; ++i)
	{
		std::cout << "| " << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << truncate(_array[i].getFirstName(), 10) << " | ";
		std::cout << std::setw(10) << truncate(_array[i].getLastName(), 10) << " | ";
		std::cout << std::setw(10) << truncate(_array[i].getNickName(), 10) << " |";
		std::cout << std::endl;
	}
	int id = -1;
	if (_numContact > 0)
	{
		std::string input;
		do
		{
			std::cout << "Enter index: ";
			std::getline(std::cin, input);
			bool allDigits = true;
			for (std::string::size_type i = 0; i < input.length(); ++i)
			{
				if (!std::isdigit(input[i]))
				{
					allDigits = false;
					break;
				}
				if (allDigits)
					std::istringstream(input) >> id;
			}
		} while (id < 1 || id > _numContact);
		_array[id - 1].print();

	}
}

std::string	PhoneBook::truncate(const std::string &str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

