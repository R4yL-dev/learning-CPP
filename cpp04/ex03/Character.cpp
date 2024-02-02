/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:09:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/02 22:38:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("undefined") {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}
Character::Character(Character const &src) : _name(src._name) {
	for (int i = 0; i < 4; i++) {
		if (src._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = src._inventory[i]->clone();
	}
}
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			this->_inventory[i] = NULL;
	}
}
Character &Character::operator=(Character const &rhs) {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->_name;
}
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}
}
void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx])
			this->_inventory[idx]->use(target);
	}
}
