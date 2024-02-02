/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:39:18 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 13:19:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("wrongDog") {
	std::cout << "Default constructor of WrongDog was call" << std::endl;
}
WrongDog::~WrongDog() {
	std::cout << "Destructor of WrongDog was call" << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << "Wrong Waff waff" << std::endl;
}
