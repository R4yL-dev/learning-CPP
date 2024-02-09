/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:43:20 by lray              #+#    #+#             */
/*   Updated: 2024/02/09 12:45:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
	_name("undefined"),
	_hitPoint(10), _energyPoint(10),
	_attackDamage(0)
{
	std::cout << "A default ClapTrap was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ClapTrap::ClapTrap(std::string const &name) :
	_name(name),
	_hitPoint(10),
	_energyPoint(10),
	_attackDamage(0)
{
	std::cout << "A ClapTrap named " << this->_name << " was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ClapTrap::ClapTrap(std::string const &name, unsigned int const hitPoint, unsigned int const energyPoint, unsigned int const attackDamage) :
	_name(name),
	_hitPoint(hitPoint),
	_energyPoint(energyPoint),
	_attackDamage(attackDamage)
{
	std::cout << "A full ClapTrap named " << this->_name << " was built. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &src) :
	_name(src._name),
	_hitPoint(src._hitPoint),
	_energyPoint(src._energyPoint),
	_attackDamage(src._attackDamage)
{
	std::cout << "A ClapTrap named " << this->_name << " was built from an other ClapTrap. ";
	std::cout << "name: " << this->_name << " | hit point: " << _hitPoint;
	std::cout << " | energy point: " << _energyPoint << " | attack damage: " << _attackDamage << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Copie " << rhs._name<< " into " << this->_name << std::endl;

	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}
ClapTrap::~ClapTrap() {
	std::cout << "A ClapTrap named " << this->_name << " was destroy" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	if (this->_energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " tried to attack " << target;
		std::cout << " but has no energy point" << std::endl;
		return;
	}
	else if(this->_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " tried to attack " << target;
		std::cout << " but he is dead" << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage! ";
	std::cout << "energy point: " << _energyPoint << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " cannot take more damage, he is dead" << std::endl;
		return;
	}
	if (amount >= this->_hitPoint) {
		this->_hitPoint = 0;
	} else {
		this->_hitPoint -= amount;
	}
	std::cout << "ClapTrap " << _name << " has taken " << amount << " damage. ";
	std::cout << "hit point: " << _hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amout) {
	if (this->_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repaire itself because he is dead" << std::endl;
		return;
	}
	if (this->_energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repaire itself because he has no energy point" << std::endl;
		return;
	}
	_energyPoint--;
	_hitPoint += amout;
	std::cout << "ClapTrap " << _name << " repaire itself of " << amout << " hit point. ";
	std::cout << "hit point: " << _hitPoint << std::endl;
}
