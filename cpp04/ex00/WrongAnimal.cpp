/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:12:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 13:18:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("wrongDefault") {
	std::cout << "Default constructor of WrongAnimal was call" << std::endl;
}
WrongAnimal::WrongAnimal(std::string const &type) : _type(type) {
	std::cout << "Parameterized constructor of WrongAnimal was call" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src) : _type(src._type) {
	std::cout << "Copy constructor of WrongAnimal was call" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor of WrongAnimal was call" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "Copy operator of WrongAnimal was call" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

const std::string &WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const{
	std::cout << "A generic WrongAnimal sound..." << std::endl;
}
