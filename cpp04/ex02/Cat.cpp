/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:56:00 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 17:00:08 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat") {
	std::cout << "Default constructor of Cat was call" << std::endl;
	this->_brain = new Brain();
}
Cat::Cat(Cat const &src) : AAnimal(src._type) {
	std::cout << "Copy constructor of Cat was call" << std::endl;
	delete _brain;
	this->_brain = new Brain(*(src._brain));
}
Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Copy operator of Cat was call" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete _brain;
		_brain = new Brain(*(rhs._brain));
	}
	return *this;
}
Cat::~Cat() {
	std::cout << "Destructor of Cat was call" << std::endl;
	delete(_brain);
}

void Cat::makeSound() const {
	std::cout << "Miaou miaou" << std::endl;
}
