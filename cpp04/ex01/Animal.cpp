/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:12:53 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 13:20:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default") {
	std::cout << "Default constructor of Animal was call" << std::endl;
}
Animal::Animal(std::string const &type) : _type(type) {
	std::cout << "Parameterized constructor of Animal was call" << std::endl;
}
Animal::Animal(Animal const &src) : _type(src._type) {
	std::cout << "Copy constructor of Animal was call" << std::endl;
}
Animal::~Animal() {
	std::cout << "Destructor of Animal was call" << std::endl;
}
Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "Copy operator of Animal was call" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

const std::string &Animal::getType() const {
	return _type;
}

void Animal::makeSound() const{
	std::cout << "A generic animal sound..." << std::endl;
}
