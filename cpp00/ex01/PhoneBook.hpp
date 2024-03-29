/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:47:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 11:31:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <climits>
#include <sstream>

#define BOOK_SIZE 8

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact() const;
private:
	Contact	_array[BOOK_SIZE];
	int		_numContact;

	std::string truncate(const std::string &str, size_t width) const;
};

#endif
