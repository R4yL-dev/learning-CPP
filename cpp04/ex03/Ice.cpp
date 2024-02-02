/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:39:22 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:08:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const &src) : AMateria("ice") {}
Ice::~Ice() {};
Ice &Ice::operator=(Ice const &src) {
	return *this;
}

Ice* Ice::clone() const {
	return new Ice();
}
void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
