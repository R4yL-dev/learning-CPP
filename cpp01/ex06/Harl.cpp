/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:06:38 by lray              #+#    #+#             */
/*   Updated: 2024/01/31 15:47:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(const std::string &level) const {
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
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "Invalid level" << std::endl;
}
void Harl::complain(const std::string &level, const std::string &filter) const {
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
	if (get_level(filter) < 0) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	if (get_level(level) >= get_level(filter))
	{
		switch(get_level(level)) {
			case 0:
				(this->*funcs[0])();
				break;
			case 1:
				(this->*funcs[1])();
				break;
			case 2:
				(this->*funcs[2])();
				break;
			case 3:
				(this->*funcs[3])();
				break;
		}
	}
}
void Harl::debug() const {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my " <<
		"7XL-double-cheese-triple-pickle-special-ketchup burger. " <<
		"I really do!" << std::endl;
}
void Harl::info() const {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " <<
	"You didn't put enough bacon in my burger! " <<
	"If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning() const {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " <<
	"I've been coming for years whereas you started working here " <<
	"since last month." << std::endl;
}
void Harl::error() const {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." <<
	std::endl;
}

int	get_level(const std::string &level) {
	if (level == "DEBUG")
		return 0;
	if (level == "INFO")
		return 1;
	if (level == "WARNING")
		return 2;
	if (level == "ERROR")
		return 3;
	return -1;
}

