/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:47:53 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 16:25:22 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <iomanip>
#include <climits>

#define BOOK_SIZE 2

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact();
private:
	Contact	m_array[BOOK_SIZE];
	int		m_numContact;

	std::string truncate(const std::string &str, size_t width) const;
};

#endif
