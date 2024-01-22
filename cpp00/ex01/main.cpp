/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:51:24 by lray              #+#    #+#             */
/*   Updated: 2024/01/22 16:18:36 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "PhoneBook.h"

#include <string>
#include <iostream>

int main()
{
	PhoneBook	pb;

	while (true)
	{
		std::string	cmd = "";
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
			pb.addContact();
		else if (cmd.compare("SEARCH") == 0)
			pb.searchContact();
	}
	return 0;
}
