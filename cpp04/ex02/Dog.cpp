/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:39:18 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 17:00:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Default constructor of Dog was call" << std::endl;
	_brain = new Brain();
}
Dog::Dog(Dog const &src) : AAnimal(src._type) {
	std::cout << "Copy constructor of Dog was call" << std::endl;
	delete _brain;
	_brain = new Brain(*(src._brain));
}
Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Copy operator of Dog was call" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete _brain;
		_brain = new Brain(*(rhs._brain));
	}
	return *this;
}
Dog::~Dog() {
	std::cout << "Destructor of Dog was call" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Waff waff" << std::endl;
}
