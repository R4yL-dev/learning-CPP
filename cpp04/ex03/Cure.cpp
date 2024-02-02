/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:06 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 21:18:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const &src) : AMateria("cure") {}
Cure::~Cure() {}
Cure &Cure::operator=(Cure const &rhs) {
	return *this;
}

Cure *Cure::clone() const {
	return new Cure;
}
void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
