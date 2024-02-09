/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:18:29 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:45:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("undefined", 100, 50, 20) {
	std::cout << "A default ScavTrap was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "A ScavTrap named " << this->_name << " was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ScavTrap::ScavTrap(std::string const &name, unsigned int const hitPoint, unsigned int const energyPoint, unsigned int const attackDamage) :
	ClapTrap(name, hitPoint, energyPoint, attackDamage) {

}
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "A ScavTrap named " << this->_name << " was built from an other ScavTrap. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "Copie " << rhs._name<< " into " << this->_name << std::endl;

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}
ScavTrap::~ScavTrap() {
	std::cout << "A ScavTrap named " << this->_name << " was destroy" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (this->_energyPoint <= 0) {
		std::cout << "ScavTrap " << _name << " tried to attack " << target;
		std::cout << " but has no energy point" << std::endl;
		return;
	}
	else if(this->_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name << " tried to attack " << target;
		std::cout << " but he is dead" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage! ";
	std::cout << "energy point: " << _energyPoint << std::endl;
}

void ScavTrap::guardGate() const {
	if (this->_hitPoint > 0)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot change mode, he is dead" << std::endl;

}
