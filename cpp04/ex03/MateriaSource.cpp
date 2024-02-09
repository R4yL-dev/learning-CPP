/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:51:29 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 11:08:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_storage[i] = NULL;
	}
}
MateriaSource::MateriaSource(MateriaSource const &src) {
	for (int i = 0; i < 4; i++) {
		if (src._storage[i] == NULL)
			this->_storage[i] = NULL;
		else
			this->_storage[i] = src._storage[i]->clone();
	}
}
MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_storage[i])
			delete this->_storage[i];
	}
}
MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_storage[i])
			delete this->_storage[i];
		if (rhs._storage[i] == NULL)
			this->_storage[i] = NULL;
		else
			this->_storage[i] = rhs._storage[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (this->_storage[i] == NULL)
		{
			this->_storage[i] = materia->clone();
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_storage[i]->getType() == type)
			return this->_storage[i]->clone();
	}
	return 0;
}
