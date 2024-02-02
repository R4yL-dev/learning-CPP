/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:56:00 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 13:19:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("wrongCat") {
	std::cout << "Default constructor of WrongCat was call" << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat was call" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Miaou miaou" << std::endl;
}
