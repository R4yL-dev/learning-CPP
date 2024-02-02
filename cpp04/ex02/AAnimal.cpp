/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:12:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 17:03:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default") {
	std::cout << "Default constructor of AAnimal was call" << std::endl;
}
AAnimal::AAnimal(std::string const &type) : _type(type) {
	std::cout << "Parameterized constructor of AAnimal was call" << std::endl;
}
AAnimal::AAnimal(AAnimal const &src) : _type(src._type) {
	std::cout << "Copy constructor of AAnimal was call" << std::endl;
}
AAnimal::~AAnimal() {
	std::cout << "Destructor of AAnimal was call" << std::endl;
}
AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "Copy operator of AAnimal was call" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

const std::string &AAnimal::getType() const {
	return _type;
}
