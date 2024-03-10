/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:27:23 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:48:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("undefined", 100, 100, 30) {
	std::cout << "A default FragTrap was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "A FragTrap named " << this->_name << " was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
FragTrap::FragTrap(std::string const &name, unsigned int const hitPoint, unsigned int const energyPoint, unsigned int const attackDamage) :
	ClapTrap(name, hitPoint, energyPoint, attackDamage) {

}
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "A FragTrap named " << this->_name << " was built from an other FragTrap. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Copie " << rhs._name<< " into " << this->_name << std::endl;

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}
FragTrap::~FragTrap() {
	std::cout << "A FragTrap named " << this->_name << " was destroy" << std::endl;
}

void FragTrap::attack(std::string const &target) {
	if (this->_energyPoint <= 0) {
		std::cout << "FragTrap " << _name << " tried to attack " << target;
		std::cout << " but has no energy point" << std::endl;
		return;
	}
	else if(this->_hitPoint <= 0) {
		std::cout << "FragTrap " << _name << " tried to attack " << target;
		std::cout << " but he is dead" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "FragTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage! ";
	std::cout << "energy point: " << _energyPoint << std::endl;
}

void FragTrap::highFivesGuys() const {
	if (this->_hitPoint > 0)
		std::cout << "FragTrap " << _name << " gives away HighFive to everyone!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " cannot gives away HighFive to everyone, he is dead" << std::endl;
}
