/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:56:00 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 15:02:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("wrongCat") {
	std::cout << "Default constructor of WrongCat was call" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src._type) {
	std::cout << "Copy constructor of WrongCat was call" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}
WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat was call" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Miaou miaou" << std::endl;
}
