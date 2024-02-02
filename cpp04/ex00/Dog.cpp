/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:39:18 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 12:44:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default constructor of Dog was call" << std::endl;
}
Dog::~Dog() {
	std::cout << "Destructor of Dog was call" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Waff waff" << std::endl;
}
