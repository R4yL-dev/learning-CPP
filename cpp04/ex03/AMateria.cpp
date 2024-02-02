/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:54 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 18:29:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}
AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria(AMateria const &src) : _type(src._type) {}
AMateria::~AMateria() {}
AMateria &AMateria::operator=(AMateria const &rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* Using unknown materia on " << target.getName() << " *" << std::endl;
}


