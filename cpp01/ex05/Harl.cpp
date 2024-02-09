/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:06:38 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:30:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) const {
	typedef void (Harl::*FuncPtr)() const;
	FuncPtr funcs[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "Invalid level" << std::endl;
}
void Harl::debug() const {
	std::cout << "I love having extra bacon for my " <<
		"7XL-double-cheese-triple-pickle-special-ketchup burger. " <<
		"I really do!" << std::endl;
}
void Harl::info() const {
	std::cout << "I cannot believe adding extra bacon costs more money. " <<
	"You didn't put enough bacon in my burger! " <<
	"If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() const {
	std::cout << "I think I deserve to have some extra bacon for free. " <<
	"I've been coming for years whereas you started working here " <<
	"since last month." << std::endl;
}
void Harl::error() const {
	std::cout << "This is unacceptable! I want to speak to the manager now." <<
	std::endl;
}
